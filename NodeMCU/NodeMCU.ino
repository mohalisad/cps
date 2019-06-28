#define WIFI_SSID   "myhot"
#define WIFI_PASS   "p:159357"
#define LISTEN_PORT 4210

#include "wifi.h"

#define INCOMING_PACKET_LEN 20
#define ACK_PACKET_LEN      2


byte incomingPacket[INCOMING_PACKET_LEN];
byte ackPack[ACK_PACKET_LEN];
int packetSize;

void make_ack(){
  short seqNumber;
  seqNumber  = (((short)incomingPacket[2]&0x1F)<<4) + ((short)incomingPacket[3]>>4);
  ackPack[0] = seqNumber/2;
  ackPack[1] = (seqNumber%2)<<7;
}

void setup()
{
  init_wifi();
  Serial.begin(9600);
}


void loop()
{
  packetSize = Udp.parsePacket();
  if (packetSize)
  {
    int len = Udp.read(incomingPacket, INCOMING_PACKET_LEN);
    packetSize = Udp.parsePacket();
    if (packetSize == 0){
      Serial.write(incomingPacket,len);
      make_ack();
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(ackPack,ACK_PACKET_LEN);
      Udp.endPacket();
    }
  }
}
