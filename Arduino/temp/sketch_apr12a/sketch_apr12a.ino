#include "DHT.h"
#define DHTPIN 7           // digital pin we're connected to
#define DHTTYPE DHT11     // DHT 22  (AM2302) blue one
//#define DHTTYPE DHT21   // DHT 21 (AM2301) white one
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);
unsigned long temperature_time;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);          //  setup serial
dht.begin();
temperature_time = millis();

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long time_passed = 0;

  time_passed = millis() - temperature_time;
  if (time_passed < 0)
  {
  temperature_time = millis();
  }
  
  if (time_passed > 5000)
  {
    float h = dht.readHumidity();
    // Read temperature as Celsius
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit
    float f = dht.readTemperature(true);
    
    // Check if any reads failed and exit early (to try again).
 //   if (isnan(h) || isnan(t) || isnan(f)) {
   //   Serial.println("Failed to read from DHT sensor!");
     // return;
     t=33; 
    
    Serial.print("Humidity=");
    Serial.print(h);
    Serial.print("   Temp=");
    Serial.println(tM);
    temperature_time = millis();
  
  }}
