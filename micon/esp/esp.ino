#include <WiFi.h>
#include <WiFiUdp.h>

const int Rx = 16;
const int Tx = 17;

const char * ssid = "wifi-name";
const char * pass = "wifi-pass";

const char * udpAddr = "ip-addr";
const int udpPort = 9999;

WiFiUDP udp;

void setup() {
   Serial.begin(4800);
   Serial2.begin(9600, SERIAL_8N1, Rx, Tx);

   WiFi.begin(ssid, pass);
   while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print("-");
   }

  Serial.println(WiFi.localIP());

}

void loop() {
  uint8_t send[101];
  String send_str = Serial2.readString();
  send_str.toCharArray((char *)send, 100);
  uint8_t received[100] = "";

  udp.beginPacket(udpAddr, udpPort);
  udp.write(send, 100);
  udp.endPacket();

  udp.parsePacket();
  if(udp.read(received, 100) > 0){
    Serial.print((char *) received);
  }
  delay(500);
}
