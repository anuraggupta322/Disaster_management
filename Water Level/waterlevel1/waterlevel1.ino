#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

byte sensorPin[] = {16,5, 4};
//byte ledPin[] = {11, 12, 13}; // number of leds = numbers of sensors
const byte sensors = 3;
int level = 0;
 
const char* ssid = "Too slow";
const char* password = "asdfghjkl"; 

void setup()
{ 
Serial.begin(9600);
  for(int i = 0; i < sensors; i++)
{
pinMode(sensorPin[i], INPUT);
//pinMode(ledPin[i], OUTPUT);
}
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.println("Connecting..");
 
  }

}
void loop() {
  
level = 0;
for(int i = 0; i < sensors; i++)
{
if(digitalRead(sensorPin[i]) == HIGH)
{
//digitalWrite(ledPin[i], HIGH);
level = sensors - i;

}

}
Serial.println("Water level");
switch(level)
{
case 1:
Serial.println("HIGH");
break;
case 2:
Serial.println("AVERAGE");
break;
case 3:
Serial.println("LOW");
break;
default:
Serial.println("NO WATER");
break;
}
delay(100);


   

  
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
HTTPClient http;  //Declare an object of class HTTPClient
 
http.begin("http://3.17.13.174:8080/WaterLevel/ultra.jsp?id=1&distance="+String(level));
Serial.print(level);//Specify request destination
int httpCode = http.GET();                                                                  //Send the request
 
if (httpCode > 0) { //Check the returning code
}
    http.end();   //Close connection
  delay(500);
    }
}


 
