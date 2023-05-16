#include <chrono>
#include <iomanip>
#include "lista.hpp"
#include "itemLista.hpp"
#include "itemMatriz.hpp"
#include "lista.hpp"
#include "funcoesArquivo.hpp"
#include "matrizRandomica.hpp"
#include "matrizLargura.hpp"
#include "matrizProfundidade.hpp"

int main(){
    chrono::steady_clock::time_point inicio = chrono::steady_clock::now();
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

    cout << "\n---[MATRIZ RANDÔMICA]---";
    PercorrerMatrizRandomica(matriz, linha, coluna, N);
    matrizFinal(arquivoRandomica, matriz, N);
    chrono::steady_clock::time_point fimRandomico = chrono::steady_clock::now();
    chrono::duration<double, milli> tempoRandomico = fimRandomico - inicio;
    cout<<"TEMPO DE EXECUÇÃO RANDÔMICA: "<< fixed  << setprecision(2)<< tempoRandomico.count() <<" ms "<<endl;

    cout << "\n---[MATRIZ LARGURA]---\n";
    LerArquivo(matriz, N);
    PercorrerMatrizLargura(matriz, N, linha, coluna, lista);
    matrizFinal(arquivoLargura, matriz, N);
    chrono::steady_clock::time_point fimLargura = chrono::steady_clock::now();
    chrono::duration<double, milli> tempoLargura = fimLargura - inicio;
    cout<<"TEMPO DE EXECUÇÃO LARGURA: "<< fixed  << setprecision(2)<< tempoLargura.count() <<" ms "<<endl;
    excluirLista(lista);
    init(lista);
    
    cout << "\n---[MATRIZ PROFUNDIDADE]---";
    LerArquivo(matriz, N);
    PercorrerMatrizProfundidade(matriz, N, linha, coluna, lista);
    matrizFinal(arquivoProfundidade, matriz, N);
    chrono::steady_clock::time_point fimProfundidade = chrono::steady_clock::now();
    chrono::duration<double, milli> tempoProfundidade = fimProfundidade - inicio;
    cout<<"TEMPO DE EXECUÇÃO PROFUNDIDADE: "<< fixed  << setprecision(2)<< tempoProfundidade.count() <<" ms "<<endl;
    arquivoLargura.close();
    arquivoProfundidade.close();
    arquivoRandomica.close();
    //Liberação da matriz
    for(int i = 0; i < N; i++){
        free(matriz[i]);
    }
    free(matriz);
    excluirLista(lista);
    
    return 0;
}