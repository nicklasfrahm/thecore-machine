// include required libraries
#include "DigitalLed.h"
#include <Arduino.h>
#include <ESP8266WiFiMulti.h>
#include <SocketIoClient.h>

// include environment variables
#include "env.h"

// general constants
const uint32_t BAUD_RATE = 115200;
const uint8_t LED_ONCHIP = 2;

// specific constants
const uint8_t LED_STATUS = LED_ONCHIP;

// instantiate necessary classes
ESP8266WiFiMulti wifi;
SocketIoClient sio;
DigitalLed statusLed(LED_ONCHIP, LOW, LED_CONFIG_SINK);

// toggle event handler
void toggle(const char *payload, size_t length)
{
  Serial.println("[SIO] Event: toggle");
  Serial.print("[SIO] Payload: ");
  Serial.println(payload);
  statusLed.toggle();
}

void setup(void)
{
  // start serial communication
  Serial.begin(BAUD_RATE);
  Serial.println();
  Serial.println("[INF] Starting device ...");

  // add wifi network
  wifi.addAP(WIFI_SSID, WIFI_PASS);
  Serial.println("[NET] Connecting to WiFi network ...");
  Serial.print("[NET] SSID: ");
  Serial.println(WIFI_SSID);
  Serial.print("[NET] PASS: ");
  Serial.println(WIFI_PASS);

  // wait for wifi connection
  while (wifi.run() != WL_CONNECTED)
  {
    Serial.println("[NET] Waiting for connection retry ...");
    statusLed.low();
    delay(450);
    statusLed.high();
    delay(50);
  }

  // display IP
  Serial.print("[NET] IP address: ");
  Serial.println(WiFi.localIP());

  // configure websockets
  Serial.println("[SIO] Configuring event listeners ...");
  sio.on("toggle", toggle);
  sio.begin("192.168.2.24", 3000, "/sio");

  // enable LED
  Serial.println("[LED] Indicating successful setup ...");
  statusLed.high();
}

void loop(void) { sio.loop(); }