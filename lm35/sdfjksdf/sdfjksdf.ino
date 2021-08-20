void setup() {
  
Serial.begin(9600);
}

void loop() {
 int sicaklik=analogRead(5);
 sicaklik=sicaklik*0.488281;//anologdan dijitale donusturme
 Serial.println(sicaklik);
delay(1000);
}
