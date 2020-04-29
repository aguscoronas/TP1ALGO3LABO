#ifndef FUNCIONES
#define FUNCIONES
#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>

int fuerzaBruta(int n, int R);
int Backtracking(int n, int R);
int programacionDinamica(int n, int R);
void tiempo(int n, int R, int (*funcion)(int, int));
#endif