int readpin = A5;
int readval;
float analogOutG;
float analogOutR;
float v;
int dt = 10;
int Gled = 3;
int Rled = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(readpin, INPUT);
  pinMode(Gled, OUTPUT);
  pinMode(Rled, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readval = analogRead(readpin);
  v = (5./1023.)*readval;
  
  
  analogOutG = (255./1023.)*readval;
  analogWrite(Gled, analogOutG);

  analogOutR = (255./1023.)*readval;
  analogWrite(Rled, analogOutR);

  Serial.println(analogOutG *(5./255.));
  delay(dt);



}

