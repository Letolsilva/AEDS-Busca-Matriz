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
Este é um programa desenvolvido em C++ para a disciplina de Algoritmo de Estrutura de Dados I. <br> 
O objetivo do programa é realizar o caminhamento em matrizes de três maneiras diferentes: aleatória, DFS (Busca em Profundidade) e BFS (Busca em Largura). Esses algoritmos de busca foram implementados para visitar todas as posições de uma matriz. <br>
O algoritmo de largura (BFS) é utilizado para verificar as posições adjacentes em relação a posição atual. A partir de uma matriz qualquer, o algoritmo opta por visitar todas as relações de adjacência a cada interação antes de avançar para uma nova posição.
Já o algoritmo de profundidade (DFS) utiliza a matriz para encontrar todas as posições alcançáveis a partir de uma determinada posição inicial. Esse algoritmo visita os vizinhos de uma posição atual até que não haja mais posições alcançáveis a partir dele, antes de avançar para outro vértice.<br> O algoritmo aleatório utiliza um caminhamento aleatório para explorar a matriz. Ele escolhe aleatoriamente uma das posições vizinhas para se mover. Esse processo é repetido até que todas as posições da matriz sejam visitadas. <br>
Ambos os algoritmos, BFS e DFS, foram implementados para percorrer uma matriz e visitar todas as suas posições.
</p>

## Objetivos

O objetivo desta atividade é desenvolver algoritmos que permitam que um programa encontre o caractere '?' (interrogação) em uma matriz que representa um labirinto, utilizando os algoritmos de busca em largura, profundidade e aleatória. Para isso, foi implementado algoritmos para visitar todas as posições da matriz a partir de uma posição inicial, adotada para todos os casos como: [0][0], e procurar pelo caractere '?' em cada uma dessas posições.
Para isto, ele deve executar matrizes quadradas no tamanho NxN, escritas no arquivo "dataset/input.data", iniciando na primeira matriz, começando a percorre-lá na posição inicial e continuar enquanto não encontrar o caracter. As matrizes, devem ser percorridas com os três modelos de caminhamento em matriz: randômico (adptado do labirindo recorrente), em largura (BFS) e em profundidade (DFS).

<h4>Condições </h4>

- Item de passagem livre (número 1 na posição da matriz).
- item de dano, indicado pelo carácter ‘*’.
- paredes definidas como ‘#’.
-  Caracter ‘?’ que indica o ponto de parada da exploração.























<!-- O algoritmo BFS utiliza uma fila (queue) para armazenar os elementos a serem visitados. O algoritmo começa com um elemento inicial e o adiciona à fila. Em seguida, o algoritmo retira o primeiro elemento da fila e visita todos os seus vizinhos (elementos conectados a ele), adicionando-os à fila. O processo continua até que não haja mais elementos na fila para visitar. -->
