#include <Arduino.h>
#include <FastLED.h>

// Configuration des pins et des LEDs
#define LEDS_SCORE 7
#define PIN_PIXELS_SCORE 5
#define LEDS_AMBIANCE_TOTAL 10
#define PIN_LEDS_AMBIANCE 18
#define BTN_BLUE 2
#define BTN_RED 15
#define BTN_RESET 4
#define BRIGHTNESS 50

CRGB leds_score[LEDS_SCORE];
CRGB leds_ambiance[LEDS_AMBIANCE_TOTAL];

int scoreBlue = 0; // Nombre de points du joueur bleu
int scoreRed = 0;  // Nombre de points du joueur rouge
const int rounds = 7; // Nombre total de tours

// Prototypes des fonctions
void resetGame();
void scorePoint(char player);
void flashAnimation(CRGB color);
void declareWinner();
void breatheAnimation(CRGB color);

void setup() {
  FastLED.addLeds<WS2811, PIN_PIXELS_SCORE, RGB>(leds_score, LEDS_SCORE).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, PIN_LEDS_AMBIANCE, GRB>(leds_ambiance, LEDS_AMBIANCE_TOTAL).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(BTN_BLUE, INPUT_PULLUP);
  pinMode(BTN_RED, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);
  resetGame();
}

void loop() {
  static unsigned long lastDebounceTime = 0;  // Dernier temps où un bouton a été pressé
  unsigned long debounceDelay = 500;  // Délai pour filtrer les rebonds

  if (!digitalRead(BTN_BLUE) && (millis() - lastDebounceTime > debounceDelay)) {
    scorePoint('B');
    flashAnimation(CRGB::Blue);
    lastDebounceTime = millis();
  } else if (!digitalRead(BTN_RED) && (millis() - lastDebounceTime > debounceDelay)) {
    scorePoint('R');
    flashAnimation(CRGB::Red);
    lastDebounceTime = millis();
  } else if (!digitalRead(BTN_RESET) && (millis() - lastDebounceTime > debounceDelay)) {
    resetGame();
    lastDebounceTime = millis();
  }
}

void scorePoint(char player) {
  if (player == 'B' && scoreBlue + scoreRed < rounds) {
    leds_score[scoreBlue] = CRGB::Blue;
    scoreBlue++;
  } else if (player == 'R' && scoreBlue + scoreRed < rounds) {
    leds_score[LEDS_SCORE - 1 - scoreRed] = CRGB::Red;
    scoreRed++;
  }
  FastLED.show();
  
  if (scoreBlue + scoreRed == rounds) {
    declareWinner();
  }
}

void declareWinner() {
  CRGB color = (scoreBlue > scoreRed) ? CRGB::Blue : CRGB::Red;
  breatheAnimation(color);
  // Remarque : retiré l'appel à resetGame ici pour permettre l'animation de respirer à finir
}

void flashAnimation(CRGB color) {
  fill_solid(leds_ambiance, LEDS_AMBIANCE_TOTAL, color);
  FastLED.show();
  delay(100);
  fill_solid(leds_ambiance, LEDS_AMBIANCE_TOTAL, CRGB::Black);
  FastLED.show();
}

void breatheAnimation(CRGB color) {
  for (int brightness = 0; brightness <= 255; brightness += 5) { // Incrément augmenté pour accélérer l'animation
    fill_solid(leds_ambiance, LEDS_AMBIANCE_TOTAL, color);
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(10);
  }
  for (int brightness = 255; brightness >= 0; brightness -= 5) { // Incrément augmenté pour accélérer l'animation
    fill_solid(leds_ambiance, LEDS_AMBIANCE_TOTAL, color);
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(10);
  }
  FastLED.setBrightness(BRIGHTNESS); // Reset à la luminosité par défaut
}

void resetGame() {
  fill_solid(leds_score, LEDS_SCORE, CRGB::Black);
  fill_solid(leds_ambiance, LEDS_AMBIANCE_TOTAL, CRGB::Black);
  FastLED.show();
  scoreBlue = 0;
  scoreRed = 0;
}
