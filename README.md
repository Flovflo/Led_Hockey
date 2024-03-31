# Led_Hockey

### Carte
 - S2 mini

### Connexions

1. **Bande de LEDs "Score"** :
   - **Data Pin** : Connectez le fil de données de votre première bande de LEDs au **Pin 5** de l'Arduino.
   - **Alimentation** : Connectez le VCC de la bande de LEDs à une source d'alimentation 5V et le GND au GND de l'Arduino et de la source d'alimentation.

2. **Bande de LEDs "Ambiance"** :
   - **Data Pin** : Connectez le fil de données de votre deuxième bande de LEDs au **Pin 18** (pour les modèles compatibles, sinon utilisez un autre pin disponible).
   - **Alimentation** : Identique à la bande de LEDs "Score".

3. **Boutons** :
   - **Bouton Bleu** : Connectez une borne du bouton au **Pin 2**, et l'autre borne au GND. Vous pouvez ajouter une résistance de 10kΩ entre le Pin 2 et le VCC pour une meilleure stabilité (pull-up externe), bien que l'exemple utilise une résistance pull-up interne.
   - **Bouton Rouge** : Connectez une borne du bouton au **Pin 15**, et l'autre au GND, avec une option de résistance pull-up comme ci-dessus.
   - **Bouton Reset** : Connectez une borne du bouton au **Pin 4**, et l'autre au GND, avec une option de résistance pull-up comme ci-dessus.

### Avant le début de la partie :
- Les scores des joueurs sont à 0.
- Les LEDs de score et d'ambiance sont éteintes, ce qui est établi par la fonction `resetGame()` appelée dans `setup()`.
- Les boutons des joueurs (bleu et rouge) ainsi que le bouton de réinitialisation sont configurés avec des résistances de tirage internes activées (mode `INPUT_PULLUP`), ce qui signifie qu'ils lisent `HIGH` lorsqu'ils ne sont pas pressés et `LOW` lorsqu'ils sont pressés.

### Pendant la partie :
- Lorsqu'un joueur marque un point, il appuie sur son bouton correspondant (bleu ou rouge). Le programme détecte cet appui grâce à la vérification dans la boucle principale (`loop()`), et après un délai pour éviter les rebonds (bounce) du bouton, la fonction `scorePoint(char player)` est appelée avec le joueur correspondant.
  - Cette fonction incrémente le score du joueur concerné, met à jour l'affichage des LEDs de score en conséquence (bleues pour le joueur bleu à partir de la gauche, rouges pour le joueur rouge à partir de la droite), et vérifie si la fin de la partie est atteinte (c'est-à-dire si le total des points marqués atteint le nombre de rounds prévu).
- Immédiatement après l'enregistrement d'un point, une animation flash rapide est déclenchée sur les LEDs d'ambiance dans la couleur du joueur ayant marqué le point grâce à la fonction `flashAnimation(CRGB color)`.

### Fin de la partie :
- La partie se termine lorsque le total des points marqués par les deux joueurs atteint 7 (le nombre de rounds prévu).
- À ce moment, la fonction `declareWinner()` est appelée pour déterminer le gagnant (le joueur avec le plus grand nombre de points) et déclencher une animation de respiration (`breatheAnimation(CRGB color)`) sur les LEDs d'ambiance dans la couleur du gagnant.
- L'animation de respiration s'effectue par un éclaircissement et un assombrissement progressifs de la couleur du gagnant, créant un effet visuel attractif pour célébrer la victoire.
- Après l'animation du gagnant, la fonction `declareWinner()` pourrait être appelée pour réinitialiser les scores et les LEDs, prêtes pour une nouvelle partie. 

### À tout moment :
- Le bouton de réinitialisation peut être utilisé pour remettre à zéro les scores et éteindre les LEDs, préparant ainsi l'aire de jeu pour une nouvelle partie.



