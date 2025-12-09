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

4. Pour exécuter les tests automatiques :

	`make run`

Si vous n'utilisez pas `make`, compilez manuellement les sources dans `bin/` avec `g++` (ex. `g++ -std=c++17 -O2 -o monprog *.cpp`).

Exécution des tests
-------------------
Deux méthodes sont disponibles pour exécuter les tests automatiques :

### Méthode 1 : Via le Makefile (recommandé)
Depuis le dossier `bin/` :

```bash
make run
```

### Méthode 2 : Exécution directe
Depuis le répertoire racine du dépôt :

```bash
cd Tests && ./mktest.sh
```

(Ces scripts sont des scripts shell — exécutez-les dans WSL/MSYS ou adaptez-les pour PowerShell si nécessaire.)

Structure du dépôt (extrait)
---------------------------
- `bin/` : code source C++ et `makefile`.
- `Tests/` : jeux de tests et scripts d'exécution.
- `LogDeTests/` : fichiers de logs Apache de test (voir section ci-dessous).
- `manpage` : page de manuel exécutable via `man ./manpage`.

Dossier LogDeTests
------------------
Le dossier `LogDeTests/` contient des fichiers de logs Apache au format standard, utilisés comme données d'entrée pour tester le programme `analog`.

### Contenu
Chaque fichier `.log` contient des lignes au format Apache :
```
192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] "GET /docB.html HTTP/1.1" 200 12106 "/docA.html" "Mozilla/5.0"
```

Ces fichiers permettent de simuler différents scénarios :
- Navigation entre plusieurs pages web
- Requêtes sur différentes ressources (HTML, images, CSS, JS)
- Requêtes à différentes heures et dates

### Utilisation
Pour tester manuellement le programme avec un fichier de log :

```bash
cd bin
./analog ../LogDeTests/log1.log
```

Pour générer un graphe au format DOT :

```bash
./analog -g graphe.dot ../LogDeTests/log1.log
```

Pour filtrer par heure (ex. 11h) :

```bash
./analog -t 11 ../LogDeTests/log1.log
```

Pour afficher les N pages les plus consultées :

```bash
./analog -n 5 ../LogDeTests/log1.log
```

Ces fichiers sont également utilisés automatiquement par les scripts de tests dans `Tests/`.

Licence / Auteurs
------------------
Travail réalisé par le trinôme B01 — voir les auteurs listés en début de fichier.
