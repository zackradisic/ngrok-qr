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

    cout << "Running ngrok-qr" << endl;



    if(strcmp(argv[1], "http") == 0) {

        string url;
        try {
            url = get_tunnel_url("http://localhost:4040/api/tunnels", false);
        }
        catch(GetTunnelException e) {
            cout << e.what() << endl;
            return 0;
        }

        QrCode qr0 = QrCode::encodeText(url.c_str(), QrCode::Ecc::MEDIUM);
        
        ngrokqr::QRDrawer drawer(&qr0);

        drawer.draw_qr_code();
        
    }
    


    return 0;
}
