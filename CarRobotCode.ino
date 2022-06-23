
//Right Motor
int RightMotor1 = 2;
int RightMotor2 = 3;

//Left Motor
int LeftMotor1 = 6;
int LeftMotor2 = 7;
  
//Sensors pins
int RightSensorPin = 11;
int LeftSensorPin = 12;


//Sensors values 
int RightSensorValue = 0;
int LeftSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RightMotor1, OUTPUT);
  pinMode(RightMotor2, OUTPUT);
  pinMode(LeftMotor1, OUTPUT);
  pinMode(LeftMotor2, OUTPUT);
  pinMode(RightSensorPin, INPUT);
  pinMode(LeftSensorPin, INPUT);
  delay(1000);
}

void loop() {

    if(digitalRead(LeftSensorPin) == 0 && digitalRead(RightSensorPin) == 0){
      Forward();
    }else if(digitalRead(LeftSensorPin) == 0 && digitalRead(RightSensorPin) == 1){
      Forward();
      delay(100);
      TurnRight();
    }else if(digitalRead(LeftSensorPin) == 1 && digitalRead(RightSensorPin) == 0){
      Forward();
      delay(100);
      TurnLeft();
    }else if(digitalRead(LeftSensorPin) == 1 && digitalRead(RightSensorPin) == 1){
      Stop();
    }
}

void Forward(){
    Serial.println("Forward");
    digitalWrite(LeftMotor1, LOW);
    digitalWrite(LeftMotor2, HIGH);
    digitalWrite(RightMotor1, LOW);
    digitalWrite(RightMotor2, HIGH);
    delay(100);
    Stop();
    delay(100);
}

void Backward(){
  Serial.println("BACKWORD");
  digitalWrite(RightMotor2, LOW);
  digitalWrite(RightMotor1, HIGH);
  digitalWrite(LeftMotor2, LOW);
  digitalWrite(LeftMotor1, HIGH);
  delay(100);
  Stop();
  delay(100);

}

void TurnLeft(){
  Serial.println("Left");
  digitalWrite(RightMotor2, HIGH);
  digitalWrite(RightMotor1, LOW);
  digitalWrite(LeftMotor2, LOW);
  digitalWrite(LeftMotor1, HIGH);
  delay(100);
  Stop();
  delay(100);
}

void TurnRight(){
  Serial.println("Right");
  digitalWrite(LeftMotor2, HIGH);
  digitalWrite(LeftMotor1, LOW); 
  digitalWrite(RightMotor2, LOW);
  digitalWrite(RightMotor1, HIGH);
  delay(100);
  Stop();
  delay(100);
}

void Stop(){
  Serial.println("Stop");
  digitalWrite(RightMotor1, LOW);
  digitalWrite(RightMotor2, LOW);
  digitalWrite(LeftMotor1, LOW);
  digitalWrite(LeftMotor2, LOW);
}
