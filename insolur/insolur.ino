int gelen;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    gelen=Serial.read();
 if(gelen=='H')
 {
  digitalWrite(13,HIGH);
 }
 if(gelen=='L')
 {
  digitalWrite(13,LOW);
 }
    
  }

}
