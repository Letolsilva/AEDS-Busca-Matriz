#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include "funcoesArquivo.hpp"

int main(){

    int N, linha=0, coluna=0;

    //Salvando informações presentes na primeria linha
    N = lerPrimeiraLinha();

    //Alocação da matriz
    itemMatriz** matriz=new itemMatriz*[N];
    for(int i = 0; i < N; i++){
        matriz[i]=new itemMatriz[N];
    }

    LerArquivo(matriz, N);
    cout << "TAM MATRIZ: " << N << endl;

    ImprimirMatriz(matriz, N);

    PercorrerMatrizRandomica(matriz, linha, coluna, N);

    return 0;
}