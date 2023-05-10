#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include "funcoesArquivo.hpp"
#include "matrizRandomica.hpp"
#include "matrizLargura.hpp"
#include "matrizProfundidade.hpp"

int main(){
    ofstream arquivoRandomica, arquivoLargura, arquivoProfundidade;
    int N, linha=0, coluna=0;
    Lista * lista = new Lista();
    init(lista);

    arquivoRandomica.open("dataset/outputRandomica.data", ios::out);
    arquivoLargura.open("dataset/outputLargura.data", ios::out);
    arquivoProfundidade.open("dataset/outputProfundidade.data", ios::out);

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

    cout << "\nMATRIZ RANDÔMICA\n";
    PercorrerMatrizRandomica(matriz, linha, coluna, N, arquivoRandomica);
    matrizFinal(arquivoRandomica, matriz, N);

    cout << "\nMATRIZ LARGURA\n";
    LerArquivo(matriz, N);
    PercorrerMatrizLargura(matriz, N, linha, coluna, lista);
    matrizFinal(arquivoLargura, matriz, N);

    excluirLista(lista);
    init(lista);
    
    cout << "\nMATRIZ PROFUNDIDADE\n";
    LerArquivo(matriz, N);
    PercorrerMatrizProfundidade(matriz, N, linha, coluna, lista);
    matrizFinal(arquivoProfundidade, matriz, N);
    
    arquivoLargura.close();
    arquivoProfundidade.close();
    arquivoRandomica.close();

    return 0;
}