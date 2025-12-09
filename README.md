# POO2 - TP Apache

Description
-----------
Ce dépôt contient le rendu du TP « Apache » réalisé par le trinôme B01 :
- Jad AMMYDRISS
- Ayman EL HABI
- Mohammed ESSAKI

La version fournie inclut le code source, un makefile pour la compilation, un ensemble de tests et une page de manuel située à la racine.

Ressources importantes
----------------------
- Makefile : situé dans le dossier `bin/`.
- Script de tests : `Tests/mktest.sh`.

Prérequis
---------
- Un compilateur C++ (ex. `g++`) et `make`.
- Sur Windows, utilisez WSL, MSYS2/MinGW ou un environnement similaire pour exécuter `make` et les scripts shell (`.sh`).

Compilation et nettoyage
------------------------
1. Ouvrez un terminal et placez-vous dans le dossier `bin` :

	`cd bin`

2. Pour compiler (Unix/WSL/MSYS) :

	`make`

3. Pour nettoyer les fichiers compilés :

	`make clean`

Si vous n'utilisez pas `make`, compilez manuellement les sources dans `bin/` avec `g++` (ex. `g++ -std=c++17 -O2 -o monprog *.cpp`).

Exécution des tests
-------------------
- Depuis le répertoire racine du dépôt, vous pouvez exécuter la suite de tests fournie :

  `cd Tests && ./mktest.sh`

  (Ces scripts sont des scripts shell — exécutez-les dans WSL/MSYS ou adaptez-les pour PowerShell si nécessaire.)

Structure du dépôt (extrait)
---------------------------
- `bin/` : code source C++ et `makefile`.
- `Tests/` : jeux de tests et scripts d'exécution.
- `LogDeTests/` : historiques ou sorties de tests.
- `manpage` : page de manuel exécutable via `man ./manpage`.

Licence / Auteurs
------------------
Travail réalisé par le trinôme B01 — voir les auteurs listés en début de fichier.
