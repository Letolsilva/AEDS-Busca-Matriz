#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include "funcoesArquivo.hpp"

int main(){
    itemMatriz ** matriz;
    int N;
    ifstream arquivo;

    arquivo.open("dataset/input.data", ios::in);
    N = lerPrimeiraLinha(arquivo);

    //Alocação da matriz
    matriz = (itemMatriz**)malloc(N * sizeof(itemMatriz*));
    for(int i = 0; i < N; i++){
        matriz[i] = (itemMatriz*)malloc(N * sizeof(itemMatriz));
    }

    lerMatrizArquivo(matriz, arquivo, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matriz[i][j].valor << " ";
        }
        cout << endl;
    }

    return 0;
}