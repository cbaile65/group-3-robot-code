void setup() {
  pinMode(35, OUTPUT); //back motor forwards
  pinMode(36, OUTPUT); //back motor backwards
  pinMode(37, OUTPUT); //arm motor forwards
  pinMode(38, OUTPUT); //arm motor backwards

}

void loop() {
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  delay(500);


  digitalWrite(35, HIGH);
  delay(2000);

  digitalWrite(35, LOW);
  digitalWrite(36, HIGH);
  delay(2000);

  digitalWrite(36, LOW);
  digitalWrite(37, HIGH);
  delay(2000);

  digitalWrite(37, LOW);
  digitalWrite(38, HIGH);
  delay(2000);


}
