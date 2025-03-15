#include <WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected");
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    if (client.available()) {
      String data = client.readString();
      Serial.println("Received: " + data);
    }
  }
}
