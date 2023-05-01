#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include<tuple>
#include<sstream>
#include<ctime>

int lerPrimeiraLinha();
bool linhaVazia(const string &linha);
void LerArquivo(itemMatriz **matriz, int tam_matriz);
void ImprimirMatriz(itemMatriz **matriz, int N);
void PercorrerMatrizRandomica(itemMatriz **matriz, int linha, int coluna, int N);
