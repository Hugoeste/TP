---------------- Projet géométrie -------------------

Ce projet permet de calculer différentes chose géométrique sur des cercles, des carrées et des triangles.

-------- Build -----------

Compiler avec :

make

OU 

g++ -std=c++23 -Iinclude -o main src/*.cpp src/shapes/*.cpp main.cpp -lgdi32 -luser32

Executer avec :

./main

--------- Test -------------

Compiler avec :

make 

OU

g++ -std=c++23 -Iinclude -o test src/*.cpp src/shapes/*.cpp test/*.cpp -lgdi32 -luser32

Executer avec :

./test

------------ Structure du projet -----------------

    - main.cpp : point d'entrée
    - include/ : Fichier header
    - src/ : Fichier d'implémentation
    -test/ : programmes de test
