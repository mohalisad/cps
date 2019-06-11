#include "wifi.h"

#define WIFI_SSID   "MiWiFi"
#define WIFI_PASS   "p:159357"
#define LISTEN_PORT 4210
#define MAX_LEN     20

char incomingPacket[MAX_LEN];

byte[2] make_ack(byte[4] incomingPacket){
  short seqNumber;
  seqNumber = (incomingPacket[2]&0x1F)*16 + (incomingPacket[3]>>4);
  return seqNumber;
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
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(make_ack(incomingPacket));
    Udp.endPacket();
  }
}
