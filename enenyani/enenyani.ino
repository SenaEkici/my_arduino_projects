#include<SoftwareSerial.h>
SoftwareSerial  bt_com(7,6);
//rx=6
//tx=7
void setup() {
  Serial.begin(9600);
  bt_com.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);

}

void loop() {
  if(bt_com.available())
  {
    byte data=bt_com.read();
    Serial.println(data);
    if(data=='A')
    {
      digitalWrite(5,HIGH);
      Serial.println("led yandi");
    }
    if(data=='A')
    {
      digitalWrite(5,LOW);
      Serial.println("led SONDU");
    }
    
  }
}
