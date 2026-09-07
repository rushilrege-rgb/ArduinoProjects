# DHT11 Temperature & Humidity Display

A simple Arduino project that reads temperature and humidity from a DHT11 sensor and displays the readings live on a 16x2 LCD screen, with a buzzer pin ready for alerts.

## 🎥 Video Demo

[Watch the demo video](https://drive.google.com/file/d/1TJk3i64FOI2UCIM8JdQglZltZ1YUPAkp/view?usp=sharing)


## Features

- Real-time temperature (°C) and humidity (%) readings
- Live display on a 16x2 character LCD
- Buzzer pin configured for future alert functionality (e.g. temperature/humidity thresholds)

## Hardware Used

- Arduino (Uno or compatible)
- DHT11 Temperature & Humidity Sensor (3-pin breakout board)
- 16x2 LCD display (HD44780-compatible)
- Buzzer
- Breadboard + jumper wires

## Wiring

### DHT11 Sensor
| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| VCC (+)   | 5V          |
| GND (-)   | GND         |
| OUT       | Pin 4       |

### LCD (16x2)
| LCD Pin | Arduino Pin |
|---------|-------------|
| RS      | Pin 7       |
| EN      | Pin 8       |
| D4      | Pin 9       |
| D5      | Pin 10      |
| D6      | Pin 11      |
| D7      | Pin 12      |

### Buzzer
| Buzzer Pin | Arduino Pin |
|------------|-------------|
| Signal     | Pin 3       |

> **Note:** Standard LCD wiring also requires connecting VSS to GND, VDD to 5V, and V0 (contrast) to a potentiometer or GND depending on your display's brightness needs. RW is typically tied to GND for write-only mode.

## Libraries Required

Install these via **Arduino IDE → Sketch → Include Library → Manage Libraries**:

- `DHT sensor library` by Adafruit
- `Adafruit Unified Sensor` by Adafruit
- `LiquidCrystal` (built into the Arduino IDE by default)


## Troubleshooting

- **Getting \`nan\` readings?** Make sure \`Type\` matches your actual sensor (DHT11 vs DHT22), check wiring, and ensure delay between reads is at least 1000ms for DHT11.
- **LCD shows blank or garbled text?** Double-check the contrast pin (V0) is wired to a potentiometer, and confirm the RS/EN/D4-D7 pins match your code.
- **Compilation error about \`Adafruit_Sensor.h\`?** Install the "Adafruit Unified Sensor" library alongside the DHT sensor library.

## License

Feel free to use, modify, and share this project.
