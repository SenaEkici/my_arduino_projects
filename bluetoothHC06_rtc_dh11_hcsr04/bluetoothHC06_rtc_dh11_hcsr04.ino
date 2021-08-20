#include <Wire.h>

#include <SimpleDHT.h>
#include <SoftwareSerial.h>


int DHpin = 8;
SimpleDHT11 dht11(pinDHT11);


SoftwareSerial Bluetooth(10,9); //rx,tx



void setup() {

 Bluetooth.begin(9600);
  Serial.begin (9600);
  pinMode (DHpin, OUTPUT);
  
}

void loop() {

measuredh11();
if (Bluetooth.available()){
    for(int i=0;i<3;i++)
    {
    Bluetooth.write(dat[i]);
    }
   }


}


delay(3000);
}


 

  void measuredh11(){
    
     // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); 
    Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
    }
