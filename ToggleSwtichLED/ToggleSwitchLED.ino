int button1 = 6;
int button2 = 7;
int button1ValNew;
int button2ValNew;
int button1ValOld = 1;
int button2ValOld = 1;
int redLED = 8;
int blueLED = 9;
int redLEDState = 0;
int blueLEDState = 0;

int dt = 50;



void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  button1ValNew = digitalRead(button1);
  button2ValNew = digitalRead(button2);




  if(button1ValOld == 0 && button1ValNew == 1){
    if(redLEDState == 0){
      digitalWrite(redLED, HIGH);
      redLEDState = 1;
    }
    else{
      digitalWrite(redLED, LOW);
      redLEDState = 0;
    }
  }
  button1ValOld = button1ValNew;
  delay(dt);

  if(button2ValOld == 0 && button2ValNew == 1){
    if(blueLEDState == 0){
      digitalWrite(blueLED, HIGH);
      blueLEDState = 1;
  
    }
    else{
      digitalWrite(blueLED, LOW);
      blueLEDState = 0;
    }
    
  }
  button2ValOld = button2ValNew;
  delay(dt);



  


}

