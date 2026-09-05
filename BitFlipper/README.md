# Bit Flipper — 8-LED Shift Register Blinker

An Arduino project that drives 8 LEDs through a 74HC595 serial-in/parallel-out shift register, alternating between two patterns (`11110000` and `00001111`) every 500 ms.

## How It Works

Instead of wiring 8 LEDs directly to 8 Arduino pins, this project uses a **74HC595 shift register** to control all 8 LEDs using just 3 Arduino pins. The Arduino sends a byte of data serially (one bit at a time) into the shift register, which then outputs that byte in parallel across its 8 output pins — each driving one LED.

Every loop, the current LED pattern is bitwise-inverted (`255 - LEDs`), so the lit and unlit LEDs swap, creating a flipping/alternating effect.

## Hardware Required

| Qty | Component |
|-----|-----------|
| 1 | Arduino (Uno or similar) |
| 1 | 74HC595 shift register (8-bit serial-in, parallel-out) |
| 8 | LEDs |
| 8 | 330 Ω resistors |
| 1 | Breadboard |
| — | Jumper wires |

## Pin Connections

### Arduino → 74HC595

| Arduino Pin | Function | 74HC595 Pin |
|-------------|----------|-------------|
| 11 | Latch (ST_CP) | Pin 12 (RCLK) |
| 9  | Clock (SH_CP) | Pin 11 (SRCLK) |
| 12 | Data (DS)     | Pin 14 (SER) |
| 5V | Power         | Pin 16 (VCC) |
| GND | Ground       | Pin 8 (GND) |
| GND | Pin 13 (OE) — tie LOW to enable outputs | |
| GND | Pin 10 (MR) — tie HIGH to disable reset | |

> Note: Pin 10 (MR / Master Reset) should be connected to **5V** (active-low reset — keep it HIGH so the register isn't held in reset), and pin 13 (OE / Output Enable) should be connected to **GND** (active-low enable — keep it LOW so outputs are active).

### 74HC595 → LEDs

The 74HC595 has 8 parallel output pins (Q0–Q7, physical pins 15, 1–7). Each output connects to one LED, and each LED connects through a 330 Ω resistor to ground.

```
74HC595 Output (Qx) → LED anode (+)
LED cathode (–) → 330 Ω resistor → GND
```

Repeat this for all 8 outputs (Q0 through Q7) to light all 8 LEDs.

## Demo Video

[Watch the demo here](https://drive.google.com/file/d/1c_FFbAY20ffVQNARZWQbMK-LxwA8SxKj/view?usp=sharing)

## Code Overview

```cpp
int latchPin = 11;
int clockPin = 9;
int dataPin  = 12;
int dt = 500;

byte LEDs = 0b11110000;
```

- `latchPin`, `clockPin`, and `dataPin` map to the three control lines on the shift register.
- `LEDs` is a byte where each bit represents one LED (1 = on, 0 = off). It starts as `11110000`, meaning the top 4 LEDs are on and the bottom 4 are off.
- `dt` sets the delay (in ms) between pattern flips.

### `setup()`
Initializes serial communication and sets the three control pins as outputs.

### `loop()`
1. Pulls `latchPin` LOW to begin sending data.
2. Uses `shiftOut()` to push the `LEDs` byte into the shift register, least-significant-bit first.
3. Pulls `latchPin` HIGH to latch the data to the output pins (this is what actually updates the LEDs).
4. Inverts `LEDs` (`255 - LEDs`) so the pattern flips on the next cycle.
5. Waits `dt` milliseconds before repeating.

## Behavior

The 8 LEDs alternate between two states every 500 ms:

- **State A:** `11110000` → LEDs 7-4 ON, LEDs 3-0 OFF
- **State B:** `00001111` → LEDs 7-4 OFF, LEDs 3-0 ON

This creates a simple flipping/blinking pattern where one half of the LEDs is always lit while the other half is dark, and they swap every half second.

## Customization Ideas

- Change `dt` to speed up or slow down the flip rate.
- Change the initial `LEDs` value to start with a different pattern (e.g., `0b10101010` for alternating LEDs).
- Replace the invert logic with a bit-shift (`LEDs = LEDs << 1` or `>> 1`) to create a "chasing light" (Knight Rider) effect instead of a flip.

## License

Free to use and modify for personal or educational projects.
