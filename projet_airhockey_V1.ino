#define BUTTON_BLUE 2
#define BUTTON_RED 4
#define BUTTON_RESET 3

#define PIXELS_SCORE 11
#define LEDS_SCORE 50

#define PIXELS_AMBIANCE 10
#define LEDS_AMBIANCE 50

#include "Adafruit_NeoPixel.h"

//setup led score
Adafruit_NeoPixel pixelsScore = Adafruit_NeoPixel(LEDS_SCORE, PIXELS_SCORE, NEO_RGB + NEO_KHZ400);
//setup led ambiance
Adafruit_NeoPixel stripLED = Adafruit_NeoPixel(LEDS_AMBIANCE, PIXELS_AMBIANCE, NEO_GRB + NEO_KHZ800);

//variable globale
int NB_BUT=0;
int SCORE_BLUE=0;
int SCORE_RED=0;

void setup() 
{
Serial.begin(9600);  
pinMode(BUTTON_BLUE, INPUT_PULLUP);
pinMode(BUTTON_RED, INPUT_PULLUP);
pinMode(BUTTON_RESET, INPUT_PULLUP);
  
pixelsScore.begin();
pixelsAmbiance.begin();

  // Éteindre tous les pixels
  pixelsScore.clear();
  pixelsAmbiance.clear();
  pixelsScore.show();
  pixelsAmbiance.show();
}

void loop() 
  {  
    // Exécuter la fonction JOUEUR_BLUE
    JOUEUR_BLUE();
    // Exécuter la fonction JOUEUR_RED
    JOUEUR_BLUE();
  }

void ALLUMER_AMBIANCE_RED() 
  {
    // Allumer les 50 premiers pixels en rouge
    for (int i = 0; i < LEDS_AMBIANCE; i++) {
      pixels.setPixelColor(i, 255, 0, 0); //red
    }
    // Mettre à jour les pixels
    pixels.show();
  }

void ALLUMER_AMBIANCE_BLUE() 
  {
    // Allumer les 50 premiers pixels en rouge
    for (int i = 0; i < LEDS_AMBIANCE; i++) {
      pixels.setPixelColor(i,  0, 0, 255); //blue
    }
    // Mettre à jour les pixels
    pixels.show();
  }

void ALLUMER_AMBIANCE_NORMAL() {
  // Allumer les 50 premiers pixels en rouge
  for (int i = 0; i < 50; i++) {
    pixels.setPixelColor(i, 255, 0, 0);
  }
  // Allumer les 50 derniers pixels en bleu
  for (int i = 50; i < 100; i++) {
    pixels.setPixelColor(i, 0, 0, 255);
  }
  // Mettre à jour les pixels
  pixels.show();
}
void JOUEUR_BLUE() 
{
  if(digitalRead(BUTTON_BLUE)==LOW)
          {
          SCORE_BLUE=SCORE_BLUE+1;
          NB_BUT=NB_BUT+1;
                Serial.println(NB_BUT);
                Serial.println(SCORE_BLUE);
                switch (NB_BUT)
                   {
                      case 1: //Si NB_BUT vaut 1
                      pixelsScore.setPixelColor(1, 0, 0, 255); //Bleu
                      pixelsScore.show(); //met à jour le bandeau de pixels en utilisant la fonction show
                      ALLUMER_AMBIANCE_BLUE();
                      delay(5000);
                      ALLUMER_AMBIANCE_NORMAL();
                      delay(1000);//attente de 1s
                      break; 
                  
                      case 2: 
                      pixelsScore.setPixelColor(2, 0, 0, 255); 
                      pixelsScore.show(); 
                      delay(1000);
                      break;
                  
                      case 3: 
                      pixelsScore.setPixelColor(3, 0, 0, 255); 
                      pixelsScore.show(); 
                      delay(1000);
                      break;  
        
                      case 4: 
                      pixelsScore.setPixelColor(4, 0, 0, 255); 
                      pixelsScore.show(); 
                      delay(1000);
                      break; 
        
                      case 5: 
                      pixelsScore.setPixelColor(5, 0, 0, 255); 
                      pixelsScore.show(); 
                      delay(1000);
                      break; 
        
                      case 6: 
                      pixelsScore.setPixelColor(6, 0, 0, 255); 
                      pixelsScore.show(); 
                      delay(1000);
                      break;
        
                      case 7: 
                      pixelsScore.setPixelColor(7, 0, 0, 255); 
                      pixelsScore.show(); 
                      delay(1000);
                        if ( SCORE_BLUE > SCORE_RED) { // si SCORE_BLUE est plus grand que SCORE_RED
                          ALLUMER_AMBIANCE_BLUE();
                        }
                        // Sinon
                        else {
                          ALLUMER_AMBIANCE_RED();
                        }
                    }
                      break;
                      
                    }
               }
                
          }
 }
 
