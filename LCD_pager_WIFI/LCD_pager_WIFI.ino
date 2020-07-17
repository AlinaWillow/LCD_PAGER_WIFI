#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#include <LiquidCrystal_I2C.h>  // Library for LCD
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcdr(0x27, 20, 4);

WidgetLCD lcd(V2);
String text_In;
int x=0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "rKXwEET4u2AmpCqTwkHKSL08i_ZGU-jt";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PTNP";
char pass[] = "Wiboonbajaree1969";


BLYNK_WRITE(V0) {
  text_In = param.asStr();  // Text Input Widget - Strings

  lcd.print(0,0,text_In); 
  lcdr.print(text_In);
  lcdr.blink();
}

BLYNK_WRITE(V1) {

  if(param.asInt()==1){
    if(x<4){
    x++;
    lcdr.setCursor(0,x);
    lcdr.blink();
    lcd.clear();
    }
    else{x=0;}
  }
 
  
}

BLYNK_WRITE(V3) {
   
  if(param.asInt()==1){
  lcd.clear();
  lcdr.clear();
  }
}

BLYNK_WRITE(V4) {
   
  if(param.asInt()==0){
   lcdr.display(); 
  lcdr.backlight(); 
  }
  if(param.asInt()==1){
   lcdr.noDisplay(); 
  lcdr.noBacklight(); 
  }
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  
  lcdr.begin();
  lcdr.blink();
  /*
  lcdr.setCursor(6,2);
  lcdr.print("WELCOME!");
  delay(1000);
  for(int x=0;x<10;x++){
  lcdr.scrollDisplayLeft();
    delay(400);
    x++;
  }
  lcdr.clear();
  */
  
}

void loop()
{
  Blynk.run();
}
