# 42_FDF

Projet réalisé dans le cadre du cursus 42, **FDF** est un mini-projet graphique qui consiste à lire un fichier de points en 3D et à en réaliser une projection fil de fer en 2D, permettant d'afficher des paysages en relief (fil de fer = "fil de fer", d'où le nom FDF).

## 🏗️ Objectif du projet

- Lire et parser un fichier de points contenant des coordonnées en 3D (x, y, z).
- Représenter graphiquement ces points selon une projection isométrique ou parallèle.
- Afficher le résultat dans une fenêtre graphique, avec possibilité de navigation (zoom, déplacement, rotation…).

## 📦 Fonctionnalités

- Lecture et validation de fichiers de données 3D.
- Affichage en fil de fer de la carte 3D.
- Gestion des couleurs selon la hauteur (z).
- Contrôles clavier pour interagir avec la carte (zoom, translation, rotation).
- Utilisation de la minilibX (MiniLibX) pour la gestion graphique.

## 🖥️ Dépendances

- **MinilibX** (fourni par 42)
- **gcc** / **clang**
- Système UNIX (Linux ou macOS recommandé)

## 🚀 Compilation

Clonez le dépôt et compilez-le avec Make :

```bash
git clone https://github.com/Thomasrbm/42_FDF.git
cd 42_FDF
make
```

## 🕹️ Utilisation

Lancez le programme avec un fichier de carte en argument :

```bash
./fdf <carte.fdf>
```

## 🎮 Contrôles clavier (exemple)

- **Flèches** : déplacer la carte
- **+ / -** : zoomer/dézoomer
- **A / D** : rotation gauche/droite
- **W / S** : rotation haut/bas
- **ESC** : quitter

## 📁 Exemple de fichier `.fdf`

```
0 0 0 0 0
0 1 2 1 0
0 2 4 2 0
0 1 2 1 0
0 0 0 0 0
```

Chaque nombre représente la hauteur (z) du point.

## 📝 Auteurs

- [Thomasrbm](https://github.com/Thomasrbm)

## 📚 Ressources

- [Sujet officiel du projet FDF](https://github.com/42Paris/42cursus/tree/master/fdf)
- [Documentation MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)

---

> Projet réalisé dans le cadre de l'école 42.
