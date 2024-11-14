#define BLYNK_TEMPLATE_ID "TMPL6VeYXVAbf"
#define BLYNK_TEMPLATE_NAME "LPG Gas Sensor"
#define BLYNK_AUTH_TOKEN "c15jCpIoOHeyeBH4dEO_F5P4oUzfjEOi"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN; // Blynk authentication token
char ssid[] = "lpg";        // WiFi network name
char pass[] = "12345678"; // WiFi password

BlynkTimer timer;

void setup() {
  Serial.begin(9600); // Start Serial communication with Arduino
  Blynk.begin(auth, ssid, pass); // Connect to WiFi and Blynk

  timer.setInterval(1000L, sendGasData); // Check for data every second
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendGasData() {
  if (Serial.available() > 0) {            // Check if data is available from Arduino
    int gasValue = Serial.parseInt();      // Read the integer sent by Arduino
    Blynk.virtualWrite(V1, gasValue);      // Send gas value to Blynk on Virtual Pin V1
  }
}