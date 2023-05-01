 #include "funcoesArquivo.hpp"

int lerPrimeiraLinha(){
    ifstream arquivo;
    arquivo.open("dataset/input.data", ios::in);
    int N;
    string primeiraLinha;
    getline(arquivo, primeiraLinha);
    N = atoi(primeiraLinha.c_str());

    arquivo.close();
    return N;
}

bool linhaVazia(const string &linha)
{
    for (char c : linha){
        if (!isspace(c)){ // Se o caractere não for espaço em branco, a linha não está vazia
            return false;
        }
    }
    // Se todos os caracteres forem espaços em branco, a linha está vazia
    return true;
}

void LerArquivo(itemMatriz **matriz, int tam_matriz)
{
    ifstream arquivo;
    string linha_arq, elemento;
    int aux_linha = 0, aux_coluna = 0, aux_tam = 0;

    arquivo.open("dataset/input.data", ios::in);

    while (!arquivo.eof()){
        while (getline(arquivo, linha_arq, '\n')){
            if (aux_tam == 0){
                aux_tam++;
            }
            else{
                if (linhaVazia(linha_arq)){
                    aux_coluna = 0;
                    aux_linha = 0;
                }
                else{
                    // está criando um fluxo de caracteres para que a função getline possa ler e manipular os dados
                    stringstream aux(linha_arq);

                    while (getline(aux, elemento, ' ')){// lendo a cada elemento presente na minha linha armazena para minha variavel elemento e tendo o delimitador ''
                        if (aux_coluna < tam_matriz && aux_linha < tam_matriz){
                            matriz[aux_linha][aux_coluna].valor = elemento;
                            aux_coluna++;
                        }
                    }

                    if (aux_coluna > 0 && aux_linha < tam_matriz){
                        aux_linha++;
                        aux_coluna = 0;
                    }
                }
            }
        }
    }
    arquivo.close();
}

void ImprimirMatriz(itemMatriz **matriz, int N){
    cout << endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << matriz[i][j].valor << " ";
        }
        cout << endl;
    }
}

void PercorrerMatrizRandomica(itemMatriz **matriz, int linha, int coluna, int N){
    int linha_aux=0, coluna_aux=0, direcaoAleatoria=0;
    linha_aux = linha;
    coluna_aux=coluna;

    while(matriz[linha_aux][coluna_aux].valor != "?"){
        direcaoAleatoria = rand()%8;
        cout << "POSIÇÂO ATUAL" << "[" << linha_aux << "]" << "[" << coluna_aux << "]" << endl;
        cout << "DIREÇÃO ALEATORIA: " << direcaoAleatoria << endl;

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
                }
                ImprimirMatriz(matriz, N);
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
                }
                ImprimirMatriz(matriz, N);
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
                }
                ImprimirMatriz(matriz, N);
                break;
            case 3: //baixo
                if(coluna_aux < N-1 && matriz[linha_aux+1][coluna_aux].valor != "#"){
                    if(matriz[linha_aux+1][coluna_aux].valor != "*"){
                        linha_aux++;
                    }
                    else{ //é perigo
                        matriz[linha_aux+1][coluna_aux].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                }
                ImprimirMatriz(matriz, N);
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
                }
                ImprimirMatriz(matriz, N);
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
                }
                ImprimirMatriz(matriz, N);
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
                }
                ImprimirMatriz(matriz, N);
                break;
            case 7: //dig dir inf
                if(linha_aux != N-1 && coluna_aux != N-1 && matriz[linha_aux+1][coluna_aux+1].valor != "#"){
                    cout << "Entra??" << endl;
                    if(matriz[linha_aux+1][coluna_aux+1].valor != "*"){
                        linha_aux++;
                        coluna_aux++;
                    }
                    else{ //é perigo
                        matriz[linha_aux+1][coluna_aux+1].valor = "1";
                        linha_aux = 0;
                        coluna_aux = 0;
                    }
                }
                ImprimirMatriz(matriz, N);
                break;
        }
    }
    cout << "ACHADO O FIM!!" << endl;
    cout << "POSIÇÂO: [" << linha_aux << "]" << "[" << coluna_aux << "]"  << endl;
}