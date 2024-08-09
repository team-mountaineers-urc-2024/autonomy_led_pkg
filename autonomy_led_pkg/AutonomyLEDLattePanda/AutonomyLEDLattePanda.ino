#include <FastLED.h>

#define NUM_LEDS 12          // Number of LEDs in your strip
#define DATA_PIN 9           // Pin connected to the of the LED strip

CRGB leds[NUM_LEDS];         // Define the array of LEDs
int mode = 0;      //set to 0 to have LEDs start in "Startup" Case

void setup() {
  Serial.begin(9600);        // Set the baud rate to match the LattePanda Sigma's Arduino part
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // Specify the LED strip type and configuration
}

void loop() {
  if (Serial.available() > 0) { //if data available
    int temp = Serial.read(); // get value
    if(temp == 48 || temp == 49 || temp == 50 || temp == 51 || temp == 52 || temp == 53 || temp == 54 || temp == 55){ //if data is either '0', '1', '2', '3', '4', '5', '6', '7'
      mode = temp; //change mode
      // Serial.println(mode);  //test print
    }
  }

  switch (mode) {
      case 0: //Startup Case
        startupSequence();
        mode = 49; //Go to Blue
        break;
      case 48: //Ascii for 0 (Autonomous)
        displayColor(CRGB::Red);
        break;
      case 49: //Ascii for 1 (TeleOp)
        displayColor(CRGB::Blue);
        break;
      case 50: //Ascii for 2 (Arrival)
        displayColorThenDelay(CRGB::Green, 500);
        displayColorThenDelay(CRGB::Black, 500);
        break;
      case 51: //Ascii for 3 (WeeWoo)
        displayColorThenDelay(CRGB::Red, 500);
        displayColorThenDelay(CRGB::Blue, 500);
        break;
      case 52: //Ascii for 4 (Party)
        displayColorThenDelay(CRGB::Red, 100);
        displayColorThenDelay(CRGB::Orange, 100);
        displayColorThenDelay(CRGB::Yellow, 100);
        displayColorThenDelay(CRGB::Green, 100);
        displayColorThenDelay(CRGB::Blue, 100);
        displayColorThenDelay(CRGB::Purple, 100);
        break;
      case 53: //Ascii for 5 (WVU)
        displayColorThenDelay(0xEAAA00, 500);
        displayColorThenDelay(0x002855, 500);
        break;
      case 54: //Ascii for 6 (Rainbow)
        displayColorAtIndex(CRGB::Red, 7);
        displayColorAtIndex(CRGB::Orange, 6);
        displayColorAtIndex(CRGB::Orange, 0);
        displayColorAtIndex(CRGB::Yellow, 5);
        displayColorAtIndex(CRGB::Yellow, 1);
        displayColorAtIndex(CRGB::Yellow, 8);
        displayColorAtIndex(CRGB::Green, 4);
        displayColorAtIndex(CRGB::Green, 2);
        displayColorAtIndex(CRGB::Green, 9);
        displayColorAtIndex(CRGB::Blue, 3);
        displayColorAtIndex(CRGB::Blue, 10);
        displayColorAtIndex(CRGB::Purple, 11);
        break;
      case 55: //Ascii for 7 (Monash)
        displayColor(0xFC4C4E);
        break;
      default: // Do nothing for unknown values. Should never be able to reach, since recievedValue is only updated to one of the cases.
        break;
    }
}

void displayColor(CRGB color) {
  displayColorThenDelay(color, 0);
}

void displayColorThenDelay(CRGB color, int milisec) {
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show(); // Update the LED strip
  delay(milisec);
}

void displayColorAtIndex(CRGB color, int index) {
  displayColorAtIndexThenDelay(color, index, 0);
}

void displayColorAtIndexThenDelay(CRGB color, int index, int milisec) {
  leds[index] = color;
  FastLED.show(); // Update the LED strip
  delay(milisec);
}

void startupSequence() {
  displayColorAtIndexThenDelay(CRGB::Blue, 7, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 6, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 5, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 4, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 3, 100);
  displayColorAtIndex(CRGB::Blue, 11);
  displayColorAtIndexThenDelay(CRGB::Black, 7, 100);
  displayColorAtIndex(CRGB::Blue, 10);
  displayColorAtIndexThenDelay(CRGB::Black, 6, 100);
  displayColorAtIndex(CRGB::Blue, 9);
  displayColorAtIndexThenDelay(CRGB::Black, 5, 100);
  displayColorAtIndex(CRGB::Blue, 8);
  displayColorAtIndexThenDelay(CRGB::Black, 4, 100);
  displayColorAtIndex(CRGB::Blue, 0);
  displayColorAtIndexThenDelay(CRGB::Black, 3, 100);
  displayColorAtIndex(CRGB::Blue, 1);
  displayColorAtIndexThenDelay(CRGB::Black, 11, 100);
  displayColorAtIndex(CRGB::Blue, 2);
  displayColorAtIndexThenDelay(CRGB::Black, 10, 100);
  displayColorAtIndex(CRGB::Blue, 3);
  displayColorAtIndexThenDelay(CRGB::Black, 9, 100);
  displayColorAtIndex(CRGB::Blue, 4);
  displayColorAtIndexThenDelay(CRGB::Black, 8, 100);
  displayColorAtIndex(CRGB::Blue, 5);
  displayColorAtIndexThenDelay(CRGB::Black, 0, 100);
  displayColorAtIndex(CRGB::Blue, 6);
  displayColorAtIndexThenDelay(CRGB::Black, 1, 100);
  displayColorAtIndex(CRGB::Blue, 7);
  displayColorAtIndexThenDelay(CRGB::Black, 2, 100);
  displayColorAtIndex(CRGB::Blue, 0);
  displayColorAtIndexThenDelay(CRGB::Black, 3, 100);
  displayColorAtIndex(CRGB::Blue, 8);
  displayColorAtIndexThenDelay(CRGB::Black, 4, 100);
  displayColorAtIndex(CRGB::Blue, 9);
  displayColorAtIndexThenDelay(CRGB::Black, 5, 100);
  displayColorAtIndex(CRGB::Blue, 1);
  displayColorAtIndexThenDelay(CRGB::Black, 6, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 6, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 5, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 2, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 10, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 11, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 3, 100);
  displayColorAtIndexThenDelay(CRGB::Blue, 4, 100);
}
