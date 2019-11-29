# ngrok-qr
A wrapper for [ngrok](https://ngrok.com/) that automatically generates QR codes for tunnel URLs.

![Demo Picture](./demo.png?raw=true "Demo of ngrok-qr")

### Usage
Use the command `ngrok-qr` like you would normally use with ngrok, all the command line arguments will be passed to ngrok:

```
ngrok-qr http 8080
```

A new terminal window will open that will output a scannable QR code to the tunnel URL.

### Installation
`cd` into the root project directory and run `make` to compile the `ngrok-qr-generator` executable. You can then run `make install` to copy the executables into `/usr/local/bin` or you can set a `PATH` environment variable if you wish.

### Dependencies
* [ngrok 2.x](https://ngrok.com/download) - ngrok versions 2.x only
* [curl and libcurl](https://curl.haxx.se/docs/install.html) - for http requests
* [rapidjson](https://github.com/Tencent/rapidjson) - for parsing json
* [QR-code-generator](https://github.com/nayuki/QR-Code-generator) - for encoding text

### Support
ngrok-qr supports macOS or any other Unix-based machine using gnome-terminal for terminal emulation. If your Unix-based OS uses another terminal emulator you can edit the `ngrok-qr` bash script in the root project directory to support it. Extended support coming soon
