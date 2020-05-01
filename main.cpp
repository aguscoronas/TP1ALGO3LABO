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
std::cout << fuerzaBruta(n, R) << std::endl;
std::cout << Backtracking(n, R) << std::endl;
std::cout << programacionDinamica(n, R) << std::endl;

}
