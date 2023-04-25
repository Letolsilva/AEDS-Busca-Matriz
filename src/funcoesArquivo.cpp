 #include "funcoesArquivo.hpp"
/*
int lerPrimeiraLinha(ifstream &arquivo){
    int N;
    string primeiraLinha;
    getline(arquivo, primeiraLinha);
    N = atoi(primeiraLinha.c_str());
    return N;
}

void lerMatrizArquivo(itemMatriz ** matrizTexto, ifstream &arquivo, int N){
    int cont = 0;
    string numeroAtual, linha;
    getline(arquivo, linha);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizTexto[i][j].valor = "x";
        }
    }
    if (!arquivo)
    {
        cout << "Erro na abertura do arquivo!!\n";
        exit(-1);
    }
    else
    { 
        for (int x = 0; x < N; x++)
        {
            getline(arquivo, linha);

            for (int i = 0; i <= (int) linha.size(); i++)
            {
                if (linha[i] != '\0')
                {
                    if (linha[i] != ' ')
                    {
                        numeroAtual += linha[i];
                    }
                    else
                    {
                        for (int i = 0; i < N; i++)
                        {
                            if (matrizTexto[cont][i].valor == "x")
                            {
                                matrizTexto[cont][i].valor = numeroAtual;
                                break;
                            }
                        }
                        numeroAtual.clear();
                    }
                }
                else
                {
                    break;
                }
            }
            cont++;
            linha.clear();
        }
        cont = 0;
    }
}
 */

tuple<int, int> LePrimeraLinha()
{
    ifstream arquivo;
    string linha, valor_str, elemento, qtdMatriz_str;
    int tam, aux, qtdMatriz=0, cont=0;

    arquivo.open("dataset/input.data", ios::in);
    while(getline(arquivo, linha, '\n')){
        stringstream aux_str(linha);
        while (getline(aux_str, elemento, ' ')){
            if (aux == 2){
                    if (cont == 0){
                        qtdMatriz_str = elemento;
                        qtdMatriz = atoi(qtdMatriz_str.c_str());
                        cont++;
                    }
                }
                else{
                    valor_str = elemento;
                    tam = atoi(valor_str.c_str());
                    aux++;
                }
        }
    }
    arquivo.close();
    return make_tuple(tam, qtdMatriz);
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