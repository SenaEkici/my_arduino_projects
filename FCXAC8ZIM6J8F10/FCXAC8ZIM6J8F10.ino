/*
Author: Danny van den Brande, Arduinosensors.nl. BlueCore Tech.
In this example we switch on a light with a relay and the KY-020 Tilt Switch
 */
int Relay = 2;
int TiltSwitch = 3; 
int val ;
void setup ()
{
  pinMode (Relay, OUTPUT);
  pinMode (TiltSwitch, INPUT);
  Serial.begin(9600);
}
void loop ()
{
  val = digitalRead (TiltSwitch);
    if (val == HIGH) 
  {
    digitalWrite (Relay, HIGH);
    Serial.print ("Value: ");//You can remove the serial print section.
    Serial.println (val);
    delay(100);
  }
  else
  {
    digitalWrite (Relay, LOW);
    Serial.print ("Value: ");//You can remove the serial print section.
    Serial.println (val);
    delay(100);
  }
}
