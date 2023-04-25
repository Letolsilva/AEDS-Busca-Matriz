#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include "funcoesArquivo.hpp"

int main(){

    int N, qtd_matriz=0;

    //Salvando informações presentes na primeria linha
    tie(N, qtd_matriz) = LePrimeraLinha();

    //Alocação da matriz
    itemMatriz** matriz=new itemMatriz*[N];
    for(int i = 0; i < N; i++){
        matriz[i]=new itemMatriz[N];
    }

    /* matriz = (itemMatriz**)malloc(N * sizeof(itemMatriz*));
    for(int i = 0; i < N; i++){
        matriz[i] = (itemMatriz*)malloc(N * sizeof(itemMatriz));
    } */

    LerArquivo(matriz, N);
    cout << "QTD_MATRIZ: " << qtd_matriz << endl;
    cout << "TAM MATRIZ: " << N << endl;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matriz[i][j].valor << " ";
        }
        cout << endl;
    }

    return 0;
}