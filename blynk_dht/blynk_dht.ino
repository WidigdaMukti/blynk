#define BLYNK_TEMPLATE_ID "TMPL0wOsvb6b"
#define BLYNK_DEVICE_NAME "ESP32 DHT22"
#define BLYNK_AUTH_TOKEN "rSJI5p1_FShpUW94XbZz3GNZmVY3Kwq_"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "CROCODICK"; //nama hotspot yang digunakan
char pass[] = "isoisone"; //password hotspot yang digunakan

#define DHTPIN 15          // Mention the digital pin where you connected 
#define DHTTYPE DHT11     // DHT 11  
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;



void setup(){
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  
  dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V0, t);
  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.print("    Humidity : ");
  Serial.println(h);


  if(t > 30){
   // Blynk.email("isamahfudi08@gmail.com", "Alert", "Temperature over 28C!");
    Blynk.logEvent("temp_alert","Temp above 30 degrees");
  }
}
