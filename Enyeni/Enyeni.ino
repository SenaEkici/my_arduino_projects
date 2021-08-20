#include<SoftwareSerial.h>
SoftwareSerial  bt_com(7,6);

void setup() {
  Serial.begin(9600);
  bt_com.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);

}

void loop() {
  if(bt_com.available())
  {
    String data=bt_com.readString();
    Serial.println(data);
    if(data=="A")
    {
      digitalWrite(5,HIGH);
      Serial.println("led yandi");
    }
    if(data=="B")
    {
      digitalWrite(5,LOW);
      Serial.println("led sondu");
    }
    if(data=="W")
    {
      digitalWrite(8,HIGH);
      Serial.println("yesil led yandi");
    }
  }

}
