#include"declaraciones.hpp"
//read only global variables
extern int nroElementos;
extern std::vector<int> pesos;
extern std::vector<int> resistencias;

//read write global
int mejorSolucion;

int resuelveBacktracking(int resMax, int indice, int cantIncluidos){
    if(indice == nroElementos) return 0;
    //PODA POR OPTIMALIDAD
    if(nroElementos - indice + cantIncluidos < mejorSolucion) return 0;

    //PODA POR FACTIBILIDAD me paso del peso:
    //si la resistencia da negativa, entonces no avanzo
    int loElijo = 1;    
    if(resMax - pesos[indice] < 0) loElijo = 0; 
    else loElijo += resuelveBacktracking(std::min(resMax - pesos[indice], resistencias[indice]),
                                      indice+1, cantIncluidos+1);
    
    
    //comparo el resultado con no haberlo elegido 
    return std::max(loElijo, resuelveBacktracking(resMax, indice+1, cantIncluidos));
}

int Backtracking(int n, int R){
    //inicializamos en 0
    mejorSolucion = 0;
    //valores iniciales para la recursion
    return resuelveBacktracking(R, 0, 0);
}

