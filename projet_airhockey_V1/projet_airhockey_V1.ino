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

// Création des objets NeoPixel pour les scores et l'ambiance
Adafruit_NeoPixel pixelsScore = Adafruit_NeoPixel(LEDS_SCORE, PIN_PIXELS_SCORE, NEO_RGB + NEO_KHZ400);
Adafruit_NeoPixel pixelsAmbiance = Adafruit_NeoPixel(LEDS_AMBIANCE_TOTAL, PIN_LEDS_AMBIANCE, NEO_GRB + NEO_KHZ800);

// Variables pour stocker les scores
int scoreBlue = 0;
int scoreRed = 0;

// Variable pour le délai non bloquant
unsigned long previousMillis = 0;
const long interval = 1000; // Intervalle de 1 seconde

void setup() {
  Serial.begin(9600);  
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_RESET, INPUT_PULLUP);

  // Initialisation des bandes de LEDs
  pixelsScore.begin();
  pixelsAmbiance.begin();
  clearAllPixels();
}

void loop() {
  // Gestion des appuis sur les boutons
  handleButtonPress(BUTTON_BLUE, &scoreBlue, COLOR_BLUE);
  handleButtonPress(BUTTON_RED, &scoreRed, COLOR_RED);

  // Vérification de l'appui sur le bouton de réinitialisation
  ifResetButtonPressed();

  // Gestion du délai non bloquant pour l'illumination
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // Mettre ici les actions à effectuer après l'expiration du délai
    previousMillis = currentMillis;
  }
}

// Fonction pour gérer les appuis sur les boutons
void handleButtonPress(int buttonPin, int* score, uint32_t color) {
  if (digitalRead(buttonPin) == LOW) {
    delay(10); // Debounce
    if (digitalRead(buttonPin) == LOW) {
      *score += 1;
      updateScoreDisplay(*score, color);
      illuminateAmbiance(color);
      if (*score >= LEDS_SCORE) {
        endGame(color);
      }
    }
  }
}

// Met à jour l'affichage des scores sur les LEDs
void updateScoreDisplay(int score, uint32_t color) {
  for (int i = 0; i < score; ++i) {
    pixelsScore.setPixelColor(i, color);
  }
  pixelsScore.show();
}

// Illumine les LEDs d'ambiance
void illuminateAmbiance(uint32_t color) {
  for (int i = 0; i < LEDS_AMBIANCE_TOTAL; ++i) {
    pixelsAmbiance.setPixelColor(i, color);
  }
  pixelsAmbiance.show();
  // Pas de delay ici pour éviter de bloquer le programme
}

// Fonction appelée à la fin du jeu
void endGame(uint32_t winnerColor) {
  illuminateAmbiance(winnerColor);
  // Pas de delay ici, utilisez la logique non bloquante si nécessaire
  clearAllPixels();
  resetScores();
}

// Vérifie si le bouton de réinitialisation est appuyé
void ifResetButtonPressed() {
  if (digitalRead(BUTTON_RESET) == LOW) {
    delay(10); // Debounce
    if (digitalRead(BUTTON_RESET) == LOW) {
      clearAllPixels();
      resetScores();
    }
  }
}

// Éteint toutes les LEDs
void clearAllPixels() {
  pixelsScore.clear();
  pixelsAmbiance.clear();
  pixelsScore.show();
  pixelsAmbiance.show();
}

// Réinitialise les scores
void resetScores() {
  scoreBlue = 0;
  scoreRed = 0;
}
