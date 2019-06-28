#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

WiFiUDP Udp;
unsigned int localUdpPort = LISTEN_PORT;

void init_wifi(){
  IPAddress staticIP(192, 168, 43, 22);
  IPAddress gateway(192, 168, 43, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(staticIP, subnet, gateway);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Udp.begin(localUdpPort);
}
