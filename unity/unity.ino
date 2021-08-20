void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int a=1;
int b=2;

Serial.println(a);
delay(500);

Serial.println(b);
delay(500);

}
