# Led_Hockey

![image](https://user-images.githubusercontent.com/86321847/213888512-53646fa7-e285-4380-ad86-6d5ee656bbc5.png)

### Carte
 - S2 mini

### Configuration de Base
- **esphome**: Définit les paramètres de base du microcontrôleur, comme le nom et le type de la carte.
- **wifi**: Configure la connexion Wi-Fi de l'ESP32-S2 Mini.
- **logger**, **api**, **ota**: Active le logging pour le débogage, l'API pour la communication avec Home Assistant (même si nous n'utilisons pas Home Assistant pour ce projet), et les mises à jour OTA pour faciliter le téléversement de nouvelles versions du firmware sans câble.

### Gestion des LEDs NeoPixel
- **light**: Configure deux bandes de LEDs NeoPixel. Une pour le score (`pixels_score`) et une pour l'ambiance (`pixels_ambiance`), en spécifiant le type, le pin de connexion, et le nombre de LEDs.

### Boutons
- **binary_sensor**: Déclare trois boutons comme capteurs binaires, chacun configuré avec un pin spécifique. Des scripts sont exécutés lors de l'appui sur ces boutons pour augmenter le score ou réinitialiser le jeu.

### Scripts
- **globals**: Définit deux variables globales (`score_blue` et `score_red`) pour tenir compte des scores.
- **script**: Contient les scripts qui sont exécutés en réponse à l'appui sur les boutons. Ces scripts gèrent l'augmentation des scores, la mise à jour de l'affichage des scores sur les LEDs, la réinitialisation des scores et de l'affichage, et l'illumination de l'ambiance en fin de jeu. Chaque script utilise des instructions `lambda` pour exécuter du code C++ personnalisé, permettant de manipuler les scores et les états des LEDs directement.

### Fonctionnement du Jeu
- **Augmentation des Scores**: Lorsqu'un joueur appuie sur son bouton (bleu ou rouge), le script correspondant (`increment_score_blue` ou `increment_score_red`) est exécuté. Si le score est inférieur à 7, il est augmenté et le LED correspondant sur la bande de score est illuminé dans la couleur appropriée.
- **Fin de Jeu**: Si un joueur atteint un score de 7, un script de fin de jeu (`end_game_blue` ou `end_game_red`) illumine toutes les LEDs de la bande d'ambiance dans la couleur du joueur gagnant.
- **Réinitialisation du Jeu**: L'appui sur le bouton de réinitialisation exécute le script `reset_game`, qui remet les scores à zéro et éteint toutes les LEDs.

### Si besoins
- **Condensateur** : Un condensateur de 1000 µF, 6.3V ou plus, entre le Vcc et le GND de la bande de LEDs peut aider à prévenir les pics de tension lors de l'allumage des LEDs.
- **Résistance en Série** : Une résistance de 330Ω ou 470Ω sur la ligne de données des LEDs peut aider à réduire le bruit sur cette ligne.
