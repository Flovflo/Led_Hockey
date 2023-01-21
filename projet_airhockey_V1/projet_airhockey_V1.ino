#define BUTTON_BLUE 2
#define BUTTON_RED 7
#define BUTTON_RESET 4

#define PIN_PIXELS_SCORE 11
#define LEDS_SCORE 7

#define PIN_LEDS_AMBIANCE 8
#define LEDS_AMBIANCE_TOTAL 100

#define LEDS_AMBIANCE_BLUE 50
#define LEDS_AMBIANCE_RED 50

#include "Adafruit_NeoPixel.h"

//setup led score
Adafruit_NeoPixel pixelsScore = Adafruit_NeoPixel(LEDS_SCORE, PIN_PIXELS_SCORE, NEO_RGB + NEO_KHZ400);
//setup led ambiance
Adafruit_NeoPixel pixelsAmbiance = Adafruit_NeoPixel(LEDS_AMBIANCE_TOTAL, PIN_LEDS_AMBIANCE, NEO_GRB + NEO_KHZ800);

//variable globale
int NB_BUT=0;
int SCORE_BLUE=0;
int SCORE_RED=0;

void setup() 
{
Serial.begin(9600);  
//definir les bouttons en entrée et pullup
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
    JOUEUR_RED();
    // Exécuter la fonction du boutton reset
    IF_RESET_BOUTTON();

  }

void IF_RESET_BOUTTON() 
  {
    if(digitalRead(BUTTON_RESET)==LOW)
          {
            // Éteindre tous les pixels
              pixelsScore.clear();
              pixelsAmbiance.clear();
              pixelsScore.show();
              pixelsAmbiance.show();

              NB_BUT=0;
              SCORE_BLUE=0;
              SCORE_RED=0;
          }
  }

void RESET() 
  {
 // Éteindre tous les pixels
  pixelsScore.clear();
  pixelsAmbiance.clear();
  pixelsScore.show();
  pixelsAmbiance.show();

  NB_BUT=0;
  SCORE_BLUE=0;
  SCORE_RED=0;

  }

void ALLUMER_AMBIANCE_RED() 
  {
    //LEDS_AMBIANCE_TOTAL 
    for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
      pixels.setPixelColor(i, 255, 0, 0); //blue
    }
    // Mettre à jour les pixels
    pixels.show();
    delay(1000)
    for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
      pixels.setPixelColor(i, 255, 0, 0); //blue
    }
    // Mettre à jour les pixels
    pixels.show();
    delay(1000)
        for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
      pixels.setPixelColor(i, 255, 0, 0); //blue
    }
    // Mettre à jour les pixels
    pixels.show();
    delay(3000)
    ALLUMER_AMBIANCE_NORMAL();
  }

void ALLUMER_AMBIANCE_BLUE() 
  {
    //LEDS_AMBIANCE_TOTAL 
    for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
      pixels.setPixelColor(i,  0, 0, 255); //blue
    }
    // Mettre à jour les pixels
    pixels.show();
    delay(1000)
    for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
      pixels.setPixelColor(i,  0, 0, 0); //blue
    }
    // Mettre à jour les pixels
    pixels.show();
    delay(1000)
        for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
      pixels.setPixelColor(i,  0, 0, 255); //blue
    }
    // Mettre à jour les pixels
    pixels.show();
    delay(3000)
    ALLUMER_AMBIANCE_NORMAL();
  }

