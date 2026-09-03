# Dimmable LED
A simple Arduino project that uses an analog input to control the brightness of two LEDs.

## Components
- Arduino Uno
- Green LED
- Red LED
- 2 × resistors
- Potentiometer
- Breadboard
- Jumper wires

## How It Works
The potentiometer is connected to analog pin A5. The Arduino reads the potentiometer value using `analogRead()` and converts the reading into a voltage and PWM output value.
The PWM output is then used to control the brightness of both the green and red LEDs.
Turning the potentiometer changes the brightness of the LEDs.
The calculated output is also displayed in the Serial Monitor at 9600 baud.

## Demo Video

[Watch the demo](https://drive.google.com/file/d/13ir75VylQUdBoy6ApvpqNY70bBaKW1pI/view?usp=sharing)

## Code
The Arduino sketch is contained in `DimmableLED.ino`.

### Main Functions
- `analogRead()` reads the analog input from A5.
- The analog reading is converted to voltage.
- The reading is mapped to a PWM range of 0–255.
- `analogWrite()` controls the brightness of the LEDs.
- `Serial.println()` displays the output value in the Serial Monitor.

## Serial Monitor
Set the Serial Monitor to:
```text
9600 baud
```

---




