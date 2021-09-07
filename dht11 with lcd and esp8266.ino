#include <Wire.h>
#include <ESP8266WiFi.h>

#include <LiquidCrystal_I2C.h>
#include <DHT.h>  
 
String apiKey = "H38TEGNC0XKW43BB";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "how2electronics";     // replace with your wifi ssid and wpa2 key
const char *pass =  "alhabibi";
const char* server = "api.thingspeak.com";
 
#define DHTPIN 4          //pin where the dht11 is connected

DHT dht(DHTPIN, DHT11);
WiFiClient client;
LiquidCrystal_I2C lcd(0x3F, 16, 2);
void setup(){
  Wire.begin(2,0);
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 
 // Start Printing
  
       Serial.begin(115200);
       delay(10);
       dht.begin();
 
       WiFi.begin(ssid, pass);
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
     }
}
 
void loop() 
  
{
      int h = dht.readHumidity();
      int t = dht.readTemperature();
      
              if (isnan(h) || isnan(t)) 
                 {
                      lcd.print(" error ");
                 }
                 else{
                  lcd.print("temp is: "+t);
//                  lcd.print("hum is :" +h);
                  return;
                 }
}