void ALLUMER_AMBIANCE_NORMAL() {
  // Allumer LEDS_AMBIANCE_RED  pixels en rouge
  for (int i = 0; i < LEDS_AMBIANCE_RED; i++) {
    pixels.setPixelColor(i, 255, 0, 0);
  }
  // Allumer LEDS_AMBIANCE_BLUE derniers pixels en bleu
  for (int i = LEDS_AMBIANCE_BLUE; i < 100; i++) {
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
            if (NB_BUT<7)
             {
                switch (SCORE_BLUE)
                   {
                      case 1: //Si SCORE_BLUE vaut 1
                      pixelsScore.setPixelColor(1, 0, 0, 255); //Bleu
                      pixelsScore.show(); //met à jour le bandeau de pixels en utilisant la fonction show
                      ALLUMER_AMBIANCE_BLUE();
                      delay(1000);//attente de 1s
                      break; 
                  
                      case 2: 
                      pixelsScore.setPixelColor(2, 0, 0, 255); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_BLUE();
                      delay(1000);
                      break;
                  
                      case 3: 
                      pixelsScore.setPixelColor(3, 0, 0, 255); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_BLUE();
                      delay(1000);
                      break;  
        
                      case 4: 
                      pixelsScore.setPixelColor(4, 0, 0, 255); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_BLUE();
                      delay(1000);
                      break; 
        
                      case 5: 
                      pixelsScore.setPixelColor(5, 0, 0, 255); 
                      pixelsScore.show();
                      ALLUMER_AMBIANCE_BLUE();
                      delay(1000);
                      break; 
        
                      case 6: 
                      pixelsScore.setPixelColor(6, 0, 0, 255); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_BLUE();
                      delay(1000);
                      break;
        
                      case 7: 
                      pixelsScore.setPixelColor(7, 0, 0, 255); 
                      pixelsScore.show();
                      ALLUMER_AMBIANCE_BLUE(); 
                      delay(1000);
                      
                    }
          } 
          else 
          {
            if ( SCORE_BLUE > SCORE_RED) { // si SCORE_BLUE est plus grand que SCORE_RED
                          for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
                            pixels.setPixelColor(i,  0, 0, 255); //blue
                          }
                          // Mettre à jour les pixels
                          pixels.show();
                          delay(20000);
                        }
                        // Sinon
                        else {
                          for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
                            pixels.setPixelColor(i,  255, 0, 0); //red
                          }
                          // Mettre à jour les pixels
                          pixels.show();
                          delay(20000);
                        }
                        RESET();
          }
                      break;
                      
        }
 }

 //la meme focntion pour le joueur rouge
void JOUEUR_RED()
{
  if(digitalRead(BUTTON_RED)==LOW)
          {
          SCORE_RED=SCORE_RED+1;
          NB_BUT=NB_BUT+1;
                Serial.println(NB_BUT);
                Serial.println(SCORE_RED);
            if (NB_BUT<7)
             {
                switch (SCORE_RED)
                   {
                      case 1: //Si SCORE_RED vaut 1
                      pixelsScore.setPixelColor(1, 255, 0, 0); //Rouge
                      pixelsScore.show(); //met à jour le bandeau de pixels en utilisant la fonction show
                      ALLUMER_AMBIANCE_RED();
                      delay(1000);//attente de 1s
                      break; 
                  
                      case 2: 
                      pixelsScore.setPixelColor(2, 255, 0, 0); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_RED();
                      delay(1000);
                      break;
                  
                      case 3: 
                      pixelsScore.setPixelColor(3, 255, 0, 0); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_RED();
                      delay(1000);
                      break;  
        
                      case 4: 
                      pixelsScore.setPixelColor(4, 255, 0, 0); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_RED();
                      delay(1000);
                      break; 
        
                      case 5: 
                      pixelsScore.setPixelColor(5, 255, 0, 0); 
                      pixelsScore.show();
                      ALLUMER_AMBIANCE_RED();
                      delay(1000);
                      break; 
        
                      case 6: 
                      pixelsScore.setPixelColor(6, 255, 0, 0); 
                      pixelsScore.show(); 
                      ALLUMER_AMBIANCE_RED();
                      delay(1000);
                      break;
        
                      case 7: 
                      pixelsScore.setPixelColor(7, 255, 0, 0); 
                      pixelsScore.show();
                      ALLUMER_AMBIANCE_RED(); 
                      delay(1000);
                      
                    }
          } 
          else 
          {
            if ( SCORE_RED > SCORE_BLUE) { // si SCORE_RED est plus grand que SCORE_BLUE
                          for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
                            pixels.setPixelColor(i,  255, 0, 0); //red
                          }
                          // Mettre à jour les pixels
                          pixels.show();
                          delay(20000);
                        }
                        // Sinon
                        else {
                          for (int i = 0; i < LEDS_AMBIANCE_TOTAL; i++) {
                            pixels.setPixelColor(i,  0, 0, 255); //blue
                          }
                          // Mettre à jour les pixels
                          pixels.show();
                          delay(20000);
                        }
                        RESET();
          }
         break;

        }
}


