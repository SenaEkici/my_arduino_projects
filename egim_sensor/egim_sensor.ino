int relay=9;
int tilt=8;



void setup() {
 pinMode(8,INPUT);
 pinMode(9,OUTPUT);

}

void loop() {
int   tilt_gelen=digitalRead(tilt);
  if(tilt_gelen==HIGH)
  {
    digitalWrite(relay,1);
  }
  else
  {
    digitalWrite(relay,0);
  }

}
