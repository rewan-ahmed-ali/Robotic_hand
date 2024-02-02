// Robotic hand code
// Team of the code : Haidy abou gomaa,Rawan Ahmed, Ahmed Samy  
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1);
String command;
Servo thumbServo;
Servo indexServo;
Servo middleServo;
Servo ringServo;
Servo pinkyServo;
int servoPos = 0;
int middlePos;
int indexPos;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
 // Serial.setTimeout(10);
  pinkyServo.attach(3);
  ringServo.attach(5);
  middleServo.attach(6);
  indexServo.attach(9);
  thumbServo.attach(10);

  ringServo.write(0);
  indexServo.write(0);
  thumbServo.write(0);

 // OpenPinky();
  
}

void loop() {
 while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {break; }
    command += c;
}
  
if (command.length() > 0) {
  Serial.println(command);  
 if(command == "*open hand" || command == "*Open hand"){
    OpenHand();
  }
  else if(command == "*close hand" || command == "*Close hand"){
    CloseHand();
  }
  else if(command == "*open pinky" || command == "*Open pinky" ){
    OpenPinky();
    //Serial.println("True");
  }
  else if(command == "*open ring" ||command == "*Open ring" ){
    OpenRing();
  }
  else if(command == "*open middle" || command == "*Open middle"){
    OpenMiddle();
  }
  else if(command == "*open index" || command == "*Open index"){
    OpenIndex();
  }
  else if(command == "*open some" || command == "*Open some"){
    OpenThumb();
  }
  else if(command == "*close pinky" || command == "*Close pinky" ){
    ClosePinky();
  }
  else if(command == "*close ring" || command == "*Close ring"){
    CloseRing(); 
  }
  else if(command == "*close middle" || command == "*Close middle"){
    CloseMiddle();
  }
  else if(command == "*close index" || command == "*Close index"){
    CloseIndex();
  }
  else if(command == "*close some" || command == "*Close some"){
    CloseThumb();
  }
  else if(command == "*v" || command == "*V"){
      Peace();
    }
  else if(command == "*do" || command == "*Do"){
      Test();
    }
  command = ""; 
}
}



void ClosePinky(){
   pinkyServo.write(0);
  }

void OpenPinky(){
      pinkyServo.write(180);
}



void CloseRing(){
  ringServo.write(0);
    for (int i = 0 ; i <= 180; i++){
      ringServo.write(i);
      delay(5);
    }
  }

void OpenRing(){
  ringServo.write(180);
    for (int i = 180 ; i >= 0; i--){
      ringServo.write(i);
      delay(5);
    }
}




void CloseMiddle(){
    middleServo.write(0);
    middlePos = 0;
  }

void OpenMiddle(){
    middleServo.write(180);
    middlePos = 180;

  }


void CloseIndex(){
    for (int i = 0 ; i <= 180; i++){
      indexServo.write(i);
      delay(5);
    }
    indexPos = 180;
  }

void OpenIndex(){
    for (int i = 180 ; i >= 0; i--){
      indexServo.write(i);
      delay(5);
    }
    indexPos = 0;
}




void CloseThumb(){
    for (int i = 0 ; i <= 180; i++){
      thumbServo.write(i);
      delay(5);
    }
  }

void OpenThumb(){
    for (int i = 180 ; i >= 0; i--){
      thumbServo.write(i);
      delay(5);
    }
}

void CloseHand(){
  
  ClosePinky(),CloseRing(),CloseMiddle(),CloseIndex(),CloseThumb();
}

void OpenHand(){
  
  OpenPinky(),OpenRing(),OpenMiddle(),OpenIndex(),OpenThumb();
}

void Peace(){

  if(indexPos == 0 && middlePos == 0){
      ClosePinky();
      CloseRing();
      CloseThumb();
    }
   else{
      OpenHand();
       ClosePinky();
      CloseRing();
      CloseThumb();
    }  
  
  }


void Test(){
  
  ClosePinky();
  delay(10);
  CloseRing();
   delay(10);
   CloseMiddle();
    delay(10);
    CloseIndex();
     delay(10);
     CloseThumb();
      delay(10);
     OpenThumb();
      delay(10);
      OpenIndex();
       delay(10);
       OpenMiddle();
        delay(10);
        OpenRing();
         delay(10);
         OpenPinky();
  
  
  }