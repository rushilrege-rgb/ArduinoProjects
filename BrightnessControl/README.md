# LED Brightness Controller

An Arduino project that allows you to toggle an LED on/off and adjust its brightness using three push buttons.

## Features
- Toggle LED on/off with one button
- Increase brightness with up button (when LED is on)
- Decrease brightness with down button (when LED is on)
- PWM-based brightness control with 5 brightness levels
- Debounce implementation for reliable button detection
- Serial monitor displays current brightness value

## Components
- Arduino (Uno, Nano, etc.)
- 3x Push buttons
- LED
- 220Ω Resistor (for LED current limiting)
- Breadboard and jumper wires

## Pin Configuration
- **Pin 4**: On/Off button
- **Pin 3**: Brightness up button
- **Pin 2**: Brightness down button
- **Pin 6**: LED output (PWM-capable pin)

## How It Works
The project uses PWM (Pulse Width Modulation) to control LED brightness:
- **On/Off Button** (pin 4): Toggles the LED between off (0) and full brightness (255)
- **Up Button** (pin 3): Increases brightness by 51 units when LED is on (max 255)
- **Down Button** (pin 2): Decreases brightness by 51 units when LED is on (min 0)

The brightness increments in 5 levels: 0 → 51 → 102 → 153 → 204 → 255

## Brightness Levels
- Level 0: Off
- Level 1: 20% (51)
- Level 2: 40% (102)
- Level 3: 60% (153)
- Level 4: 80% (204)
- Level 5: 100% (255)

## Wiring
1. Connect on/off button to pin 4
2. Connect up button to pin 3
3. Connect down button to pin 2
4. Connect LED to pin 6 (through 220Ω resistor)

## Demo
[Video Demo](https://drive.google.com/file/d/1KXIQL86ZGWvfgH99BWUqX3pH5Ey58xD1/view?usp=sharing)

## Usage
1. Wire the buttons and LED as described above
2. Upload the code to your Arduino
3. Press the on/off button to turn the LED on/off
4. When LED is on, press up/down buttons to adjust brightness
5. Open the Serial Monitor (9600 baud) to see brightness values
