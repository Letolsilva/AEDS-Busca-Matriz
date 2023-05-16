<h1 align="center" font-size="200em"><b>Labirinto DFS e BFS</b></h1>

<div align = "center" >
<!-- imagem -->

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

# Sumário
- [Introdução](#Introdução)
- [Objetivos](#Objetivos)
- [Problema apresentado](#Problema-apresentado)
- [Arquivos](#Arquivos)
- [Resolução do Problema](#Resolução-do-problema)
- [Exemplifição](#Exemplificação)
- [Resultados esperados](#Resultados-esperados)
- [Conclusão](#Conclusão)
- [Compilação e Execução](#Compilação-e-Execução)
- [Contato](#Contato)

## Introdução
<p align="justify">
Este é um programa desenvolvido em C++ para a disciplina de Algoritmo de Estrutura de Dados I. O objetivo do programa é realizar o caminhamento em matrizes de três maneiras diferentes: aleatória, DFS (Busca em Profundidade) e BFS (Busca em Largura). Esess algoritmos de busca foram implementados a modo que ache a posição que contenha o caracter especial '?'.<br>
O algoritmo de largura (BFS) é utilizado para verificar as posições adjacentes a partir da posição atual. A partir de uma matriz qualquer, o algoritmo opta por visitar todas as relações de adjacência a cada interação antes de avançar para uma nova posição. Já o algoritmo de profundidade (DFS) utiliza a matriz para encontrar todas as posições alcançáveis a partir de um determinado vértice inicial. Esse algoritmo visita os vizinhos de uma posição atual até que não haja mais posições alcançáveis a partir dele, antes de avançar para outro vértice. <br>
O algoritmo aleatório utiliza um caminhamento aleatório para explorar a matriz. Ele escolhe aleatoriamente uma das posições vizinhas para se mover e esse processo se repete ate que seja encontrado o caracter especial.<br>
Ambos os algoritmos, BFS e DFS, foram implementados para percorrer uma matriz e visitar todas as suas posições ate encontrarem a posição do carctaer especial('?').
</p>

## 💻Objetivos

O objetivo desta atividade é desenvolver algoritmos que permitam que um programa encontre o caractere '?' (interrogação) em uma matriz que representa um labirinto, utilizando os algoritmos de busca em largura, profundidade e aleatória. Para isso, foi implementado algoritmos para visitar todas as posições da matriz a partir de uma posição inicial, adotada para todos os casos como: [0][0], e procurar pelo caractere '?' em cada uma dessas matrizes.

<storng><h4>Informações importantes:</h4></strong>
- Item de passagem livre (número 1 na posição da matriz);
- Item de dano, indicado pelo carácter ‘*’;
  - Ao encontrado o caractere ‘*’, obriga o algoritmo a voltar no estágio inicial de execução e reiniciar novamente do zero toda a execução.
- Paredes definidas como ‘#’, impede o acesso na posição correspondente;
- ‘?’ que indica o ponto de parada da exploração e que chegamos ao final do labirinto..

<strong><h4>Condições impostas: </h4></strong>
- A matriz a ser utlizada deve estar contida no arquivo input.data;
- A primeira linha do arquivo input.data deve conter o tamanho da matriz e a quantidade existente, seguindo esse modelo: ' 5 5 1';
  - a matriz deve ser quadrada.
  - a quantidade de matriz deve ser somente uma para o bom funcionamento do codigo, mas ainda assim deve conter na primiera linha a     quantidade de matriz
- Necessidade de possuir uma matriz contendo o numero 1 e somente dois tipos de caracteres são permitidos:
  - '#' -Representa parede
  - '*' -Representa dano


Informações importantes:
Item de passagem livre (número 1 na posição da matriz);
Item de dano, indicado pelo carácter ‘*’;
Ao encontrado o caractere ‘*’, obriga o algoritmo a voltar no estágio inicial de execução e reiniciar novamente do zero toda a execução.
Paredes definidas como ‘#’, impede o acesso na posição correspondente;
‘?’ que indica o ponto de parada da exploração e que chegamos ao final do labirinto.

Condições impostas:
A matriz a ser utlizada deve estar contida no arquivo input.data;
A primeira linha do arquivo input.data deve conter o tamanho da matriz e a quantidade existente, seguindo esse modelo: ' 5 5 1';
a matriz deve ser quadrada.
a quantidade de matriz deve ser somente uma para o bom funcionamento do codigo, mas ainda assim deve conter na primiera linha a quantidade de matriz
Necessidade de possuir uma matriz contendo o numero 1 e somente dois tipos de caracteres são permitidos:
'#' -Representa parede
'*' -Representa dano

## 📄Arquivos
- <strong>Main.cpp:</strong> É chamada a função que ira retronar o tamanho da matriz presente no arquivo input.data, e é nela que é chamado tambem as funções respectivas para cada algoritmos de busca: PercorrerMatrizRandomica, PercorrerMatrizLargura, PercorrerMatrizProfundidade.
- <strong>FunçõesArquivo.hpp:</strong> Criada as funções que irao manipular o arquivo input.data.
- <strong>FunçõesArquivo.cpp:</strong> Feita a estruturação das funções criadas no arquivo FunçõesArquivo.hpp.
- <strong>ItemLista.hpp:</strong> Criada a struct dos itens que iram conter na Lista.
- <strong>ItemMatriz.hpp:</strong> Criada a struct que irá conter o dados de cada posição da matriz, como cor o valor daquela posição e a linha e coluna que é aquela posição.
- <strong>Lista.hpp:</strong> Criado os arquivos que irao manipular a lista.
- <strong>Lista.cpp:</strong> Feita a estruturação das funções criadas no arquivo Lista.hpp
- <strong>MatrizLargura.hpp:</strong> Criada as funções para o funcionamento do algoritmo de busca em largura.
- <strong>MatrizLargura.cpp:</strong> Feita a estruturação das funções criadas no arquivo MatrizLargura.hpp.
- <strong>MatrizProfundidade.hpp:</strong> Criada as funções para o funcionamento do algoritmo de busca em profundidade.
- <strong>MatrizProfundidade.cpp:</strong> Feita a estruturação das funções criadas no arquivo MatrizProfundidade.hpp.
- <strong>MatrizRandomica.cpp:</strong> Criada as funções para o funcionamento do algoritmo de busca de forma randomica.
- <strong>MatrizRandomica.hpp:</strong> Feita a estruturação das funções criadas no arquivo MatrizRandomica.hpp.

## 🔨Resolução do problema
<h3><b>Busca randômica</b></h3>
<h3><b>Busca em largura</b></h3>

As funções principais foram: ```verFronteiras``` e ```PercorrerMatrizLargura```, nelas são feitas as implementações do desenvolvimento do código.

<b> Função verFronteiras </b>
essa função verifica quais posições são possíveis de serem acessadas e adicionadas na fila. A partir da posição atual, verifica-se as posições adjacentes e quais são caminháveis, ou seja, as casas que estão em branco e não são paredes. Caso isso aconteça, a condição do if é satisfeita e o item da matriz, contendo seu valor, cor e posição, é adicionado ao final da fila.
<!-- IMAGEMMMM da matriz dos vizinhos -->
<!-- TABELA DOS SENTIDOS de prioridade da inserção na fila -->

<b> Função PercorrerMatrizLargura </b>
inicialmente, é chamada a função ``` inicializarCores```, na qual a cor de todas as posições da matriz começa como branco, indicando que todas as posições ainda não foram visitadas. A iteração ocorre enquanto não for encontrado o caractere especial ('?'). Para encontrá-lo, primeiro é verificada sua posição atual. Caso seja perigoso ('*'), a posição se torna 1 e ele retorna para a posição inicial, excluindo a lista e todas as posições retornam para a cor branca. Caso contrário, são verificadas suas fronteiras utilizando a função verFronteiras. Os vizinhos são alterados para a cor cinza e salvos na fila. A partir do primeiro da fila, atualiza-se a posição atual percorrendo a matriz.

<h3><b>Busca em profundidade</b></h3>
De maneira geral nesse algoritmo de busca, a logica é feita a partir de TAG's que irao representar cada posição a ser tomada e suas funções principais são a `caminhoDisponivel` e `PercorrerMatrizProfundidade`, nela adotamos uma forma de caminhamento por TAG, a partir da TAG em que estivermos é a posição a ser seguida e salvamos sempre em uma fila, a partir disso tambem é possivel verificar se nao estamos voltando pelo mesmo caminho em que chegamos ate a posição, pois se estivermos deve ser retirado da fila a posição correspondente.<br>
- <b>OBS:</b>  A TAG sempre se inicializa com o caminhamento sendo para baixo.<br>

<b>Função 'PercorrerMatrizProfundidade'</b><br>
Inicialmente é inicializado todos os itens da matriz para a cor branca, logo apos a iteração ocorre ate que encontremos o caracter especial('?'), o caminhamento começa e olhamos se é uma posição possivel a ser seguida, se em caso de parede('#') devemos seguir outra direção, se em caso de um perigo('*'), devemos voltar à posição inicial, excluir todos os itens armazenados em nossa fila e reinciar todos os itens da matriz para a cor branca, já para o caso em que nenhuma das opções ditas sao satisfeitas é porque é um caminho possivel e podemos ir ate ele dessa forma mudamos a cor da posição correspondente para a cor cinza e adicionamos ao inicio da fila essa posição, pelo switch vamos saber qual posição seguiremos, pois em cada 'case' dele corresponde a uma posição que adotamos para o caminhamento na matriz, dentro de cada 'case', é verificado se podemos continuar no caminho pela TAG correspondete, por exemplo, se a TAG é o numero 5 (baixo), é verificado no case 5 se podemos continuar indo para baixo, se em caso negativo a TAG deverá mudar e iremos agora adotar uma nova direção a ser seguida, para isso é chamado a função `caminhoDisponivel` que nela ira retornar o numero para a TAG e a nova posição a ser seguida, isso ocorre ate que seja encontrado o caractere '?'. <br>
- <b>OBS:</b> O case 0 so ocorre quando visto que estivermos 'presos', ou seja, todas as posições ao nosso entorno são paredes, dessa maneira devemos desenfileirar a fila e a posição agora fica marcada com a cor preta e nao é possivel ser visitada novamente.<br>

<b>Função 'caminhoDisponivel'</b><br>
Essa função irá nos retornar a nova direção a ser seguida pelo algoritmo, nela é feita a verificação se a posição que vamos seguir nao é a que chegamos ate ela, pois se for deve ser feito o desenfileiramento da fila nela tambem é visto se estamos presos ou nao.

Caminhamento adotado pelas TAG:

<div align="center">

| TAG              | Direção                                                 |                     
| -----------------| --------------------------------------------------------|
| 0                |   Necessario desenfileirar a fila                       |
| 1                |   Cima                                                  |
| 2                |   Diagonal direita superior                             |
| 3                |   Direita                                               |
| 4                |   Diagonal direita inferior                             |
| 5                |   Baixo                                                 |
| 6                |   Diagonal esquerda inferior                            |
| 7                |   Esquerda                                              |
| 8                |   Diagonal esquerda superior                            |

<li>É seguido um caminhamento no sentido horario.</li>
<li>Outros valores diferentes dos mostrados na tabela podem levar ao mal funcionamento do código.</li>
</div>













<!-- O algoritmo BFS utiliza uma fila (queue) para armazenar os elementos a serem visitados. O algoritmo começa com um elemento inicial e o adiciona à fila. Em seguida, o algoritmo retira o primeiro elemento da fila e visita todos os seus vizinhos (elementos conectados a ele), adicionando-os à fila. O processo continua até que não haja mais elementos na fila para visitar. -->
