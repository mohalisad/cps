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


void setup()
{
  IPAddress staticIP(192, 168, 1, 50);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(staticIP, subnet, gateway);
  Serial.begin(115200);
  Serial.println();
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, MAX_LEN);
    Serial.printf("UDP packet contents: %x %x\n", incomingPacket[0],incomingPacket[1]);
    //Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    //Udp.write(replyPacket);
    //Udp.endPacket();
  }
}
