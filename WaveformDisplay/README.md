# KY-038 Mic Waveform Display (SH110X OLED)

A simple Arduino project that reads audio amplitude from a KY-038 microphone module and displays a live scrolling waveform on an SH110X-based OLED screen (128x64, I2C).

## Demo

[Watch the demo video](PASTE_YOUR_VIDEO_LINK_HERE)

## Hardware

- Arduino Uno / Nano (or compatible)
- KY-038 microphone module
- SH110X OLED display (SH1106 or SH1107, 128x64, I2C)
- Breadboard + jumper wires

## Wiring

**KY-038 → Arduino**
| KY-038 pin | Arduino pin |
|---|---|
| VCC | 5V |
| GND | GND |
| A0 (analog out) | A0 |
| D0 | not used |

**SH110X OLED → Arduino**
| OLED pin | Arduino pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCK / SCL | A5 |

## Libraries Required

Install via Arduino Library Manager:
- `Adafruit_GFX`
- `Adafruit_SH110X`

## How It Works

- Reads the mic's analog output (`A0`) every loop.
- Auto-ranges the signal using a running min/max so quiet or loud environments both display well.
- Enforces a minimum range (`minRange`) to prevent the display from looking jittery during silence.
- Slowly recalibrates the min/max range over time (`driftInterval`) so the display adapts to changing volume levels without getting stuck.
- Draws a scrolling waveform line on the OLED based on the scaled signal.

## Tuning

Two constants near the top of the sketch control behavior:
- `minRange` — higher values = calmer display during silence, but louder sounds needed to see visible movement.
- `driftInterval` — higher values = slower, calmer recalibration; lower values = faster adaptation but more twitchy.

## Notes

- The KY-038's analog output is an enveloped/rectified signal, not a true raw audio waveform — great for a reactive visual, not for spectral/pitch analysis.
- Sensitivity is also controlled by the onboard gain trimpot — adjust it alongside the software tuning above for best results.
