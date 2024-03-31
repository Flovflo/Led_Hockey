# Led_Hockey

### Carte
 - S2 mini

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
- Après l'animation du gagnant, la fonction `resetGame()` pourrait être appelée pour réinitialiser les scores et les LEDs, prêtes pour une nouvelle partie. Cependant, dans la dernière version du code que j'ai fournie, l'appel à `resetGame()` a été retiré de `declareWinner()` pour permettre à l'animation de se terminer. Vous pourriez vouloir ajouter un mécanisme (comme un bouton de réinitialisation ou un délai) pour réinitialiser le jeu après la célébration du gagnant.

### À tout moment :
- Le bouton de réinitialisation peut être utilisé pour remettre à zéro les scores et éteindre les LEDs, préparant ainsi l'aire de jeu pour une nouvelle partie.



