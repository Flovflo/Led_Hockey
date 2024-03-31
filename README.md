# Led_Hockey

![image](https://user-images.githubusercontent.com/86321847/213888512-53646fa7-e285-4380-ad86-6d5ee656bbc5.png)

### Carte
 - S2 mini

### Exemple : si un joueur bleu a 3 points et un joueur rouge 2 points, voici ce qui se passe selon le code que nous avons élaboré :

Affichage des Scores : Les LEDs de score afficheront la situation des points en utilisant les couleurs spécifiées pour chaque joueur. Avec 3 points pour le joueur bleu et 2 points pour le joueur rouge, les LEDs s'allumeront comme suit :   
Les trois premières LEDs (en partant de la gauche) s'allumeront en bleu pour représenter les 3 points du joueur bleu.   
Les deux dernières LEDs (en partant de la droite) s'allumeront en rouge pour représenter les 2 points du joueur rouge.   
Les LEDs restantes (au milieu dans ce cas) resteront éteintes (X), représentant l'absence de points.   
Le résultat sur le strip de LEDs de score sera : B B B X X R R    
Animation lors d'un Point Marqué : Chaque fois qu'un joueur marque un point, une animation de "flash" rapide est déclenchée sur les LEDs d'ambiance dans la couleur du joueur qui a marqué. Cela signifie que, juste après le moment où le joueur bleu marque son troisième point (ou le joueur rouge son deuxième), les LEDs d'ambiance s'illuminent brièvement dans la couleur correspondante (bleu pour le joueur bleu, rouge pour le joueur rouge) avant de revenir à l'état éteint.   
Déroulement du Jeu : Le jeu continue jusqu'à ce qu'un total de 7 tours soit atteint (comme indiqué par la variable rounds). Si les joueurs continuent à marquer, les animations de score et les animations d'ambiance se déclencheront en conséquence à chaque point marqué.   
Fin de Partie et Déclaration du Gagnant : Une fois que le total des points marqués atteint 7 (c'est-à-dire que la somme des points du joueur bleu et du joueur rouge égale 7), le jeu procède à déterminer le gagnant en comparant les scores. Si le joueur bleu ou rouge a plus de points, une animation "respirante" se déclenchera sur les LEDs d'ambiance dans la couleur du gagnant pour célébrer sa victoire.     
Dans notre exemple en cours, si le jeu se termine avec le joueur bleu ayant plus de points que le joueur rouge, les LEDs d'ambiance s'illumineront avec une animation "respirante" en bleu.     
Réinitialisation du Jeu : Après la célébration du gagnant, le jeu peut être réinitialisé en appuyant sur le bouton de réinitialisation, éteignant toutes les LEDs et remettant à zéro les compteurs de points pour commencer une nouvelle partie.     
