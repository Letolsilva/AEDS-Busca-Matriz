#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include <tuple>
#include <sstream>
#include <ctime>
#include "funcoesArquivo.hpp"

void inicializarCores(itemMatriz ** matriz, int N);
void PercorrerMatrizLargura(itemMatriz **matriz, int N, int linha, int coluna, Lista * lista, int &passosLargura);
void verFronteiras(itemMatriz ** matriz, int linha, int coluna, int N, Lista * lista);
void matrizFinal(ofstream &arquivo, itemMatriz ** matriz, int N);