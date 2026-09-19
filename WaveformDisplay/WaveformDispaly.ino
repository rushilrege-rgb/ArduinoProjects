#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int micPin = A0;
int waveform[SCREEN_WIDTH];

// auto-ranging variables
int runningMin = 1023;
int runningMax = 0;

// drift/recalibration control
int driftCounter = 0;
const int driftInterval = 5;   // only recalibrate every N loops (higher = slower/calmer)

// how tight the range is allowed to get (higher = calmer during silence)
const int minRange = 40;

void setup() {
  Serial.begin(9600);

  if (!display.begin(0x3C, true)) {
    Serial.println(F("SH110X allocation failed"));
    while (1);
  }
  display.clearDisplay();
  display.display();

  for (int i = 0; i < SCREEN_WIDTH; i++) {
    waveform[i] = SCREEN_HEIGHT / 2;
  }
}

void loop() {
  int sensorValue = analogRead(micPin);

  // update running min/max immediately if a new extreme is seen
  if (sensorValue < runningMin) runningMin = sensorValue;
  if (sensorValue > runningMax) runningMax = sensorValue;

  // slow recalibration so range drifts back toward center over time
  driftCounter++;
  if (driftCounter >= driftInterval) {
    runningMin = min(runningMin + 1, sensorValue);
    runningMax = max(runningMax - 1, sensorValue);
    driftCounter = 0;
  }

  // enforce a minimum range so quiet noise doesn't get stretched to fill the screen
  int range = runningMax - runningMin;
  if (range < minRange) {
    int mid = (runningMax + runningMin) / 2;
    runningMin = mid - minRange / 2;
    runningMax = mid + minRange / 2;
  }

  int y = map(sensorValue, runningMin, runningMax, SCREEN_HEIGHT - 1, 0);
  y = constrain(y, 0, SCREEN_HEIGHT - 1);

  // shift waveform history left, add new sample on the right
  for (int i = 0; i < SCREEN_WIDTH - 1; i++) {
    waveform[i] = waveform[i + 1];
  }
  waveform[SCREEN_WIDTH - 1] = y;

  // draw
  display.clearDisplay();
  for (int i = 0; i < SCREEN_WIDTH - 1; i++) {
    display.drawLine(i, waveform[i], i + 1, waveform[i + 1], SH110X_WHITE);
  }
  display.display();

  delay(5);
}
