#include <string>
#include <iostream>
#include <curl/curl.h>
#include "GetTunnel.h"
#include "DrawQR.h"
#include "qr-code-generator/QrCode.hpp"


using namespace std;
using namespace qrcodegen;
using namespace ngrokqr;

int main(int argc, char *argv[]) {

    
    if(argc < 3) return 0;


    if(strcmp(argv[1], "http") == 0) {

        string http_url;
        string https_url;
        try {
            http_url = get_tunnel_url("http://localhost:4040/api/tunnels");
            https_url = string(http_url).insert(4, "s");

        }
        catch(GetTunnelException e) {
            cout << e.what() << endl;
            return 0;
        }

        QrCode http = QrCode::encodeText(http_url.c_str(), QrCode::Ecc::MEDIUM);
        QrCode https = QrCode::encodeText(https_url.c_str(), QrCode::Ecc::MEDIUM); 

        ngrokqr::QRDrawer drawer(&https, https_url.c_str());
        drawer.draw_qr_code();
        drawer.set_qr_code(&http, http_url.c_str());
        drawer.draw_qr_code();
        
    }
    


    return 0;
}
