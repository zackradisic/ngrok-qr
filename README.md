# ngrok-qr
A wrapper for [ngrok](https://ngrok.com/) that automatically generates QR codes for tunnel URLs.


### Usage
Use ngrok-qr like you would normally use ngrok, all the command line arguments will be passed to ngrok:

```
ngrok-qr http 8080
```

A new terminal window will open that will output a scannable QR code to the tunnel URL.

### Installation
cd into the root project directory and run `make` to compile the `ngrok-qr-generator` executable. You can then set a `PATH` environment variable pointing to the `ngrok-qr` executable, or you can drag and drop the executables in the root project directory to `usr/local/bin`.

### Dependencies
* [ngrok 2.x](https://ngrok.com/download) - ngrok versions 2.x only
* [curl and libcurl](https://curl.haxx.se/docs/install.html) - for http requests
* [rapidjson](https://github.com/Tencent/rapidjson) - for parsing json
* [QR-code-generator](https://github.com/nayuki/QR-Code-generator) - for encoding text

### Support
ngrok-qr supports macOS and any other Unix-based machine using gnome-terminal for terminal emulation. Extended support coming soon

### Notes
* I haven't implemented any command line parsing so features like configuration files, changing the forwarded host, or multiple tunnels are not support yet.
