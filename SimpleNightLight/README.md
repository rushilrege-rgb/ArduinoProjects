# Simple Night Light

A simple Arduino project that creates an automated night light using a light sensor and red LED.

## Features
- Automatically turns on when it gets dark
- Uses an LDR (Light Dependent Resistor) to detect ambient light
- Simple and beginner-friendly code
- Threshold value: 300 (adjustable)

## Components
- Arduino (Uno, Nano, etc.)
- LDR (Light Dependent Resistor)
- Red LED
- 10kΩ Resistor (for LDR voltage divider)
- 220Ω Resistor (for LED current limiting)
- Breadboard and jumper wires

## Pin Configuration
- **A5**: Analog input (LDR sensor)
- **Pin 8**: Digital output (Red LED)

## How It Works
The LDR sensor reads ambient light levels on pin A5. When the sensor value drops below 300, the red LED on pin 8 turns on automatically. When the light level rises above 300, the LED turns off. The serial monitor displays the sensor readings for debugging and threshold adjustment.

## Adjusting Sensitivity
To make the night light more or less sensitive, adjust the threshold value `300` in the code:
- **Lower values** = LED turns on when it's darker
- **Higher values** = LED turns on when there's still more light

## Demo
[Video Demo](https://drive.google.com/file/d/1P3j58bL_NDO-W-FOweVbVHQLdai39Gv4/view?usp=sharing)

## Usage
1. Wire the LDR to pin A5 and the red LED to pin 8
2. Upload the code to your Arduino
3. Open the Serial Monitor to see sensor readings
4. Adjust the threshold value (300) if needed for your environment
