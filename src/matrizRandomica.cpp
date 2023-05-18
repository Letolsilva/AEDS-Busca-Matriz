#include "matrizRandomica.hpp"
/*void matrizRandomicaFinal(ofstream &arquivo, itemMatriz ** matriz, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arquivo << matriz[i][j].valor << " ";
        }
        arquivo << "\n";
    }
}*/
void PercorrerMatrizRandomica(itemMatriz **matriz, int linha, int coluna, int N, int &passosRandomico){
    int linha_aux=0, coluna_aux=0, direcaoAleatoria=0;
    linha_aux = linha;
    coluna_aux=coluna;

    while(matriz[linha_aux][coluna_aux].valor != "?"){
        direcaoAleatoria = rand()%8;
        //cout << "POSIÇÂO ATUAL" << "[" << linha_aux << "]" << "[" << coluna_aux << "]" << endl;
        //cout << "DIREÇÃO ALEATORIA: " << direcaoAleatoria << endl;

        switch (direcaoAleatoria)
        {
            case 0: // direita
                if(coluna_aux < N-1 && matriz[linha_aux][coluna_aux+1].valor != "#"){
                    if(matriz[linha_aux][coluna_aux+1].valor != "*"){
                        coluna_aux++;
                    }
                    else{ //é perigo
                        matriz[linha_aux][coluna_aux+1].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
            case 1: //esquerda
                if(coluna_aux > 0 && matriz[linha_aux][coluna_aux-1].valor != "#"){
                    if(matriz[linha_aux][coluna_aux-1].valor != "*"){
                        
                        coluna_aux--;
                    }
                    else{ //é perigo
                        matriz[linha_aux][coluna_aux-1].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
            case 2: // cima
                if(linha_aux > 0 && matriz[linha_aux-1][coluna_aux].valor != "#"){
                    if(matriz[linha_aux-1][coluna_aux].valor != "*"){
                        linha_aux--;
                    }
                    else{ //é perigo
                        matriz[linha_aux-1][coluna_aux].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
            case 3: //baixo
                if(linha_aux < N-1 && matriz[linha_aux+1][coluna_aux].valor != "#"){ 
                    if(matriz[linha_aux+1][coluna_aux].valor != "*"){
                        linha_aux++;
                    }
                    else{ //é perigo
                        matriz[linha_aux+1][coluna_aux].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
            case 4: //dig  esq sup
                if(linha_aux != 0 && coluna_aux != 0 && matriz[linha_aux-1][coluna_aux-1].valor != "#"){
                    if(matriz[linha_aux-1][coluna_aux-1].valor != "*"){
                        linha_aux--;
                        coluna_aux--;
                    }
                    else{ //é perigo
                        matriz[linha_aux-1][coluna_aux-1].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
            case 5: //dig dir sup
                if(linha_aux != 0 && coluna_aux != N-1 && matriz[linha_aux-1][coluna_aux+1].valor != "#"){
                    if(matriz[linha_aux-1][coluna_aux+1].valor != "*"){
                        linha_aux--;
                        coluna_aux++;
                    }
                    else{ //é perigo
                        matriz[linha_aux-1][coluna_aux+1].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
            case 6: //dig esq inf
                if(linha_aux != N-1 && coluna_aux != 0 && matriz[linha_aux+1][coluna_aux-1].valor != "#"){
                    if(matriz[linha_aux+1][coluna_aux-1].valor != "*"){
                        linha_aux++;
                        coluna_aux--;
                    }
                    else{ //é perigo
                        matriz[linha_aux+1][coluna_aux-1].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
            case 7: //dig dir inf
                if(linha_aux != N-1 && coluna_aux != N-1 && matriz[linha_aux+1][coluna_aux+1].valor != "#"){
                    //cout << "Entra??" << endl;
                    if(matriz[linha_aux+1][coluna_aux+1].valor != "*"){
                        linha_aux++;
                        coluna_aux++;
                    }
                    else{ //é perigo
                        matriz[linha_aux+1][coluna_aux+1].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                    passosRandomico++;
                }
                //ImprimirMatriz(matriz, N);
                break;
        }
    }
    cout << "\nACHADO O FIM!!" << endl;
    cout << "POSIÇÂO: [" << linha_aux << "]" << "[" << coluna_aux << "]"  << endl;
    
}