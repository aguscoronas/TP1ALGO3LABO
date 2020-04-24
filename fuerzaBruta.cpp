#include"declaraciones.hpp"
//read only global variables
extern int nroElementos;
extern std::vector<int> pesos;
extern std::vector<int> resistencias;
/*
 *Fuerza Bruta recursiva: 
 *resMax es la resistencia que queda en todo momento tanto del tuvo como de los elementos
 *elejidos que están abajo y pueden ser aplastados.
 *indice es el elemento que estamos considerando
 */
int resuelveFuerzaBruta(int resMax, int indice){
    //caso base: no hay mas elementos para considerar
    if(indice == nroElementos) return 0;
    //caso elijo el elemento: decremento la resistencia y aumento el nro de elegidos
    int loElijo = 1;
    loElijo += resuelveFuerzaBruta(std::min(resMax - pesos[indice], resistencias[indice]),
                                      indice+1);
    //si la resistencia daba negativa, entonces nunca lo podría haber elegido así que lo anulo
    if(resMax - pesos[indice] < 0) loElijo = 0;
    
    //comparo el resultado con no haberlo elegido 
    return std::max(loElijo, resuelveFuerzaBruta(resMax, indice+1));
}

int fuerzaBruta(int n, int R){
    //valores iniciales para la recursion
    return resuelveFuerzaBruta(R, 0);
}