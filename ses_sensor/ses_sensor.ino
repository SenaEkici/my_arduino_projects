int sesensor=2;
int led=3;
int sensordurum=0;
void setup() {
 pinMode(sesensor,INPUT);
 pinMode(led,OUTPUT);
 

}

void loop() {
 sensordurum=digitalRead(sesensor);
 if(sensordurum==1)
 {
  digitalWrite(led,HIGH);
 }
 else
 {
  digitalWrite(led,LOW);
  
 }

}
