# Jeu du Pendu (Hangman)

Un jeu classique du pendu développé en C dans le cadre d'un projet EPITECH.

## Contexte : Le Stumper EPITECH

Ce projet a été réalisé dans le cadre d'une épreuve appelée "stumper", une évaluation barrage conditionnant le passage en deuxième année à EPITECH. Le stumper se caractérise par :

- Une durée limitée de 4 heures
- Une réalisation en mode TTY (terminal)
- Des règles strictes à respecter :
  - Respect des normes de codage EPITECH
  - Gestion rigoureuse des erreurs
  - Vérification systématique des valeurs de retour de toutes les fonctions de la libc
  - Absence de fuites mémoire
  - Performance et optimisation du code

Cette évaluation vise à tester notre capacité à produire rapidement un programme fonctionnel et propre sous contrainte de temps, tout en travaillant efficacement en binôme.

## Description

Le jeu du pendu est un jeu de devinettes où le joueur doit découvrir un mot caché en proposant des lettres. À chaque erreur, le joueur perd une tentative. Le jeu se termine soit par la découverte complète du mot (victoire), soit par l'épuisement de toutes les tentatives (défaite).

## Fonctionnalités

- Sélection aléatoire d'un mot à partir d'un fichier dictionnaire
- Interface simple en ligne de commande
- Possibilité de personnaliser le nombre de tentatives
- Affichage dynamique de l'état du mot à deviner
- Gestion des erreurs robuste

## Comment compiler

```bash
make
```

Cette commande génère l'exécutable `hangman`.

## Comment utiliser

```bash
./hangman <chemin_vers_dictionnaire> [nombre_de_tentatives]
```

### Arguments

- `<chemin_vers_dictionnaire>` : Chemin vers le fichier contenant les mots à deviner (obligatoire)
- `[nombre_de_tentatives]` : Nombre de tentatives accordées (facultatif, par défaut: 10)

### Exemple

```bash
./hangman file 5
```

Lance le jeu avec les mots du fichier `file` et 5 tentatives.

## Structure du projet

- `main.c` : Point d'entrée du programme, validation des arguments
- `src/dictionnary.c` : Gestion du dictionnaire et sélection aléatoire des mots
- `src/process_handman.c` : Logique principale du jeu
- `src/utils/linked_list.c` : Implémentation d'une liste chaînée pour stocker les mots
- `include/` : Fichiers d'en-tête et définitions des structures

## Nettoyage

```bash
# Supprime les fichiers objets
make clean

# Supprime les fichiers objets et l'exécutable
make fclean

# Nettoie et recompile le projet
make re
```

## Auteurs

- Amayyas Aouadene
- Maeva Arroniz
