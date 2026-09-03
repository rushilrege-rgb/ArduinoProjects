# Toggle Switch LED

An Arduino project that uses two buttons to toggle two LEDs on and off independently.

## Features
- Two push buttons for independent LED control
- Each button toggles its corresponding LED on/off
- Debounce implementation for reliable button detection
- Simple state management system

## Components
- Arduino (Uno, Nano, etc.)
- 2x Push buttons
- Red LED
- Blue LED
- 2x 220Ω Resistors (for LED current limiting)
- Breadboard and jumper wires

## Pin Configuration
- **Pin 6**: Button 1 (controls red LED)
- **Pin 7**: Button 2 (controls blue LED)
- **Pin 8**: Red LED output
- **Pin 9**: Blue LED output

## How It Works
Each button press toggles its corresponding LED:
- **Button 1** on pin 6 toggles the **red LED** on pin 8
- **Button 2** on pin 7 toggles the **blue LED** on pin 9

The code uses debounce logic to detect rising edges (LOW to HIGH transitions) with a 50ms delay to prevent false triggers from button bounce.

## Wiring
1. Connect button 1 to pin 6 (with pull-down or pull-up configuration)
2. Connect button 2 to pin 7 (with pull-down or pull-up configuration)
3. Connect red LED to pin 8 (through 220Ω resistor)
4. Connect blue LED to pin 9 (through 220Ω resistor)

## Demo
[Video Demo](https://drive.google.com/file/d/1Ebn9E-CKRvJF63nyL_aDEAdLIIdbSCFl/view?usp=sharing)

## Usage
1. Wire the buttons and LEDs as described above
2. Upload the code to your Arduino
3. Press button 1 to toggle the red LED on/off
4. Press button 2 to toggle the blue LED on/off
