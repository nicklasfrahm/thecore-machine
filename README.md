# thecore machine

**thecore** is a facility of manufacturing ressources. **thecore-machine** is the firmware for a _NodeMCU v1.0_. It connects a manufacturing ressource (e.g 3D-print, CNC-router) to the cloud and enables easy and intuitive use of it.

## Installation

In order to install the software onto the device, the developer needs an IDE with a **Platform IO** plugin (e.g. VS Code, Atom).

To install the necessary platform and the libraries, run the following commands:

```shell
pio platform install espressif8266
pio lib install SocketIoClient
pio lib install WebSockets
```

Create the file `src/env.h` and put in the following:

```cpp
#define WIFI_SSID "wifi-network"
#define WIFI_PASS "wifi-password"
```

Then it can be compiled and uploaded to the device.

```shell
pio run --target upload
```
