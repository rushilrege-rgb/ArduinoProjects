# Joystick-Controlled LED Compass

An analog joystick controls 8 LEDs arranged in a circular pattern (like a compass), lighting up the LED that corresponds to the joystick's current direction.

## 🎥 Demo Video

[Watch the demo](https://drive.google.com/file/d/1R-YVR-b5-smIB7FhlnYlBVmMSBwVts_5/view?usp=sharing)

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

Each of the 8 LEDs is wired in series with its own 330Ω current-limiting resistor to protect it from excess
