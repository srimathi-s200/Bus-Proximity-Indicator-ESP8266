
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "BusStop_AP";
const char* password = "Bus12345";

WiFiUDP udp;
IPAddress receiverIP(192, 168, 4, 1);
const int receiverPort = 4210;

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println();
  Serial.println("BUS TRANSMITTER STARTING");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to bus stop Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi connected!");
  Serial.print("Bus IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    int rssi = WiFi.RSSI();

    udp.beginPacket(receiverIP, receiverPort);
    udp.print(rssi);
    udp.endPacket();

    Serial.print("Signal strength: ");
    Serial.print(rssi);
    Serial.println(" dBm");
  } else {
    Serial.println("Wi-Fi disconnected");
  }

  delay(1000);
}