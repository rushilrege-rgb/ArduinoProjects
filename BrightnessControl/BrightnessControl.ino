int onButton = 4;
int upButton = 3;
int downButton = 2;

int onButtonValNew;
int upButtonValNew;
int downButtonValNew;

int onButtonValOld = 1;
int upButtonValOld = 1;
int downButtonValOld = 1;

int LEDPin = 6;
int LEDState = 0;

int dt = 25;

int increment = 51;
int analogVal = 0;






void setup() {
  // put your setup code here, to run once:
  pinMode(onButton, INPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  onButtonValNew = digitalRead(onButton);
  upButtonValNew = digitalRead(upButton);
  downButtonValNew = digitalRead(downButton);
  
  Serial.println(analogVal);
  delay(dt);
  

  

  if(onButtonValOld == 0 && onButtonValNew == 1){
    
    if(LEDState == 0){
      analogVal = 255;
      analogWrite(LEDPin, analogVal);
      LEDState = 1;  
    }
    else{
      analogVal = 0;
      analogWrite(LEDPin, analogVal);
      LEDState = 0;
    }
  }
  onButtonValOld = onButtonValNew;
  delay(dt);

  if(LEDState == 1){
    if(upButtonValOld == 0 && upButtonValNew == 1){
      if(analogVal != 255){
        analogVal += increment;
        analogWrite(LEDPin, analogVal);
      }
    }
  }
  upButtonValOld = upButtonValNew;
  delay(dt);

  if(LEDState == 1){
    if(downButtonValOld == 0 && downButtonValNew == 1){
      if(analogVal != 0){
        analogVal -= increment;
        analogWrite(LEDPin, analogVal);
      }
    }
  }
  downButtonValOld = downButtonValNew;
  delay(dt);
}
