//Arduino code
#include <SoftwareSerial.h>
SoftwareSerial s(5,6);

int level0=A0;
int level1=A1;
int level2=A2;
int level3=A3;
int level4=A4;

int a,b,c,d,e;
int z=1000;

void setup() {
s.begin(9600);
Serial.begin(115200);
pinMode(level0,INPUT);
pinMode(level1,INPUT);
pinMode(level2,INPUT);
pinMode(level3,INPUT);
pinMode(level4,INPUT);
}
 
void loop() {
int data=0;

a=analogRead(level0);
b=analogRead(level1);
c=analogRead(level2);
d=analogRead(level3);
e=analogRead(level4);
Serial.println(a);
Serial.println("a");
Serial.println(b);
Serial.println("b");
Serial.println(c);
Serial.println("c");
Serial.println(d);
Serial.println("d");
Serial.println(e);
Serial.println("e");


if(e>z && d>z && c>z && b>z && a>z )
{
  data =5;
}
if(e<z && d>z && c>z && b>z && a>z)
{
   data = 4;
}

if(e<z && d<z && c>z && b>z && a>z)
   {
      data = 3;
    }
if(e<z && d<z && c<z && b>z && a>z)
 {
   data = 2;
 } 
if(e<z && d<z && c<z && b<z && a>z)
{
  data = 1;
}
if(e<z && d<z && c<z && b<z && a<z)
{
  data = 0;
}
Serial.println(data);
delay(1000);
if(s.available()>0)
{
 s.write(data);
}
}

