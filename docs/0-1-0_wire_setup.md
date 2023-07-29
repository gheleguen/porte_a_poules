
# 2/Montage électronique
**Version 0.1.0**
<br><br>
## 2.1 Introduction
La version 0.1.0 est la première version à être installé sur un poulailler. Le test a été effectué en été 2023 en Bretagne à Trégunc. 

### 2.1.1 Principe de fonctionnement
Le boitier ici présent permet d'enrouler et de dérouler une corde autour d'un tambour. Ce qui dans notre cas par un jeu de poulie, permet de lever et descendre la porte d'us poulailler. 

L'utilisateur en agissant sur les trois potentiomètres peut modifier chacun de ces trois paramètres sans intervenir sur le programme : 
 - L'heure minimum d'ouverture, 
 - L'heure minimum de fermeture,
 - Le seuil de luminosité pour le déclenchement, 

Une horloge RTC, permet de conserver l'heure et la date même hors tentions. De cette manière le système connaît l'heure réel et la date. 
Une module (lecture écriture) de carte SD permet d'écrire sur un fichier .txt des données tel que les paramètres donnés par l'utilisateur, et les heures de déclenchements de la porte. Ce fichier a pour unique vocation de simplifier le débogage.

Une photo-résistance permet de mesurer la quantité de lumière ambiante. C'est cette donnée qui sert à définir le moment où s'ouvrira ou se fermera la porte.  

Les deux boutons poussoirs ou plutôt les deux fins de courses permettent au système d'avoir l'information de la position de la porte et ainsi arrêter le moteur lorsque la porte est abaissé ou ouverte. 

Dans cette version, on utilise une batterie 6v au plomb. Elle est chargé via un panneau solaire 12v et un abaisseur de tension. Le circuit d'alimentation est détaillé dans une autre partie de ce tutoriel.

Un interrupteur disposé sur le coté permettra d'ouvrir ou fermer l'alimentation du système. 
 
### 2.1.2 Recommandations
Le circuit détaillé ci-dessous est à réaliser en veillant à garder des longueurs de câbles suffisantes. Il est également recommandé d'utiliser un kit de connecteurs duponts pour faciliter les branchements. 

Par ailleur bien consulter les autres partie du tutoriel et particulièrement la partie traitant de l'intégration. En effet la longueur des câbles nécessaires dépendra de la disposition des différents éléments dans le boitier étanche. 

</br></br> 
## 2.2 Réalisation
### 2.2.1 Câblage
Réaliser le circuit représenté ci dessous. Le fichier fritzing est disponible dans le dossier "hardware" du dépôt.

Souder sur la carte "adafruit proto shield" des résistances de tirage (symbolisés par des petits fils blanc sur le shèma reliant le 5v aux boutons poussoirs et la photo-résistance).

![DevMR2-3.jpg](pictures/MF3-1.jpg)

#### 3.1.2
 - Visser le réducteur du moteur sur le support au moyen de 3 vis M3 et de 3 écrous.
 - Insérer les 3 potentiomètres dans les supports en forçant. On prendra soin de placer le potentiomètre qui sert au réglage du seuil de luminosité sur la pointe. 
 - Visser le support de potentiomètres sur la droite, la carte arduino au centre et le contrôleur moteur à gauche. 
 - Visser le support de moteur en dessous du porte potentiomètres. 





</br></br>
## 2.3 Améliorations envisageables
 - Ajouter un écran LCD pour donner l'heure des dernières ouvertures, fermetures et valeur de lumière. 
 - Si la lecture de l'intensité lumineuse pose un problème, peut-être étudier des techniques de lissage de courbe tel qu'utiliser une moyenne glissante, [comme documenté ici](https://www.aranacorp.com/fr/implementation-de-la-moyenne-glissante-dans-arduino/#:~:text=Le%20principe%20de%20la%20moyenne,l'%C3%A9tablissement%20de%20la%20moyenne.).
