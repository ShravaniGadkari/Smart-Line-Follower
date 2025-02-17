//Motor A
const int motorPin1  = 2;  
const int motorPin2  = 3;  
//Motor B
const int motorPin3  = 4; 
const int motorPin4  = 5;  

int irRightPin = A0;
int irLeftPin = A1;
int threshold = 500;

int triggerPin=A0;
int echoPin=A1;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(irRightPin, INPUT);
  pinMode(irLeftPin, INPUT);

  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
}
void loop() {
  int distance = getDistance();
  if(distance <= 20 && distance >=0){
    stop();
  }
  else if (analogRead(irRightPin) <= threshold && analogRead(irLeftPin) <= threshold) {
    forward();
  }
  else if (analogRead(irRightPin) >= threshold && analogRead(irLeftPin) <= threshold) {
    right();
  }
  else if (analogRead(irRightPin) <= threshold && analogRead(irLeftPin) >= threshold) {
    left();
  }
  else if (analogRead(irRightPin) >= threshold && analogRead(irLeftPin) >= threshold) {
    stop();
  }
}

int getDistance(){
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  int dur = pulseIn(echoPin, HIGH);
  int dis = (dur/2) / 29.1;
  return dis;
}
void backward()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
void forward()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void right()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
void slowRight()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
void left()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void slowLeft()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
void stop()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
