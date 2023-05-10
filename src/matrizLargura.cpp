#include "matrizLargura.hpp"

void inicializarCores(itemMatriz ** matriz, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matriz[i][j].cor = "branco";
            matriz[i][j].posicaoLinha = i;
            matriz[i][j].posicaoColuna = j;
        }
    }
}

void verFronteiras(itemMatriz ** matriz, int linha, int coluna, int N, Lista * lista){
    if(linha == 0){
        if(coluna == 0){
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#")){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, lista->primeiro, matriz[linha][coluna+1]);
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#")){
                matriz[linha+1][coluna+1].cor = "cinza";//diagonal direita inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna+1]);
            }
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#")){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna]);
            }
        }
        else if(coluna == (N - 1)){
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#")){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna]);
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#")){
                matriz[linha+1][coluna-1].cor = "cinza";//diagonal esquerda inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna-1]);
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#")){
                matriz[linha][coluna-1].cor = "cinza";//esquerda
                insertEnd(lista, lista->primeiro, matriz[linha][coluna-1]);
            }
        }
        else{
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#")){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, lista->primeiro, matriz[linha][coluna+1]);
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#")){
                matriz[linha+1][coluna+1].cor = "cinza";//diagonal direita inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna+1]);
            }
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#")){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna]);
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#")){
                matriz[linha+1][coluna-1].cor = "cinza";//diagonal esquerda inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna-1]);
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#")){
                matriz[linha][coluna-1].cor = "cinza";//esquerda
                insertEnd(lista, lista->primeiro, matriz[linha][coluna-1]);
            }
        }
    }
    else if(linha == (N - 1)){
        if(coluna == 0){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#")){
                matriz[linha-1][coluna].cor = "cinza";//cima
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna]);
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#")){
                matriz[linha-1][coluna+1].cor = "cinza";//diagonal direita superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna+1]);
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#")){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, lista->primeiro, matriz[linha][coluna+1]);
            }
        }
        else if(coluna == (N - 1)){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#")){
                matriz[linha-1][coluna].cor = "cinza";//cima
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna]);
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#")){
                matriz[linha][coluna-1].cor = "cinza";//esquerda
                insertEnd(lista, lista->primeiro, matriz[linha][coluna-1]);
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#")){
                matriz[linha-1][coluna-1].cor = "cinza";//diagonal esquerda superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna-1]);
            }
        }
        else{
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#")){
                matriz[linha-1][coluna].cor = "cinza";//cima
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna]);
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#")){
                matriz[linha-1][coluna+1].cor = "cinza";//diagonal direita superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna+1]);
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#")){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, lista->primeiro, matriz[linha][coluna+1]);
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#")){
                matriz[linha][coluna-1].cor = "cinza";//esquerda
                insertEnd(lista, lista->primeiro, matriz[linha][coluna-1]);
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#")){
                matriz[linha-1][coluna-1].cor = "cinza";//diagonal esquerda superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna-1]);
            }
        }
    }
    else{ 
        if(coluna == 0){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#")){
                matriz[linha-1][coluna].cor = "cinza";//cima
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna]);
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#")){
                matriz[linha-1][coluna+1].cor = "cinza";//diagonal direita superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna+1]);
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#")){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, lista->primeiro, matriz[linha][coluna+1]);
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#")){
                matriz[linha+1][coluna+1].cor = "cinza";//diagonal direita inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna+1]);
            }
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#")){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna]);
            }
        } 
        else if(coluna == (N - 1)){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#")){
                matriz[linha-1][coluna].cor = "cinza";//cima
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna]);
            }
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#")){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna]);
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#")){
                matriz[linha+1][coluna-1].cor = "cinza";//diagonal esquerda inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna-1]);
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#")){
                matriz[linha][coluna-1].cor = "cinza";//esquerda
                insertEnd(lista, lista->primeiro, matriz[linha][coluna-1]);
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#")){
                matriz[linha-1][coluna-1].cor = "cinza";//diagonal esquerda superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna-1]);
            }
        } 
        else{     
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#")){
                matriz[linha-1][coluna].cor = "cinza";//cima
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna]);
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#")){
                matriz[linha-1][coluna+1].cor = "cinza";//diagonal direita superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna+1]);
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#")){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, lista->primeiro, matriz[linha][coluna+1]);
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#")){
                matriz[linha+1][coluna+1].cor = "cinza";//diagonal direita inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna+1]);
            }
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#")){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna]);
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#")){
                matriz[linha+1][coluna-1].cor = "cinza";//diagonal esquerda inferior
                insertEnd(lista, lista->primeiro, matriz[linha+1][coluna-1]);
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#")){
                matriz[linha][coluna-1].cor = "cinza";//esquerda
                insertEnd(lista, lista->primeiro, matriz[linha][coluna-1]);
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#")){
                matriz[linha-1][coluna-1].cor = "cinza";//diagonal esquerda superior
                insertEnd(lista, lista->primeiro, matriz[linha-1][coluna-1]);
            }
        }
    }
}

void matrizFinal(ofstream &arquivo, itemMatriz ** matriz, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arquivo << matriz[i][j].valor << " ";
        }
        arquivo << "\n";
    }
}

void PercorrerMatrizLargura(itemMatriz **matriz, int N, int linha, int coluna, Lista * lista){
    inicializarCores(matriz, N);
    while(matriz[linha][coluna].valor != "?"){
        if(matriz[linha][coluna].valor == "*"){
            matriz[linha][coluna].valor = "1";
            linha = 0;
            coluna = 0;
            excluirLista(lista);
            init(lista);
            inicializarCores(matriz, N);
        }
        else{
            verFronteiras(matriz,linha,coluna,N, lista);
            matriz[linha][coluna].cor = "preto";
            cout << "Posição atual: " << linha << " " << coluna << endl;
            LImprime(lista);
            linha = lista->primeiro->item.posicaoLinha;
            coluna = lista->primeiro->item.posicaoColuna; 
            cout << "Posição atual 2: " << linha << " " << coluna << endl;
            removerItemInicio(lista);
        }
    }
}