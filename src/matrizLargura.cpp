#include "matrizLargura.hpp"

void inicializarCores(itemMatriz ** matriz, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matriz[i][j].cor = "branco";
        }
    }
}

void verFronteiras(itemMatriz ** matriz, int linha, int coluna, int N, Lista * lista){
    if(linha == 0){
        if(coluna == 0){
            if(matriz[linha][coluna+1].cor == "branco"){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, matriz[linha][coluna+1]);
            }
            if(matriz[linha+1][coluna+1].cor == "branco"){
                matriz[linha+1][coluna+1].cor = "cinza";//diagonal direita inferior
                insertEnd(lista, matriz[linha+1][coluna+1]);
            }
            if(matriz[linha+1][coluna].cor == "branco"){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, matriz[linha+1][coluna]);
            }
        }
        else if(coluna == (N - 1)){
            if(matriz[linha+1][coluna].cor == "branco"){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, matriz[linha+1][coluna]);
            }
        }
        else{
            if(matriz[linha][coluna+1].cor == "branco"){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, matriz[linha][coluna+1]);
            }
            if(matriz[linha+1][coluna+1].cor == "branco"){
                matriz[linha+1][coluna+1].cor = "cinza";//diagonal direita inferior
                insertEnd(lista, matriz[linha+1][coluna+1]);
            }
            if(matriz[linha+1][coluna].cor == "branco"){
                matriz[linha+1][coluna].cor = "cinza";//baixo
                insertEnd(lista, matriz[linha+1][coluna]);
            }
        }
    }
    else if(linha == (N - 1)){
        if(coluna == 0){
            if(matriz[linha][coluna+1].cor == "branco"){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, matriz[linha][coluna+1]);
            }
        }
        else if(coluna == (N - 1)){

        }
        else{
            if(matriz[linha][coluna+1].cor == "branco"){
                matriz[linha][coluna+1].cor = "cinza";//direita
                insertEnd(lista, matriz[linha][coluna+1]);
            }
        }
    }
    else{
        if(matriz[linha][coluna+1].cor == "branco"){
            matriz[linha][coluna+1].cor = "cinza";//direita
            insertEnd(lista, matriz[linha][coluna+1]);
        }
        if(matriz[linha+1][coluna+1].cor == "branco"){
        matriz[linha+1][coluna+1].cor = "cinza";//diagonal direita inferior
        insertEnd(lista, matriz[linha+1][coluna+1]);
        }
        if(matriz[linha+1][coluna].cor == "branco"){
            matriz[linha+1][coluna].cor = "cinza";//baixo
            insertEnd(lista, matriz[linha+1][coluna]);
        }
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
            lista->primeiro->item.cor = "preto";
        }
    }
}