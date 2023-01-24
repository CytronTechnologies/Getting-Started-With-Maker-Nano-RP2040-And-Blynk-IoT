/*
  Connect RP2040 + ESP8266 board to the new Blynk (https://blynk.io)
  
  Items:
  - Maker Nano RP2040
    https://my.cytron.io/maker-nano-rp2040-simplifying-projects-with-raspberry-pi-rp2040
  - Grove WiFi 8266
    https://my.cytron.io/p-grove-wifi-8266-iot-for-microbit-and-beyond
  
  Connections
  - Grove WiFi to Maker port [0, 1]
  
  External libraries:
  - Blynk by Volodymyr Shymanskyy 1.1.0 (Library Manager)
  - BlynkESP8266 (https://github.com/vshymanskyy/BlynkESP8266)
*/

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPLMtlKKbol"

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "xxxxxx";
char ssid[] = "xxxxxx";
char pass[] = "xxxxxx";

#define EspSerial Serial1
#define ESP8266_BAUD 115200
#define POTENTIMETER A3
BlynkTimer timer;

ESP8266 wifi(&EspSerial);

  
 

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  int potentiometer_adc = analogRead(POTENTIMETER);
  Serial.println("Potentiometer: " + String(potentiometer_adc));
  Blynk.virtualWrite(V1, potentiometer_adc);
}

void setup()
{
  pinMode(POTENTIMETER, INPUT);
  Serial.begin(115200);
  delay(10);

  EspSerial.begin(ESP8266_BAUD);
  EspSerial.println("AT+RST");
  delay(5000);

  Blynk.begin(auth, wifi, ssid, pass);
   // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);

}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
