<div align="center">

# FDF — Fil de Fer

**Moteur de rendu 3D fil de fer à partir de cartes d'élévation, écrit en C avec MiniLibX.**

[![42](https://img.shields.io/badge/École-42-000000?style=flat-square&logo=42&logoColor=white)](https://42.fr/)
[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-42-success?style=flat-square)](https://github.com/42School/norminette)
[![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?style=flat-square&logo=linux&logoColor=black)](https://www.kernel.org/)
[![Build](https://img.shields.io/badge/Build-Makefile-427819?style=flat-square&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)

</div>

---

## Sommaire

- [Présentation](#présentation)
- [Aperçu technique](#aperçu-technique)
- [Architecture du projet](#architecture-du-projet)
- [Prérequis](#prérequis)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Contrôles](#contrôles)
- [Format des cartes `.fdf`](#format-des-cartes-fdf)
- [Cartes de test fournies](#cartes-de-test-fournies)
- [Détails d'implémentation](#détails-dimplémentation)
- [Performance](#performance)
- [Auteur](#auteur)
- [Licence & Ressources](#licence--ressources)

---

## Présentation

**FDF** *(Fil de Fer)* est un projet graphique du cursus 42 dont l'objectif est de représenter en *wireframe* une carte d'élévation 3D, à partir d'un fichier texte décrivant une grille de points. Le programme lit, valide, projette et affiche la scène dans une fenêtre interactive, avec navigation temps-réel (zoom, translation, rotation sur les trois axes, changement de projection, palettes de couleurs).

Ce dépôt contient une implémentation complète, optimisée et conforme à la **norminette 42**, avec gestion robuste des erreurs, validation stricte des fichiers d'entrée, double-buffering et calculs de couleurs interpolées.

---

## Aperçu technique

| Caractéristique          | Détail                                                            |
| ------------------------ | ----------------------------------------------------------------- |
| **Langage**              | C (C99, conforme norme 42)                                        |
| **Bibliothèque graphique** | MiniLibX (X11)                                                  |
| **Résolution**           | 2000 × 1200 (configurable via `WINDOW_WIDTH` / `WINDOW_HEIGHT`)   |
| **Projections**          | Isométrique, parallèle (perspective approchée)                   |
| **Rotations**            | Matrices sur les axes X, Y, Z (radians)                          |
| **Tracé de lignes**      | Algorithme de Bresenham avec interpolation de couleurs           |
| **Rendu**                | Off-screen image buffer (anti-flickering)                        |
| **Parsing**              | Lecture ligne-à-ligne via `get_next_line`, support hexadécimal   |
| **Palettes**             | 3 palettes de gradients sélectionnables à chaud                  |

---

## Architecture du projet

```
FDF_42/
├── Makefile                    # Build system avec auto-clone libft & MiniLibX
├── Readme.md
├── fdf_dir/
│   ├── fdf.h                   # Header principal, structures & prototypes
│   ├── fdf.c                   # Initialisation MLX et données
│   ├── main.c                  # Point d'entrée
│   ├── draw/                   # Pipeline de rendu
│   │   ├── display.c
│   │   ├── draw_map.c          # Boucle principale de tracé
│   │   ├── draw_colors_line.c  # Bresenham + interpolation couleur
│   │   ├── draw_colors_point.c
│   │   ├── manage_colors.c     # Gestion des palettes
│   │   ├── projection.c        # Isométrique / parallèle
│   │   └── rotate.c            # Rotations 3D
│   ├── events/                 # Hooks clavier & souris
│   │   ├── events_mouse.c
│   │   └── events_utils.c
│   ├── parse/                  # Lecture & validation des cartes
│   │   ├── fill_map.c
│   │   ├── parse_allocate_map.c
│   │   ├── parse_utils.c
│   │   └── validate_format.c
│   └── gnl/                    # get_next_line
└── test_maps/                  # 30+ cartes de démonstration
```

---

## Prérequis

| Dépendance     | Rôle                                          | Installation (Debian/Ubuntu)                         |
| -------------- | --------------------------------------------- | ---------------------------------------------------- |
| `gcc` / `clang` | Compilation                                  | `sudo apt install build-essential`                   |
| `make`          | Build system                                 | `sudo apt install make`                              |
| **MiniLibX**    | Rendu graphique (X11)                        | *Cloné automatiquement par le Makefile*              |
| `libX11`, `libXext` | Backend X Window System                  | `sudo apt install libx11-dev libxext-dev`            |
| `libft`         | Bibliothèque standard 42 maison              | *Clonée automatiquement par le Makefile*             |

> **Note :** le `Makefile` télécharge et compile automatiquement la *libft* et la *MiniLibX*. Aucune installation manuelle n'est requise pour ces deux dépendances.

---

## Installation

```bash
# 1. Cloner le dépôt
git clone https://github.com/Thomasrbm/42_FDF.git
cd 42_FDF

# 2. Compiler
make

# 3. Lancer le programme
./fdf test_maps/42.fdf
```

### Cibles `make` disponibles

| Cible        | Effet                                                                 |
| ------------ | --------------------------------------------------------------------- |
| `make`       | Compile la *libft*, la *MiniLibX* puis l'exécutable `fdf`             |
| `make clean` | Supprime les objets, la *libft* et la *MiniLibX*                      |
| `make fclean`| `clean` + suppression de l'exécutable                                 |
| `make re`    | `fclean` puis recompilation complète                                  |
| `make clean_mlx` | Supprime uniquement la *MiniLibX*                                 |

> **Flags de compilation :** `-Wall -Wextra -Werror -O3 -march=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer`

---

## Utilisation

```bash
./fdf <chemin/vers/carte.fdf>
```

**Exemple :**

```bash
./fdf test_maps/pyramide.fdf
./fdf test_maps/france.XXL.fdf
./fdf test_maps/julia.fdf
```

Le programme retourne `EXIT_FAILURE` et affiche un message explicite sur `stderr` en cas de :

- nombre incorrect d'arguments,
- fichier introuvable ou non lisible,
- format invalide (largeur de ligne incohérente, caractère illégal, hexadécimal mal formé),
- échec d'allocation mémoire,
- échec d'initialisation de la MiniLibX.

---

## Contrôles

### Clavier

| Touche             | Action                                                   |
| ------------------ | -------------------------------------------------------- |
| `←` `↑` `→` `↓`    | Translation de la carte                                  |
| `+` / `-`          | Zoom avant / arrière                                     |
| `T` / `Y`          | Augmenter / diminuer l'amplitude du relief (axe Z)       |
| `W` / `S`          | Rotation sur l'axe X                                     |
| `A` / `D`          | Rotation sur l'axe Y                                     |
| `Q` / `E`          | Rotation sur l'axe Z                                     |
| `P`                | Basculer entre projection isométrique et parallèle       |
| `C`                | Activer / désactiver le dégradé de couleurs              |
| `V`                | Cycler entre les 3 palettes de couleurs                  |
| `ESC`              | Quitter                                                  |

### Souris

| Action                  | Effet                                  |
| ----------------------- | -------------------------------------- |
| Glisser (clic gauche)   | Translation de la carte                |
| Molette                 | Zoom centré sur le curseur             |

---

## Format des cartes `.fdf`

Chaque ligne contient une rangée de points séparés par des espaces. Chaque point peut être :

- un entier signé représentant l'élévation `z`,
- ou un entier suivi d'une couleur hexadécimale au format `z,0xRRGGBB`.

**Exemple minimal :**

```
0 0 0 0 0
0 1 2 1 0
0 2 4 2 0
0 1 2 1 0
0 0 0 0 0
```

**Exemple avec couleurs :**

```
0      0      0,0xFF0000  0      0
0      5,0x00FF00  10     5      0
0,0x0000FF 10    15     10     0
```

**Règles de validation :**

- toutes les lignes doivent avoir la même largeur,
- les valeurs `z` doivent être des entiers (positifs ou négatifs) dans `INT_MIN..INT_MAX`,
- la couleur, optionnelle, doit être un hexadécimal valide précédé de `0x` ou `0X`.

---

## Cartes de test fournies

Le dossier `test_maps/` contient plus de 30 cartes pour explorer les capacités du moteur :

- **Géométriques :** `pyramide.fdf`, `pyra.fdf`, `plat.fdf`, `pylone.fdf`, `42.fdf`
- **Reliefs :** `mars.fdf`, `france.XXL.fdf`, `Japan.L.fdf`, `world.fdf`
- **Fractales :** `julia.fdf`, `elem-fract.fdf`
- **Stress-tests :** `100x100.fdf`, `200x200.fdf`
- **Edge cases :** `empty.fdf`, `invalid_format.fdf`, `Zero.fdf`

---

## Détails d'implémentation

### Pipeline de rendu

1. **Parsing** — Lecture du fichier via `get_next_line`, calcul des dimensions, validation stricte ligne par ligne, allocation de la grille `int **grid` et de la grille couleur `int **color`.
2. **Calcul `min_z` / `max_z`** — utilisé pour normaliser le gradient de couleur en fonction de l'altitude.
3. **Transformations** — Pour chaque point : rotations 3D (X, Y, Z) → projection (isométrique ou parallèle) → translation par offset → mise à l'échelle (zoom).
4. **Tracé** — Algorithme de Bresenham vers le voisin droit et le voisin bas, avec interpolation linéaire de la couleur entre les deux extrémités.
5. **Affichage** — Écriture dans un *image buffer* MLX (off-screen), puis `mlx_put_image_to_window` en un seul appel pour éviter le flickering.

### Optimisations

- **Image buffer** plutôt que `mlx_pixel_put` (~100× plus rapide).
- **`needs_redraw` flag** — la scène n'est redessinée qu'en cas de changement effectif d'état, le `loop_hook` reste passif sinon.
- **Compilation `-O3 -march=native -flto`** avec auto-vectorisation et inlining agressif.

### Robustesse

- Tous les `malloc` sont contrôlés ; un échec déclenche `error_exit()` qui libère proprement la carte et termine le processus.
- La sortie via `close_window` ou la touche `ESC` libère l'image MLX, la fenêtre, le display, puis la carte.
- Vérification stricte de la cohérence des lignes (largeur identique sur toute la carte).

---

## Performance

Sur une machine standard *(i5 ~3 GHz, X11 sur Linux)* :

| Carte           | Dimensions  | Frame budget (redraw) |
| --------------- | ----------- | --------------------- |
| `pyramide.fdf`  | 11 × 11     | < 1 ms                |
| `42.fdf`        | ~40 × 40    | ~2 ms                 |
| `100x100.fdf`   | 100 × 100   | ~10 ms                |
| `france.XXL.fdf`| très grande | ~50–100 ms            |

Le `loop_hook` ne redessine que sur changement (`needs_redraw == 1`), ce qui maintient le programme à ~0 % CPU lorsqu'il est inactif.

---

## Auteur

**Thomas Robert** — [`throbert`](https://profile.intra.42.fr/users/throbert) chez 42 Paris

[![GitHub](https://img.shields.io/badge/GitHub-Thomasrbm-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/Thomasrbm)

---

## Licence & Ressources

Projet réalisé dans le cadre du **cursus 42**. Le code est libre de consultation à but pédagogique.

- [Sujet officiel FDF — 42 Paris](https://github.com/42Paris/42cursus/tree/master/fdf)
- [Documentation MiniLibX (Harm Smits)](https://harm-smits.github.io/42docs/libs/minilibx)
- [Algorithme de Bresenham](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
- [Projections isométriques](https://en.wikipedia.org/wiki/Isometric_projection)

<div align="center">

— *Made with ❤️ at* **[42](https://42.fr/)** —

</div>
