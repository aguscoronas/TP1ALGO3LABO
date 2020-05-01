#include"declaraciones.hpp"

int nroElementos;
std::vector<int> pesos;
std::vector<int> resistencias;
int main()
{
int n, R;
std::cin >> n;
std::cin >> R;
std::vector<int> w(n,0);
std::vector<int> r(n,0);
for(int i = 0; i < n; i++){ 
    std::cin >> w[i];
    std::cin >> r[i];
}
nroElementos = n;
pesos = w;
resistencias = r;

tiempo(n, R, &fuerzaBruta);
tiempo(n, R, &Backtracking);
tiempo(n, R, &programacionDinamica);
}

//para realizar las mediciones de los algoritmos
void tiempo(int n, int R, int (*funcion)(int, int)){
    auto start = std::chrono::steady_clock::now();    
    funcion(n, R);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << std::chrono::duration <double, std::milli>(diff).count() << std::endl;
} 