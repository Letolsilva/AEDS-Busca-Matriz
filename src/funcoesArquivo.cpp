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
                if (!linhaVazia(linha_arq)){
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

