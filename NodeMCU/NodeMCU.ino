#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define WIFI_SSID   "MiWiFi"
#define WIFI_PASS   "p:159357"
#define LISTEN_PORT 4210
#define MAX_LEN     20

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

WiFiUDP Udp;
unsigned int localUdpPort = LISTEN_PORT;
char incomingPacket[MAX_LEN];
char  replyPacket[] = "Hi there! Got the message :-)";

void init_wifi(){
  IPAddress staticIP(192, 168, 1, 50);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(staticIP, subnet, gateway);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Udp.begin(localUdpPort);
}

void setup()
{
  init_wifi();
  Serial.begin(9600);
}


void loop()
{
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    int len = Udp.read(incomingPacket, MAX_LEN);
    Serial.write(incomingPacket,len);
    //Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    //Udp.write(replyPacket);
    //Udp.endPacket();
  }
}
