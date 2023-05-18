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
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#") && (tag != 8)){
                return 4;//Diagonal direita inferior
            }
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#") && (tag != 1)){
                return 5;//Baixo
            }
        }
        else if(coluna == (N - 1)){
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#") && (tag != 1)){
                return 5;//Baixo
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#") && (tag != 2)){
                return 6;//Diagonal esquerda inferior
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
        }
        else{
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#") && (tag != 8)){
                return 4;//Diagonal direita inferior
            }
            if((matriz[linha+1][coluna].cor == "branco") && (matriz[linha+1][coluna].valor != "#") && (tag != 1)){
                return 5;//Baixo
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#") && (tag != 2)){
                return 6;//Diagonal esquerda inferior
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
        }
    }
    else if(linha == (N - 1)){
        if(coluna == 0){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#") && (tag != 5)){
                return 1;//Cima
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#") && (tag != 6)){
                return 2;//Diagonal direita superior
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
        }
        else if(coluna == (N - 1)){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#") && (tag != 5)){
                return 1;//Cima
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#") && (tag != 4)){
                return 8;//Diagonal esquerda superior
            }
        }
        else{
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#") && (tag != 5)){
                return 1;//Cima
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#") && (tag != 6)){
                return 2;//Diagonal direita superior
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#") && (tag != 4)){
                return 8;//Diagonal esquerda superior
            }
        }
    }
    else{
        if(coluna == 0){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#") && (tag != 5)){
                return 1;//Cima
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#") && (tag != 6)){
                return 2;//Diagonal direita superior
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#") && (tag != 8)){
                return 4;//Diagonal direita inferior
            }
        }
        else if(coluna == (N - 1)){
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#") && (tag != 5)){
                return 1;//Cima
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#") && (tag != 2)){
                return 6;//Diagonal esquerda inferior
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#") && (tag != 4)){
                return 8;//Diagonal esquerda superior
            }
        }
        else{
            if((matriz[linha-1][coluna].cor == "branco") && (matriz[linha-1][coluna].valor != "#") && (tag != 5)){
                return 1;//Cima
            }
            if((matriz[linha-1][coluna+1].cor == "branco") && (matriz[linha-1][coluna+1].valor != "#") && (tag != 6)){
                return 2;//Diagonal direita superior
            }
            if((matriz[linha][coluna+1].cor == "branco") && (matriz[linha][coluna+1].valor != "#") && (tag != 7)){
                return 3;//Direita
            }
            if((matriz[linha+1][coluna+1].cor == "branco") && (matriz[linha+1][coluna+1].valor != "#") && (tag != 8)){
                return 4;//Diagonal direita inferior
            }
            if((matriz[linha+1][coluna-1].cor == "branco") && (matriz[linha+1][coluna-1].valor != "#") && (tag != 2)){
                return 6;//Diagonal esquerda inferior
            }
            if((matriz[linha][coluna-1].cor == "branco") && (matriz[linha][coluna-1].valor != "#") && (tag != 3)){
                return 7;//Esquerda
            }
            if((matriz[linha-1][coluna-1].cor == "branco") && (matriz[linha-1][coluna-1].valor != "#") && (tag != 4)){
                return 8;//Diagonal esquerda superior
            }
        }
    }
    return controle;
}

void PercorrerMatrizProfundidade(itemMatriz **matriz, int N, int linha, int coluna, Lista * lista, int &passosProfundidade){
    int tag = 5;
    inicializarCores(matriz, N);
    while(matriz[linha][coluna].valor != "?"){        
        if(matriz[linha][coluna].valor == "*"){
            matriz[linha][coluna].valor = "1";
            linha = 0;
            coluna = 0;
            excluirLista(lista);
            init(lista);
            inicializarCores(matriz, N);
            tag = 5;
        }
        if(matriz[linha][coluna].cor == "branco"){
            insertInicio(lista, matriz[linha][coluna]);
            matriz[linha][coluna].cor = "cinza";
        }
        switch(tag){
            case 0:
                removerItemInicio(lista);
                matriz[linha][coluna].cor = "preto";
                linha = lista->primeiro->item.posicaoLinha;
                coluna = lista->primeiro->item.posicaoColuna;
                tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
            break;

            case 1:
                if((linha != 0) && ((matriz[linha-1][coluna].valor) != "#")){
                    linha--;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }                
            break;

            case 2:
                if((linha != 0) && (coluna != (N-1)) && ((matriz[linha-1][coluna+1].valor) != "#")){
                    linha--;
                    coluna++;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }                  
            break;

            case 3:
                if((coluna != (N-1)) && ((matriz[linha][coluna+1].valor) != "#")){
                    coluna++;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }
            break;

            case 4:
                if((linha != (N-1)) && (coluna != (N-1)) && ((matriz[linha+1][coluna+1].valor) != "#")){
                    linha++;
                    coluna++;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }
            break;

            case 5:
                if((linha != (N-1)) && ((matriz[linha+1][coluna].valor) != "#")){
                    linha++;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }
            break;

            case 6:
                if((linha != (N-1)) && (coluna != 0) && ((matriz[linha+1][coluna-1].valor) != "#")){
                    linha++;
                    coluna--;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }
            break;

            case 7:
                if((coluna != 0) && ((matriz[linha][coluna-1].valor) != "#")){
                    coluna--;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }
            break;

            case 8:
                if((linha != 0) && (coluna != 0) && ((matriz[linha-1][coluna-1].valor) != "#")){
                    linha--;
                    coluna--;
                    passosProfundidade++;
                }       
                else{
                    tag = caminhoDisponivel(matriz, N, linha, coluna, tag);
                }
            break;
        }
    }
    cout << "\nACHADO O FIM!!" << endl;
    cout << "POSIÇÂO: [" << linha << "]" << "[" << coluna << "]"  << endl;
}