#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.clearWriteError();
  Serial.println("Initializing wifi on nodemcu.....");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println("Setup Done ✔️");
}

void loop() {
  Serial.println("\nScanning wifi networks...");
  int n = WiFi.scanNetworks();
  Serial.println("Scan ccompleted");
  if (n == 0) {
    Serial.println("No network found ❌");
  } else {
    Serial.println(String(n)+ " Networks Founds");
    for (int i = 1; i <= n; i++) {
      String flag = (WiFi.encryptionType(i-1) == ENC_TYPE_NONE) ? "🟢":"🔒";
      Serial.println(String(i)+" ->  "+WiFi.SSID(i-1)+" "+flag+" "+"("+WiFi.RSSI(i-1)+"dBm)");
      delay(100);
    }
  }
  delay(5000);
}
