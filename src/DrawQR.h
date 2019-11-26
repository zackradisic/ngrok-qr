#include <string>
#include <iostream>
#include "qr-code-generator/QrCode.hpp"

using namespace std;
using namespace qrcodegen;

namespace ngrokqr {

    class QRDrawer {

        #define WHITE_BLOCK "\033[0;37;47m  "
        #define BLACK_BLOCK "\033[0;37;40m  "
        #define NEW_LINE "\033[0;37;40m  "
        #define RESET_LINE "\033[0m\033[0m"
        
        public:
            QRDrawer(QrCode* qr_code): qr_code{qr_code} {
            }

            void draw_qr_code() {

                for(int i = 0; i < qr_code->getSize() + 2; i++) {
                    cout << WHITE_BLOCK;
                }
                cout << endl;

                for (int y = 0; y < qr_code->getSize(); y++) {
                    cout << WHITE_BLOCK;
                    for (int x = 0; x < qr_code->getSize(); x++) {
                        cout << (qr_code->getModule(x, y) ? BLACK_BLOCK : WHITE_BLOCK);
                    }
                    cout << WHITE_BLOCK << RESET_LINE << endl;
                }
                
                for(int i = 0; i < qr_code->getSize() + 2; i++) {
                    cout << WHITE_BLOCK;
                }
                cout << endl;

            }

        private:
            const QrCode* qr_code;

            inline void print_vertical_padding() {
                for(int i = 0; i < qr_code->getSize() + 2; i++) {
                    cout << WHITE_BLOCK;
                }
            }

    };
    
};