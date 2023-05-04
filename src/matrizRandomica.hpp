#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include<tuple>
#include<sstream>
#include<ctime>
#include "funcoesArquivo.hpp"

void PercorrerMatrizRandomica(itemMatriz **matriz, int linha, int coluna, int N, ofstream &arquivo);
void matrizRandomicaFinal(ofstream &arquivo, itemMatriz ** matriz, int N);