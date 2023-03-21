#define trigF 5
#define echoF 4
// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

int step;
int duration;
int distance;


void setup() {
 step = 3;

//pins from left to right
  pinMode(21, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(35, OUTPUT); //rear arm extend
  pinMode(36, OUTPUT); //rear arm retract
  pinMode(37, OUTPUT); //stendo arm backwards
  pinMode(38, OUTPUT); //stebndo arm forwards
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT); 
  pinMode(42, OUTPUT); 
  pinMode(2, OUTPUT); 
  pinMode(1, OUTPUT); 

  pinMode(trigF, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoF, INPUT); // Sets the echoPin as an Input
}

void loop() {
  
  switch(step){

//move to edge and stop
case 0:    
   // Clears the trigPin
      digitalWrite(trigF, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigF, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigF, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoF, HIGH);
      // Calculating the distance
      distance= duration*0.034/2;
      Serial.println(distance);

      if(distance <= 5){
        digitalWrite(41, HIGH);
      }

      if (distance >= 5){
        step = 1;
      }
      break;

      //extend front arm
      case 1:

      break;

      //stepper move front arm to table
      case 2:

      break;

      //extend back wheels
      case 3:
      digitalWrite(35, HIGH);
      delay(4000);
      digitalWrite(35, LOW);
      step = 4;
      break;

      //front arm pull
      case 4:
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
      if(distance <= 5){
        digitalWrite(37, LOW);
      step = 5;
      }
      break;

      //pull back wheels up      
      case 5:
      digitalWrite(36, HIGH);
      delay(4000);
      digitalWrite(36, LOW);
      step = 6;
      break;

      //retract front arm
      case 6:

      break;

      //arm rotate back to stating position
      case 7:

      break;

      //drive forwards?
      case 8:

      break;
  }
  
}