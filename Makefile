CXXFLAGS = -std=c++17 -Iincludes -Ilibs/qr-code-generator
QRCODEGEN_CXXFLAGS = -std=c++11 -O



default:
	for f in libs/qr-code-generator/*.cpp; do $(CXX) -flto $(QRCODEGEN_CXXFLAGS) libs/qr-code-generator/$$(basename "$$f") -o bin/objects/qrcodegen/$$(basename "$$f" ".cpp")".o" -c; done
	ar rcs bin/static/libqrcodegen.a bin/objects/qrcodegen/BitBuffer.o bin/objects/qrcodegen/QrCode.o bin/objects/qrcodegen/QrCodeGeneratorDemo.o bin/objects/qrcodegen/QrCodeGeneratorWorker.o bin/objects/qrcodegen/QrSegment.o
	for f in src/*.cpp; do $(CXX) -flto $(CXXFLAGS) src/$$(basename "$$f") -o bin/objects/$$(basename "$$f" ".cpp")".o" -c; done
	$(CXX) $(CXXFLAGS) bin/objects/*.o bin/static/libqrcodegen.a -o ngrok-qr-generator -lcurl


OSX_MV = exit

ifeq ($(UNAME_S),Darwin)
	OSX_MV = chmod u+x ./ngrok-qr-generator-osascript; cp ./ngrok-qr-generator-osascript /usr/local/bin/ngrok-qr-generator-osascript
endif

install:
	chmod u+x ./ngrok-qr
	chmod u+x ./ngrok-qr-generator
	cp ./ngrok-qr /usr/local/bin/ngrok-qr
	cp ./ngrok-qr-generator /usr/local/bin/ngrok-qr-generator
	$(OSX_MV)
	
