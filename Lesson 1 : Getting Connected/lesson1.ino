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
#define BLYNK_TEMPLATE_ID   "YourTemplateID"

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define EspSerial Serial1
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void setup()
{
  Serial.begin(115200);
  delay(10);

  EspSerial.begin(ESP8266_BAUD);
  EspSerial.println("AT+RST");
  delay(5000);

  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  Blynk.run();
}
