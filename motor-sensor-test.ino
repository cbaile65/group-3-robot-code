int distance;
long duration;

void setup() {

  pinMode(5, OUTPUT); // Sets the trigPin as an Output 
  pinMode(4, INPUT); // Sets the echoPin as an Input

  pinMode(35, OUTPUT); //back motor forwards
  pinMode(36, OUTPUT); //back motor backwards
  pinMode(37, OUTPUT); //arm motor forwards
  pinMode(38, OUTPUT); //arm motor backwards

  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
}

void loop() {


  digitalWrite(5, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(5, HIGH);
      delayMicroseconds(10);
      digitalWrite(5, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(4, HIGH);
      // Calculating the distance
      distance= duration*0.034/2;
      Serial.println(distance);


      digitalWrite(37, HIGH);
      if(distance <= 10){
        digitalWrite(37, LOW);
      }


}
