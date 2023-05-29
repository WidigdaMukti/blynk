/*
  Blynk example
  You should get Auth Token in the Blynk App.
  You need to write the right wifiCredentials.
*/

/* Comment this out to disable prints and save space */
#define BLYNK_TEMPLATE_ID "TMPL-1AKgMYs"
#define BLYNK_DEVICE_NAME "Control LED"
#define BLYNK_AUTH_TOKEN "jVAHUZvg61g-vIWdGjJ6e8DnDhf_k13B"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "CROCODICK"; //nama hotspot yang digunakan
char pass[] = "isoisone"; //password hotspot yang digunakan

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == 1)
  {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  // process received value
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
