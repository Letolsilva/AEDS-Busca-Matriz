#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include <tuple>
#include <sstream>
#include <ctime>
#include "funcoesArquivo.hpp"
#include "matrizLargura.hpp"

void PercorrerMatrizProfundidade(itemMatriz **matriz, int N, int linha, int coluna, Lista * lista);
int caminhoDisponivel(itemMatriz ** matriz, int N, int linha, int coluna, int tag);