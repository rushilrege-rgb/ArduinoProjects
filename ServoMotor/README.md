# Servo Motor Control Projects

This repository contains two Arduino sketches for controlling servo motors using different input methods: buttons and a joystick.

---

## Projects Overview

### 1. ServoButtonHold.ino - Button-Controlled Servo

Control a servo motor smoothly using two push buttons.

**Features:**
- Left button decreases servo angle
- Right button increases servo angle
- Smooth 5-degree increments
- Range: 0° to 180°
- Starting position: 90°

**Hardware Requirements:**
- Arduino microcontroller
- 1x servo motor
- 2x push buttons
- Connecting wires
- Power supply (5V for servo)
- 2x 10K Resistor (also possible without)

**Pin Configuration:**
- Left button: Pin 8
- Right button: Pin 7
- Servo motor: Pin 10

**How It Works:**
The sketch continuously reads the button states. When a button is pressed (LOW signal), the servo position is updated by ±5 degrees and written to the servo. The delay between updates is 15ms to ensure smooth movement.

**Demo Video:**
[ServoButtonHold Demo](https://drive.google.com/file/d/1AG9AV4DcXxbs_OoRK85CX04w7k9AJ-eg/view?usp=sharing)

---

### 2. servoJoystick.ino - Joystick-Controlled Servo

Control a servo motor with precise positioning using an analog joystick.

**Features:**
- Proportional control using joystick X-axis
- Smooth mapping from joystick input to servo angle
- Real-time serial monitoring
- Range: 0° to 180°
- Optional button input on joystick (pin 2)

**Hardware Requirements:**
- Arduino microcontroller
- 1x servo motor
- 1x analog joystick module (2-axis or greater)
- Connecting wires
- Power supply (5V for servo and joystick)

**Pin Configuration:**
- Joystick X-axis: A0 (analog)
- Joystick button: Pin 2 (digital)
- Servo motor: Pin 9

**How It Works:**
The sketch reads the analog value from the joystick's X-axis (0-1023) and maps it to a servo angle (0-180°) using the formula: `servoPos = (90/513) × xVal`. The servo position is updated every 20ms, providing smooth, responsive control. Serial output displays both the servo position and raw analog value for debugging.

**Serial Monitor Output:**
```
90 513
85 483
80 453
...
```

**Demo Video:**
[Joystick Servo Demo](https://drive.google.com/file/d/15iLSHTLK0tgbRkhiXCT_Qgl1KgEFnQ2q/view?usp=sharing)

---

## Customization

### ServoButtonHold
- Adjust `increment` variable to change step size (currently 5°)
- Modify `dt` to change response speed (currently 15ms)
- Change pin numbers to match your wiring

### servoJoystick
- Modify the mapping formula in `servoPos = (90./513.)*xVal;` to adjust sensitivity
- Adjust `dt` to change update frequency (currently 20ms)
- Implement the button input (`sVal`) for additional functionality

---

## Installation

1. Download the sketch files
2. Open in Arduino IDE
3. Install Servo library (usually pre-installed)
4. Select your board type and COM port
5. Upload the sketch to your Arduino

## Troubleshooting

- **Servo doesn't move:** Check power supply and pin connections
- **Jerky movement:** Increase the `dt` delay value
- **Buttons not responding:** Verify pull-up resistors and pin connections
- **Serial output not displaying:** Check baud rate (9600) matches Serial Monitor

---

## License

Feel free to use and modify these sketches for your projects.
