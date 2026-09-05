# Joystick-Controlled LED Compass

An analog joystick controls 8 LEDs arranged in a circular pattern (like a compass), lighting up the LED that corresponds to the joystick's current direction.

## 🎥 Demo Video

[https://drive.google.com/file/d/1R-YVR-b5-smIB7FhlnYlBVmMSBwVts_5/view?usp=sharing]

## Overview

The joystick outputs two analog values (X and Y axis). Depending on which direction the joystick is pushed, a corresponding LED lights up:

- Center → all LEDs off
- Left / Right / Up / Down → the 4 cardinal LEDs
- Diagonals → the 4 corner LEDs

This creates a simple 8-direction LED "compass" driven entirely by joystick position.

## Hardware Used

| Component            | Quantity |
|-----------------------|----------|
| Arduino (Uno/Nano/etc)| 1        |
| Analog joystick module| 1        |
| LEDs                   | 8        |
| 330Ω resistors         | 8        |
| Jumper wires           | as needed|
| Breadboard              | 1        |

Each of the 8 LEDs is wired in series with its own 330Ω current-limiting resistor to protect it from excess current.

## LED Layout

The 8 LEDs are arranged in a circle (like a clock face / compass rose), matching the 8 directions of joystick movement — each LED sits at its compass position (N, NE, E, SE, S, SW, W, NW) around the joystick.

## Pin Wiring

| Signal    | Arduino Pin | Direction Represented |
|-----------|-------------|------------------------|
| red1      | 3           | Right (X max)          |
| red2      | 5           | Up (Y max)             |
| blue1     | 4           | Right / X max diagonal |
| blue2     | 2           | Left (X min)           |
| yellow1   | 7           | Down-Left (X min, Y min)|
| yellow2   | 6           | Down-Right (X max, Y min)|
| green1    | 8           | Up-Right (X max, Y max)|
| green2    | 9           | Up-Left (X min, Y max) |
| Joystick X| A0          | —                       |
| Joystick Y| A1          | —                       |

## How It Works

1. The joystick's X and Y axis values are read using `analogRead()`.
2. These values are printed to the Serial Monitor for debugging (`Serial.begin(9600)`).
3. Based on the X/Y reading, the corresponding LED is turned `HIGH` while all others are set `LOW`.
4. Center position (~510, ~530) turns all LEDs off.

## Known Limitation

The current code checks for **exact** joystick values (e.g. `xVal == 510`). In practice, joystick potentiometers are noisy and rarely return the exact same number twice, so LEDs may not always trigger reliably at the edges. Using **ranges** (e.g. `xVal > 800`) instead of exact equality is recommended for more consistent behavior.

## License

Feel free to use, modify, and share this project.
