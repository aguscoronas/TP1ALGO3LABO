#include"declaraciones.hpp"
//read only global variables
extern int nroElementos;
extern std::vector<int> pesos;
extern std::vector<int> resistencias;
//memoizacion en columnas
int resuelvepDinamica(int resMax, int indice, std::vector<std::vector<int>> &columnas){
    if(indice >= nroElementos) return 0;
    //si esta indizado devuelvo ese valor
    if(columnas[indice][resMax] != -1) return columnas[indice][resMax];
    
    int loElijo = 1;
    //resMax no puede tomar valores negativos
    if(resMax - pesos[indice] < 0) loElijo = 0; 
    else loElijo += resuelvepDinamica(std::min(resMax - pesos[indice], resistencias[indice]),
                                      indice+1, columnas);
    
    //indizo el resultado y lo devuelvo 
    return columnas[indice][resMax] = std::max(loElijo, resuelvepDinamica(resMax, indice+1, columnas));
           
}

int programacionDinamica(int n, int R){
    //Creo la matriz para la recursion
    std::vector<int> filas (R+1 ,-1);
    std::vector<std::vector<int>> columnas (n+1, filas);
    
    return resuelvepDinamica(R, 0, columnas);
} 
