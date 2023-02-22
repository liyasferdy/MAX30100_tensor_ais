#include <Arduino.h>
#include <WiFiMulti.h>
#include "MAX30100.h"
#include <Wire.h>

#define WIFI_SSID "wifi_network_name"
#define WIFI_PASSWORD "wifi_password"

#define REPORTING_PERIOD_MS     1000

// WiFiMulti wifiMulti;

// void setup() {
//   Serial.begin(921600);
//   pinMode(LED_BUILTIN, OUTPUT);

//   wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

//   while (wifiMulti.run() != WL_CONNECTED) {
//     delay(100);
//   }

//   Serial.println("Connected");
// }

// void loop() {
//   digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED);
// }


//TEST Code from library
MAX30100 sensor;
uint32_t tsLastReport = 0;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while(!Serial);
  sensor.begin(pw1600, i50, sr100 );
}

void loop() {
  sensor.readSensor();
  delay(10);

  //Test Code from antoher Source
  //Grab the updated IR
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    //Serial.println((sensor.IR));
    Serial.print("IR: ");
    Serial.print(sensor.IR);
    Serial.print("RED: ");
    Serial.print(sensor.RED);
    // Serial.print("bpm / SpO2:");
    // Serial.print(pox.getSpO2());
    // Serial.println("%");  

    tsLastReport = millis();
  }

}



// long meanDiff(int M) {
//   #define LM_SIZE 15
//   static int LM[LM_SIZE];      // LastMeasurements
//   static byte index = 0;
//   static long sum = 0;
//   static byte count = 0;
//   long avg = 0;

//   // keep sum updated to improve speed.
//   sum -= LM[index];
//   LM[index] = M;
//   sum += LM[index];
//   index++;
//   index = index % LM_SIZE;
//   if (count < LM_SIZE) count++;

//   avg = sum / count;
//   return avg - M;
// }