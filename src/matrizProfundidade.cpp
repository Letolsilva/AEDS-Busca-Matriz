#include "matrizProfundidade.hpp"

int caminhoDisponivel(itemMatriz ** matriz, int N, int linha, int coluna, int tag){
    int controle = 0;
    /*1 - Cima
      2 - Diagonal direita superior
      3 - Direita
      4 - Diagonal direita inferior
      5 - Baixo
      6 - Diagonal esquerda inferior
      7 - Esquerda
      8 - Diagonal esquerda superior
    */
    if(linha == 0){
        if(coluna == 0){
            if((matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
            if((matriz[linha+1][coluna+1].valor != "#") && (tag != 8)){
                return 4;//Diagonal direita inferior
            }
            if((matriz[linha+1][coluna].valor != "#") && (tag != 1)){
                return 5;//Baixo
            }
        }
        else if(coluna == (N - 1)){
            if((matriz[linha+1][coluna].valor != "#") && (tag != 1)){
                return 5;//Baixo
            }
            if((matriz[linha+1][coluna-1].valor != "#") && (tag != 2)){
                return 6;//Diagonal esquerda inferior
            }
            if((matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
        }
        else{
            if((matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
            if((matriz[linha+1][coluna+1].valor != "#") && (tag != 8)){
                return 4;//Diagonal direita inferior
            }
            if((matriz[linha+1][coluna].valor != "#") && (tag != 1)){
                return 5;//Baixo
            }
            if((matriz[linha+1][coluna-1].valor != "#") && (tag != 2)){
                return 6;//Diagonal esquerda inferior
            }
            if((matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
        }
    }
    else if(linha == (N - 1)){
        
    }
    else{
        if(coluna == 0){
            if(matriz[linha-1][coluna+1].valor != "#"){
                return 2;//Diagonal direita superior
            }
            if(matriz[linha][coluna+1].valor != "#"){
                return 3;//Direita
            }
            if(matriz[linha+1][coluna+1].valor != "#"){
                return 4;//Diagonal direita inferior
            }
        }
        else if(coluna == (N - 1)){
            if(matriz[linha+1][coluna-1].valor != "#"){
                return 6;//Diagonal esquerda inferior
            }
            if(matriz[linha][coluna-1].valor != "#"){
                return 7;//Esquerda
            }
            if(matriz[linha-1][coluna-1].valor != "#"){
                return 8;//Diagonal esquerda superior
            }
        }
        else{
            if(matriz[linha-1][coluna+1].valor != "#"){
                return 2;//Diagonal direita superior
            }
            if(matriz[linha][coluna+1].valor != "#"){
                return 3;//Direita
            }
            if(matriz[linha+1][coluna+1].valor != "#"){
                return 4;//Diagonal direita inferior
            }
            if(matriz[linha+1][coluna-1].valor != "#"){
                return 6;//Diagonal esquerda inferior
            }
            if(matriz[linha][coluna-1].valor != "#"){
                return 7;//Esquerda
            }
            if(matriz[linha-1][coluna-1].valor != "#"){
                return 8;//Diagonal esquerda superior
            }
        }
    }
    return controle;
}

void PercorrerMatrizProfundidade(itemMatriz **matriz, int N, int linha, int coluna, Lista * lista){
    inicializarCores(matriz, N);
    while(matriz[linha][coluna].valor != "?"){
        while(linha != (N - 1)){
            matriz[linha][coluna].cor = "cinza";
            insertInicio(lista, lista->primeiro, matriz[linha][coluna]);
            if((matriz[linha+1][coluna].valor) != "#"){
                linha++;
            }
            else{
                
            }
        }
    }
}