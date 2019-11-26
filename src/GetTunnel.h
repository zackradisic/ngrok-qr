#include <iostream>
#include <string>
#include <curl/curl.h>
#include <rapidjson/document.h>
#include <unistd.h>


using namespace std;


namespace ngrokqr {

    class GetTunnelException : public exception {

    public:
        GetTunnelException(const char* msg): msg{msg} {

        }
        const char* what() const throw() {
            string s = "Error retrieving tunnel info: ";
            s += msg;

            return s.c_str();
        }

    private:
        const char* msg;

    };

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    string parse_tunnel_json(string raw_json) {
        rapidjson::Document document;
        document.Parse(raw_json.c_str());

        if (!document.IsObject()) throw GetTunnelException("Invalid JSON response: top-level member is not a JSON object");
        if (!document.HasMember("tunnels")) throw GetTunnelException("Invalid JSON response: could not find tunnels property");
        if (!document["tunnels"].IsArray()) throw GetTunnelException("Invalid JSON response: tunnels property is not an array");
        auto tunnels = document["tunnels"].GetArray();
        auto &tunnel = tunnels[1];

        string url = tunnel["public_url"].GetString();

        return url;
    }


    string get_tunnel_url(string url, bool ssl) {
        CURL *curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if(curl) {
            
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);

            if(res == 7) {
                
                int count = 0;
                while(count < 10) {
                    cout << "Connection error trying again..." << endl;
                    res = curl_easy_perform(curl);
                    if(res == 0) break;
                    count++;
                    usleep(75 * 1000);
                }
            }

            if(res != 0) throw GetTunnelException(curl_easy_strerror(res));

            curl_easy_cleanup(curl);

            return parse_tunnel_json(readBuffer);
        }
        else {
            throw GetTunnelException("Error intializing curl");
        }
    }

};
