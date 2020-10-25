#define BLYN K_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int b1 = D1 ; 
int b2 = D2 ;
int buzz = D7;
int b1_value;
int b2_value;

char auth[] = "-zQSabwuJ6C_QmLIDe6GZjuApNVsO3B3";
char ssid[] = "Darshan";
char pass[] = "123456780";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth , ssid , pass);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D7,OUTPUT);
}

void loop()
{
  Blynk.run();
  b1_value = digitalRead(b1);
  b2_value = digitalRead(b2);
  WidgetLED led1(V0);
  WidgetLED led2(V1);
  if (b1_value == HIGH)
  {
    digitalWrite(buzz , HIGH);
    led1.on();
  }
  else
  {
    digitalWrite(buzz , LOW);
    led1.off();
  }
  
  if (b2_value == HIGH)
  {
    digitalWrite(buzz , HIGH);
    led2.on();
  }
  else
  {
    digitalWrite(buzz , LOW);
    led2.off();
  }
}
