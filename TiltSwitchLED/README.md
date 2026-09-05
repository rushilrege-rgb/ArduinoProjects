# Tilt Switch LED Control Project

Control LEDs using a tilt switch sensor to detect orientation.

---

## Project Overview

This Arduino sketch uses a tilt switch to detect when the device is tilted and controls two LEDs accordingly. It's a simple but effective way to create orientation-aware lighting.

**Features:**
- Tilt detection using a tilt switch sensor
- Dual LED output (red and green)
- Real-time serial monitoring
- Simple binary control logic

---

## How It Works

The tilt switch is a simple ball-based sensor that completes a circuit when tilted and breaks the circuit when level. The Arduino reads this state and controls two LEDs:

- **When tilted** (tilt switch closes, reads LOW):
  - Green LED: **ON**
  - Red LED: **OFF**

- **When level** (tilt switch open, reads HIGH):
  - Red LED: **ON**
  - Green LED: **OFF**

The serial monitor continuously outputs the tilt switch state for debugging and monitoring purposes.

---

## Hardware Requirements

- Arduino microcontroller
- 1x tilt switch sensor
- 2x LEDs (1 red, 1 green)
- 2x resistors (220Ω recommended for LED protection)
- 1x pull-up resistor (10kΩ recommended for tilt switch)
- Connecting wires
- Power supply (5V)

---

## Pin Configuration

| Component | Arduino Pin | Type |
|-----------|------------|------|
| Tilt Switch | Pin 2 | Digital Input |
| Red LED | Pin 8 | Digital Output |
| Green LED | Pin 9 | Digital Output |

---

## Wiring Diagram

```
Tilt Switch:
  - Pin 2 (INPUT with pull-up enabled)
  - 5V and GND connections

Red LED:
  - Anode → Pin 8 (through 220Ω resistor)
  - Cathode → GND

Green LED:
  - Anode → Pin 9 (through 220Ω resistor)
  - Cathode → GND
```

---

## Code Explanation

```cpp
// Read tilt switch state (digital)
tiltVal = digitalRead(tiltSwitch);

// Control LEDs based on tilt state
if(tiltVal == 0){  // Tilted
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
}
else{  // Level
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
}
```

---

## Serial Monitor Output

The serial monitor will display the tilt switch state at 100ms intervals:

```
0
0
0
1
1
1
0
...
```

- `0` = Tilted (green LED on)
- `1` = Level (red LED on)

---

## Customization

### Change Update Speed
Modify the `delay(100);` value to adjust how frequently the sensor is read:
- Decrease for faster response
- Increase to reduce processor load

### Change Pin Assignments
Simply modify these lines at the top of the sketch:
```cpp
int tiltSwitch = 2;    // Change to your desired pin
int redLED = 8;        // Change to your desired pin
int greenLED = 9;      // Change to your desired pin
```

### Extend Functionality
You can expand this project to:
- Control buzzer sounds when tilted
- Log tilt events to EEPROM
- Use multiple tilt switches
- Add PWM brightness control to LEDs

---

## Troubleshooting

| Issue | Solution |
|-------|----------|
| LEDs don't light up | Check LED polarity and resistor values |
| Tilt switch not detecting | Verify pull-up resistor and pin connections |
| Erratic LED behavior | Add a capacitor across the tilt switch for debouncing |
| Serial data shows constant 0 or 1 | Check tilt switch for stuck contacts |

---

## Demo Video

[INSERT VIDEO LINK HERE - Tilt Switch LED Demo](VIDEO_URL)

---

## Installation

1. Download the sketch file
2. Open in Arduino IDE
3. Select your board type and COM port
4. Upload the sketch to your Arduino
5. Open the Serial Monitor (9600 baud) to see output

---

## License

Feel free to use and modify this sketch for your projects.
