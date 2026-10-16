
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;

const int ledPin = D5;
const int udpPort = 4210;

// LED turns ON at -60 dBm or stronger
const int nearThreshold = -60;


void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.mode(WIFI_AP);
  WiFi.softAP("BusStop_AP", "Bus12345");

  udp.begin(udpPort);

  Serial.println("BUS STOP RECEIVER READY");
  Serial.println("Waiting for bus signal...");
}

void loop() {
  int packetSize = udp.parsePacket();

  if (packetSize > 0) {
    char buffer[32];

    int len = udp.read(buffer, sizeof(buffer) - 1);

    if (len > 0) {
      buffer[len] = '\0';

      int rssi = atoi(buffer);

      Serial.print("Received RSSI: ");
      Serial.print(rssi);
      Serial.println(" dBm");

      if (rssi >= nearThreshold) {
        digitalWrite(ledPin, HIGH);
        Serial.println("BUS NEAR - LED ON");
      } else {
        digitalWrite(ledPin, LOW);
        Serial.println("BUS FAR - LED OFF");
      }
    }
  }
}
