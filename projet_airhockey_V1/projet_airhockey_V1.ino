#define BUTTON_BLUE 2
#define BUTTON_RED 7
#define BUTTON_RESET 4

#define PIN_PIXELS_SCORE 11
#define LEDS_SCORE 7

#define PIN_LEDS_AMBIANCE 8
#define LEDS_AMBIANCE_TOTAL 100

#define LEDS_AMBIANCE_BLUE 50
#define LEDS_AMBIANCE_RED 50

// Définition des couleurs
#define COLOR_BLUE pixels.Color(0, 0, 255)
#define COLOR_RED pixels.Color(255, 0, 0)
#define COLOR_OFF pixels.Color(0, 0, 0)

#include "Adafruit_NeoPixel.h"

Adafruit_NeoPixel pixelsScore = Adafruit_NeoPixel(LEDS_SCORE, PIN_PIXELS_SCORE, NEO_RGB + NEO_KHZ400);
Adafruit_NeoPixel pixelsAmbiance = Adafruit_NeoPixel(LEDS_AMBIANCE_TOTAL, PIN_LEDS_AMBIANCE, NEO_GRB + NEO_KHZ800);

int scoreBlue = 0;
int scoreRed = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_RESET, INPUT_PULLUP);

  pixelsScore.begin();
  pixelsAmbiance.begin();
  clearAllPixels();
}

void loop() {
  handleButtonPress(BUTTON_BLUE, &scoreBlue, COLOR_BLUE);
  handleButtonPress(BUTTON_RED, &scoreRed, COLOR_RED);
  ifResetButtonPressed();
}

void handleButtonPress(int buttonPin, int* score, uint32_t color) {
  if (digitalRead(buttonPin) == LOW) {
    delay(10); // Debounce
    if (digitalRead(buttonPin) == LOW) { // Check again to confirm button press
      *score += 1;
      updateScoreDisplay(*score, color);
      illuminateAmbiance(color);
      if (*score >= LEDS_SCORE) {
        endGame(color);
      }
    }
  }
}

void updateScoreDisplay(int score, uint32_t color) {
  for (int i = 0; i < score; ++i) {
    pixelsScore.setPixelColor(i, color);
  }
  pixelsScore.show();
}

void illuminateAmbiance(uint32_t color) {
  for (int i = 0; i < LEDS_AMBIANCE_TOTAL; ++i) {
    pixelsAmbiance.setPixelColor(i, color);
  }
  pixelsAmbiance.show();
  delay(1000); // Brief illumination
}

void endGame(uint32_t winnerColor) {
  illuminateAmbiance(winnerColor);
  delay(20000); // Celebration time
  clearAllPixels();
  resetScores();
}

void ifResetButtonPressed() {
  if (digitalRead(BUTTON_RESET) == LOW) {
    delay(10); // Debounce
    if (digitalRead(BUTTON_RESET) == LOW) { // Check again to confirm button press
      clearAllPixels();
      resetScores();
    }
  }
}

void clearAllPixels() {
  pixelsScore.clear();
  pixelsAmbiance.clear();
  pixelsScore.show();
  pixelsAmbiance.show();
}

void resetScores() {
  scoreBlue = 0;
  scoreRed = 0;
}
