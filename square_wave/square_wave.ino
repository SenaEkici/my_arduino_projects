int PIN = 13;

void setup() {
  pinMode(PIN, OUTPUT);
}

void loop() {
  int state = 0;

  while(1) {
    if(state == 0) {
      digitalWrite(PIN, LOW);
      state = 1;
    } 
    else {
      digitalWrite(PIN, HIGH);
      state = 0;
    }
    delay(2000);
  }
}
