# Guess the Number — Arduino LCD Game

A simple number-guessing game built with an Arduino, a 16x2 character LCD, and three push buttons (Increment, Decrement, OK). The Arduino picks a random number between 1 and 25, and the player uses the buttons to guess it.

## Demo

📹 [Video Demo](https://drive.google.com/file/d/10GHGgNoj18zjrNMKxXmkrNZbYesWNtUs/view?usp=sharing)

## Hardware Used

- Arduino (Uno or compatible)
- 16x2 character LCD (HD44780-compatible, parallel interface)
- 3x push buttons (Increment, Decrement, OK)
- Breadboard + jumper wires

## Pin Configuration

| Component | Arduino Pin |
|-----------|--------------|
| LCD RS    | 7  |
| LCD EN    | 8  |
| LCD D4    | 9  |
| LCD D5    | 10 |
| LCD D6    | 11 |
| LCD D7    | 12 |
| Decrement Button | 4 |
| Increment Button | 3 |
| OK Button | 2 |

Buttons use the Arduino's internal pull-up resistors, so each button should be wired between its pin and **GND**. Pressing a button pulls the pin LOW; releasing it returns to HIGH.

## How to Play

1. **Power on** — the LCD shows "Guess the Number" and prompts you to press OK.
2. **Press OK** — enters the guessing screen, starting at 1.
3. **Use Increment / Decrement** — adjust your guess between 1 and 25.
4. **Press OK again** — locks in your guess and shows the result:
   - Too low → shows the correct answer
   - Too high → shows the correct answer
   - Correct → "YOU WIN!"
5. **Press OK a third time** — resets the game with a new random number so you can play again.

## Code Structure

The game is built around two boolean state flags that control which screen is shown and what the buttons do at each stage:

- `enterGame` — becomes `true` on the first OK press, moving from the title screen to the guessing screen.
- `guessConfirmed` — becomes `true` on the second OK press, locking the guess and showing the result.

A third OK press (once both flags are `true`) resets both flags, resets `guessNum`, and generates a new `randNumber`, returning to the title screen.

The `lcdPrintPadded()` helper pads every string to 16 characters before printing, so old text is always fully overwritten and the display never shows leftover characters from a previous screen.

## Suggestions for Improvement

- **Debounce more robustly.** The current `delay(10)` provides basic debouncing, but a dedicated debounce library (e.g. Bounce2) or a millis()-based debounce timer would make button reads more reliable, especially on cheaper/noisier switches.
- **Add attempt counting.** Track how many guesses the player takes before winning and display it on the result screen — adds a scoring element.
- **Add a "too close" hint.** For a slightly easier or more informative game, show "Close!" when the guess is within 1-2 of the answer, alongside "too high/low."
- **Re-seed randomness per play.** `randomSeed(analogRead(0))` only runs once in `setup()`. Since an unconnected analog pin tends to float, this is usually fine, but for extra randomness on replay you could call `randomSeed(analogRead(A0) + millis())` right before generating a new `randNumber` on reset.
- **Use `INPUT_PULLUP` instead of `INPUT` + `digitalWrite(pin, HIGH)`.** Functionally equivalent, but `pinMode(pin, INPUT_PULLUP)` is the clearer, modern way to enable the internal pull-up resistor.
- **Refactor with an `enum` state machine.** As you add more screens/features (attempt counter, difficulty levels, etc.), replacing the two/three booleans with a single `enum GameState { TITLE, GUESSING, RESULT }` and a `switch` statement will make the code easier to extend and reason about.
- **Extract magic numbers.** Replace hardcoded values like `25`, `1`, and `26` with named constants (e.g. `const int MAX_NUM = 25;`) so the guess range is easy to change in one place.
