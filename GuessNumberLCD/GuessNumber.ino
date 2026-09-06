#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int randNumber;
int guessNum = 1;

int decPin = 4;
int incPin = 3;
int okPin = 2;

int decPinVal;
int incPinVal;
int okPinVal;

int decPinValOld = 1;
int incPinValOld = 1;
int okPinValOld = 1;

bool enterGame = false;
bool guessConfirmed = false;
bool playAgain = false;


void lcdPrintPadded(int col, int row, String text) {
  while (text.length() < 16) {
    text += " ";
  }
  lcd.setCursor(col, row);
  lcd.print(text);
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  
  
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(decPin, INPUT);
  pinMode(incPin, INPUT);
  pinMode(okPin, INPUT);

  digitalWrite(decPin, HIGH);
  digitalWrite(incPin, HIGH);
  digitalWrite(okPin, HIGH);

  randNumber = random(1, 26);
}

void loop() {
  decPinVal = digitalRead(decPin);
  incPinVal = digitalRead(incPin);
  okPinVal = digitalRead(okPin);

  if(okPinValOld == 0 && okPinVal == 1){
    if(!enterGame){
      enterGame = true;
    }
    else if(!guessConfirmed){
      guessConfirmed = true;
    }
    else if (playAgain){
      enterGame = false;
      guessConfirmed = false;
      playAgain = false;
      guessNum = 1;
      randNumber = random(1, 26);
    }
  }

  if(enterGame){
    if(incPinValOld == 0 && incPinVal == 1){
      if(guessNum != 25){
        guessNum += 1;
      }
    }
  }
  
  if(enterGame){
    if(decPinValOld == 0 && decPinVal == 1){
      if(guessNum != 1){
        guessNum -= 1;
      }
    }
  }

  
  if(!enterGame){
    lcdPrintPadded(0, 0, "Guess the Number");
    lcdPrintPadded(0, 1, "1-25   Press OK");
  } 
  else if(!guessConfirmed){
    lcdPrintPadded(0, 0, "Your Number:");
    lcdPrintPadded(0, 1, String(guessNum));
  } 
  else {
      if(guessNum < randNumber){
        lcdPrintPadded(0, 0, "TOO LOW! Ans:");
        lcdPrintPadded(0,1, String(randNumber));
      }
      else if (guessNum > randNumber){
        lcdPrintPadded(0, 0, "TOO HIGH! Ans:");
        lcdPrintPadded(0, 1, String(randNumber));
      }
      else{
        lcdPrintPadded(0, 0, "CORRECT!");
        lcdPrintPadded(0, 1, "YOU WIN!");
      }
  }


  okPinValOld = okPinVal;
  incPinValOld = incPinVal;
  decPinValOld = decPinVal;

  delay(10);
}

