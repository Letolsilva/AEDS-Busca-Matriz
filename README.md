<h1 align="center" font-size="200em"><b>Busca DFS, BFS e randômica</b></h1>

<div align = "center" >
<!-- imagem -->

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## 📌Sumário
- [Introdução](#Introdução)
- [Objetivos](#Objetivos)
- [Problema apresentado](#Problema-apresentado)
- [Arquivos](#Arquivos)
- [Resolução do Problema](#Resolução-do-problema)
- [Resultados](#Resultados)
- [Conclusão](#Conclusão)
- [Compilação e execução](#Compilação-e-execução)
- [Contato](#Contato)

## ✒️Introdução
<p align="justify">
Este é um programa desenvolvido em C++ para a disciplina de Algoritmos e Estruturas de Dados I. O objetivo do programa é realizar o caminhamento em matrizes de três maneiras diferentes: aleatória, DFS (Busca em Profundidade) e BFS (Busca em Largura). Esses algoritmos de busca foram implementados de modo que ache a posição que contenha o caracter especial '?'.<br>
O algoritmo de largura (BFS) é utilizado para verificar as posições adjacentes a partir da posição atual. A partir de uma matriz qualquer, o algoritmo opta por visitar todas as relações de adjacência a cada interação antes de avançar para uma nova posição. Já o algoritmo de profundidade (DFS) utiliza a matriz para encontrar todas as posições alcançáveis, num mesmo sentido de caminhamento, a partir de um determinado vértice inicial. Esse algoritmo percorre uma mesma direção até que não seja mais possível andar, antes de trocar de sentido de caminhamento. <br> 
O algoritmo aleatório utiliza um caminhamento randomizado para explorar a matriz. Ele escolhe aleatoriamente uma das posições vizinhas para se mover e esse processo se repete até que seja encontrado o caracter especial.<br>
</p>

## 💻Objetivos

O objetivo desta atividade é desenvolver algoritmos que permitam que um programa encontre o caractere '?' (interrogação) em uma matriz que representa um labirinto, utilizando os algoritmos de busca em largura, profundidade e aleatória. Para isso, foram implementados algoritmos para percorres uma matriz a partir de uma posição inicial, adotada para todos os casos como: [0][0], e procurar pelo caractere '?' em cada uma dessas matrizes.

<storng><h4>Informações importantes:</h4></strong>
- Item de passagem livre (número 1 na posição da matriz);
- Item de dano, indicado pelo caractere ‘*’;
  - Ao encontrar o caractere ‘*’, o algoritmo é obrigado a voltar no estágio inicial de execução e reiniciar novamente do zero toda a execução.
- Paredes definidas como ‘#’, impedem o acesso na posição correspondente;
- ‘?’ indica o ponto de parada da exploração e que chegamos ao final do labirinto.

<strong><h4>Condições impostas: </h4></strong>
- A matriz a ser utlizada deve estar contida no arquivo ```input.data```;
- A primeira linha do arquivo ```input.data``` deve conter o tamanho da matriz e a quantidade existente, seguindo esse modelo: '5 5 1';
  - A matriz deve ser quadrada;
  - A quantidade de matriz é representada somente para um bom funcionamento do código e deve estar na primeira linha;
- Necessidade de possuir uma matriz contendo o número 1 e somente dois tipos de caracteres:
  - '#' - Representa parede
  - '*' - Representa dano

## 📄Arquivos
- <strong>Main.cpp:</strong> É chamada a função que irá retronar o tamanho da matriz presente no arquivo input.data, e é nela que é chamase as funções respectivas para cada algoritmos de busca: ```PercorrerMatrizRandomica```, ```PercorrerMatrizLargura```, ```PercorrerMatrizProfundidade```.
- <strong>FuncoesArquivo.hpp:</strong> Criada as funções que irão manipular o arquivo input.data.
- <strong>FunçõesArquivo.cpp:</strong> Feita a estruturação das funções criadas no arquivo FuncoesArquivo.hpp.
- <strong>ItemLista.hpp:</strong> Criada a struct dos itens contidos na Lista.
- <strong>ItemMatriz.hpp:</strong> Criada a struct que irá conter o dados de cada posição da matriz, como cor, o valor daquela posição e a linha e coluna correspondentes àquele item.
- <strong>Lista.hpp:</strong> Criação da struct que representa a lista e das funções que a manipulam.
- <strong>Lista.cpp:</strong> Feita a estruturação das funções criadas no arquivo Lista.hpp
- <strong>MatrizLargura.hpp:</strong> Criada as funções para o funcionamento do algoritmo de busca em largura.
- <strong>MatrizLargura.cpp:</strong> Feita a estruturação das funções criadas no arquivo MatrizLargura.hpp.
- <strong>MatrizProfundidade.hpp:</strong> Criada as funções para o funcionamento do algoritmo de busca em profundidade.
- <strong>MatrizProfundidade.cpp:</strong> Feita a estruturação das funções criadas no arquivo MatrizProfundidade.hpp.
- <strong>MatrizRandomica.cpp:</strong> Criada as funções para o funcionamento do algoritmo de busca de forma randômica.
- <strong>MatrizRandomica.hpp:</strong> Feita a estruturação das funções criadas no arquivo MatrizRandomica.hpp.
- <strong>Arquivos Output:</strong> Após os caminhamentos, cria-se arquivos para salvar as matrizes modificadas, sendo eles: `outputLargura.data`, `outputProfunidade.data`, `outputRandomica.data`.

## 🔨Resolução do problema
<h3><b>Implementação da lista</b></h3>

*Arquivos lista.hpp e lista.cpp*<br>
- ```init```: inicialização da lista.
- `insertEnd`: insere ao final da lista.
- `insertInicio`: insere ao início da lista.
- `LImprime`: imprime a lista.
- `ListaVazia`: retorna se a lista está vazia ou não.
- `removerItemInicio`: remove item do início da lista.
- `excluirLista`: libera a memória da lista.

Para a busca em largura, a lista é implementada como uma fila, e como uma pilha para a busca em profundidade.

<h3><b>Busca randômica</b></h3>
<strong>Explicação detalhada da função 'PercorrerMatrizRandomica':</strong><br>
Essa função tem como criterio de decisão qual direção o algoritmo adotará, feita por switch's, sendo cada 'case' uma direção possivel.

- Ela é realizada por um loop somente para quando atingimos a posição com o caractere '?'.
- É gerado um numero randomico entre 0 a 7 e que cada um representara a decisao de direção a ser seguida.
- É tratado os casos de extremidades da matriz, quando gerado um numero em que a posição nao é possivel ser seguida, que é a existencia de parede(#), é gerado um outro numero aleatorio ate que seja possivel o personagem se mover.
- É visto se a posição em que o personagem irá é um perigo(*) ou um item(numero 1), se em caso de perigo, ele troca essa posição pelo numero 1 e irá retorna à posição inicial e começa novamente o caminhamento, se nao ocorrer de nem ser parede e nem perigo é sinal de que é uma posição que pode ser acessada e ele pode ir ate ela.

<p align="center">
<strong><em>Direçãoes possiveis em cada 'case' presente no switch </em></strong>
</p>

<table border="1" align="center">
  <tr>
      <td><strong>Case</strong></td>
      <td><strong>Direção</strong></td>
  </tr>
  <tr>
      <td>0</td>
      <td>Direta</td>
  </tr>
  <tr>
      <td>1</td>
      <td>Esquerda</td>
  </tr>
  <tr>
      <td>2</td>
      <td>Cima</td>
  </tr>
  <tr>
      <td>3</td>
      <td>Baixo</td>
  </tr>
  <tr>
      <td>4</td>
      <td>Diagonal esquerda superior.</td>
  </tr>
  <tr>
      <td>5</td>
      <td>Diagonal direita superior.</td>
  </tr>
  <tr>
      <td>6</td>
      <td>Diagonal esquerda inferior</td>
  </tr>
  <tr>
      <td>7</td>
      <td>Diagonal direita inferior.</td>
  </tr>
</table>

<h3>Informações importantes</h3>

 - Ao encontrado com um perigo ('*') a posição do perigo e trocada para o numero 1.<br>
 - É criado um arquivo `outputRandomico.data`, que ira armazenar a matriz modificada ou nao ao final do jogo, dessa maneira o usuario poderá comparar com as matrizes presente no arquivo `input.data` e ver as posições que foram acessadas pelo personagem.<br>

<div align="center">
  <img src="imgs/Rand1.png" alt="Rand2" width=300px>
  <img src="imgs/Rand2.png" alt="Rand1" width=300px>
</div>

<h3>Exemplo de uma busca randômica:</h3>
<div align="center">
  <img src="imgs/GifRandomico.gif.gif" alt="gif" width=300px>
</div>

<h3><b>Busca em largura</b></h3>

As funções principais foram: ```verFronteiras``` e ```PercorrerMatrizLargura```, nelas são feitas as implementações do desenvolvimento do código.

<b> Função verFronteiras </b>
Essa função verifica quais posições são possíveis de serem acessadas e adicionadas na fila. A partir da posição atual, verifica-se as posições adjacentes e quais são caminháveis, ou seja, as casas que estão em branco e não são paredes. Caso isso aconteça, a condição do if é satisfeita e o item da matriz, contendo seu valor, cor e posição, é adicionado ao final da fila.
<!-- IMAGEMMMM da matriz dos vizinhos -->
Segue-se a seguinte ordem de prioridade para inserção dos vizinhos na fila:
<div align="center">

| Prioridade       | Direção                                                 |                     
| -----------------| --------------------------------------------------------|
| 1                |   Cima                                                  |
| 2                |   Diagonal direita superior                             |
| 3                |   Direita                                               |
| 4                |   Diagonal direita inferior                             |
| 5                |   Baixo                                                 |
| 6                |   Diagonal esquerda inferior                            |
| 7                |   Esquerda                                              |
| 8                |   Diagonal esquerda superior                            |
</div>

<div align="center">
  <img src="imgs/Largura.png" alt="BuscaEmLargura" width=300px>
  <p align="center"><em> Cada cor representa as posições que foram salvas na fila e a sequência em que foram colocadas.</em></p>
</div>

<b> Função PercorrerMatrizLargura </b>
Inicialmente, é chamada a função ```inicializarCores```, na qual a cor de todas as posições da matriz começa como branco, indicando que todas as posições ainda não foram visitadas. A iteração ocorre enquanto não for encontrado o caractere especial ('?'). Para encontrá-lo, primeiro é verificada sua posição atual, caso seja perigoso ('*'), a posição se torna 1 e ele retorna para a posição inicial, excluindo a lista e todas as posições retornam para a cor branca. Caso contrário, são verificadas suas fronteiras utilizando a função verFronteiras. Os vizinhos são alterados para a cor cinza e salvos na fila. A partir do primeiro da fila, atualiza-se a posição atual percorrendo a matriz, ou seja, a lista é utilizada como se fosse uma fila

<h3><b>Busca em profundidade</b></h3>
De maneira geral nesse algoritmo de busca, a lógica é feita a partir de TAG's que irão representar cada direção a ser tomada e suas funções principais são `caminhoDisponivel` e `PercorrerMatrizProfundidade`, nela adotamos uma forma de caminhamento por TAG, que é um inteiro que indica a direção de caminhamento a ser seguida. As posições percorridas são inseridas na pilha (modo de implementação da lista para esse tipo de busca), e a partir dela checa-se que, após chegarmos em um limite da matriz ou bater em uma parede, caso o único caminho disponível seja voltar por onde chegamos até a posição, deve-se desempilhar um item e fazer verificações até que haja outro caminho possível.<br>

- <b>OBS:</b>  A TAG sempre é inicializada com o caminhamento sendo para baixo.<br>

<b>Função 'PercorrerMatrizProfundidade'</b><br>
Inicialmente, são inicializados todos os itens da matriz com cor branca, depois a iteração ocorre até que encontremos o caracter especial('?'). O caminhamento começa e olhamos se é uma posição possivel a ser seguida, em caso de parede('#') devemos seguir outra direção, em caso de um perigo('*'), devemos voltar à posição inicial, excluir todos os itens armazenados em nossa pilha e reinciar todos os itens da matriz para a cor branca, já para o caso em que nenhuma das opções ditas são satisfeitas é porque é um caminho possivel e podemos percorrê-lo. Dessa forma, mudamos a cor da posição correspondente para cinza e adicionamos-a ao inicio da pilha, com switch vamos saber qual posição seguiremos, pois em cada 'case' corresponde à uma posição que adotamos para o caminhamento na matriz e nele é verificado se podemos continuar no caminho pela TAG correspondete, por exemplo, se a TAG é o numero 5 (baixo), é verificado no case 5 se podemos continuar indo para baixo, se em caso negativo a TAG deverá mudar e iremos agora adotar uma nova direção a ser seguida, para isso é chamado a função `caminhoDisponivel` que ela irá retornar o novo número para a TAG e a nova direção a ser seguida, esse procedimento ocorre até que seja encontrado o caractere '?'. <br>

<b>Função 'caminhoDisponivel'</b><br>
Essa função irá nos retornar a nova direção a ser seguida pelo algoritmo, nela é feita a verificação se a direção que vamos seguir não é mesma em que chegamos, pois se for, deve ser feito a exclusão da pilha, e vê-se se estamos encurralados entre paredes

Prioridade adotada pela TAG:

<div align="center">

| TAG              | Direção                                                 |                     
| -----------------| --------------------------------------------------------|
| 0                |   Necessário desenfileirar a fila                       |
| 1                |   Cima                                                  |
| 2                |   Diagonal direita superior                             |
| 3                |   Direita                                               |
| 4                |   Diagonal direita inferior                             |
| 5                |   Baixo                                                 |
| 6                |   Diagonal esquerda inferior                            |
| 7                |   Esquerda                                              |
| 8                |   Diagonal esquerda superior                            |
</div>
- <b>OBS:</b> O case 0 so ocorre quando visto que estivermos 'presos', ou seja, todas as posições ao nosso entorno são paredes, dessa maneira devemos excluir a pilha e a posição fica marcada com a cor preta, pois não deve ser visitada novamente.<br>
<li>É seguido uma ordem de prioridade do caminhamento no sentido horario.</li>
<li>Outros valores diferentes dos mostrados na tabela podem levar ao mau funcionamento do código.</li>

<div align="center">
  <img src="imgs/Profundidade.png" alt="Pasta Dataset" width=300px>
  <p align="center"><em> Cada cor representa uma direção a ser tomada por vez. <br> Os números representam as TAG's, conforme a tabela acima.</em></p>
</div>

## 🎯Resultados
Ao final das buscas, é impresso no terminal a posição em que o caracter especial foi encontrado, o tempo de execução e o número de passos dados de determinada busca.
Para calcularmos o tempo de execução de cada tipo de busca, utilizamos a biblioteca `chrono`, que mede o tempo decorrido entre dois pontos do código. Criou-se uma variável para salvar o tempo inicial e à medida em que as matrizes eram percorridas, o tempo atual é salvo e a duração da execução é gerada pela diferença entre ele e o tempo inicial. A ordem de execução foi: busca randômica, busca em largura e busca em profundidade, sendo que para as duas últimas situações, a duração da execução é calculada a partir da diferença entre o tempo final, o tempo inicial e o tempo de execução das buscas anteriores. Por exemplo, para calcular o tempo de execução da busca em profundidade, fez-se: `Duração = Tempo final - tempo inicial - duração busca em largura - duração busca randômica`.
Para os resultados abaixo, foi utilizada uma matriz de tamanho 50x50, sendo a situação padrão dos perigos e paredes disponível em `input.data`
- Matriz com `?` na última posição - Situação padrão
  - Busca randômica: 5.70 ms e 53757 passos
  - Busca em largura: 35.58 ms e 51210 passos
  - Busca em profundidade: 5.32 ms e 18860 passos
- Matriz com `?` no meio
  - Situação padrão 
    - Busca randômica: 2.06 ms e 904 passos
    - Busca em largura: 5.46 ms e 3328 passos
    - Busca em profundidade: 11.46 ms e 29172 passos
  - Número de perigos maior
    - Busca randômica: 6.80 ms e 42185 passos
    - Busca em largura: 48.85 ms e 62780 passos
    - Busca em profundidade: 86.83 ms e 441880 passos
  - Número de paredes maior
    - Busca randômica: 2.76 ms e 14108 passos
    - Busca em largura: 3.98 ms e 1690 passos
    - Busca em profundidade: 7.73 ms e 25015 passos
- Matriz com `?` na posição [0][1] - Situação padrão
  - Busca randômica: 0.94 ms e 183 passos
  - Busca em largura: 2.78 ms e 1 passo
  - Busca em profundidade: 8.70 ms e 26471 passos

**Relações**
- Matriz com `?` na última posição - Situação padrão
  - A busca em largura é 524.2% mais devagar que a busca randômica
  - A busca em profundidade é 6.7% mais rápida que a busca randômica
- Matriz com `?` no meio
  - Situação padrão
    - A busca em largura é 165% mais devagar que a busca randômica
    - A busca em profundidade é 456.3% mais devagar que a busca randômica
  - Número de perigos maior
    - A busca em largura é 618.4$ mais devagar que a busca randômica
    - A busca em profundidade é 1177% mais devagar que a busca randômica
  - Número de paredes maior
    - A busca em largura é 44.2% mais devagar que a busca randômica
    - A busca em profundidade é 180% mais devagar que a busca randômica
- Matriz com `?` na posição [0][1] - Situação padrão
  - A busca em largura é 195% mais devagar que a busca randômica
  - A busca em profundidade é 825.5% mais devagar que a busca randômica
## ✔️Conclusão
Ao final deste código, pode-se observar que as buscas randômicas, BFS e a DFS são muito diferentes e têm aplicações muito distintas.
A diferença mais marcante entre as buscas está nas estruturas de dados auxiliares empregadas pelas duas estratégias. Enquanto a busca randômica não segue um caminho previsível e percorre aleatoriamente, a BFS utiliza uma fila de posições, e a DFS utiliza uma pilha, sendo possível estimar o percurso realizado por ambas as estratégias com base na entrada e na matriz a ser percorrida. Além disso, podemos observar que  a DFS visita todas as posições de uma matriz sem interferência da posição inicial, enquanto a BFS visita apenas as posições que estão ao alcance da posição inicial. Essas características nos permitem analisar em quais casos cada algoritmo é ideal. Por exemplo, se soubermos que a solução (representada pelo caractere '?'), está em algum lugar longe do vértice de origem da matriz, usamos o DFS. Se soubermos que a solução não está tão longe da origem, usamos o BFS.

Em relação a complexidade do tempo, podemos calcular de maneira geral que o DFS e o BFS possuem uma complexidade de O(V + E), onde V e E são o número total de vértices e arestas no grafo, respectivamente, em uma matriz V seria as posições e E a quantidade de passos.

Em relação aos tempos de execução e o número de passos, podemos obter as seguintes relações: Para a matriz com `?` na última posição da situação padrão, a busca em profundidade é a melhor opção, já que percorre menos posições em menos tempo em relação aos outros tipos de busca. Quando `?` está no meio, na situação padrão e quando aumenta-se o número de perigos, a busca randômica é a melhor opção, porém quando aumenta-se o número de paredes, apesar de a busca em largura ser 44.2% mais lenta que a busca randômica, a situação aleatória possui um número de passos 88% maior. A busca em largura gasta mais tempo devido à manipulação da fila e verificação das fronteiras, mas na busca propriamente dita, na situação do aumento de paredes, ela mostra-se mais eficiente por achar `?` em menos movimentações. Finalmente, quanto `?` está na posição [0][1] da situação padrão, a busca em profundidade tem uma diferença discrepante no tempo de execução devido ao caminhamento começar para baixo. Ainda nesse caso, a busca em largura é a melhor opção, pois apesar de ser 195% mais devagar do que a busca randômica devido à manipulação da fila e verificação das fronteiras, com ela é possível achar `?` em somente um passo, já que na ordem de prioridade das direções possíveis no começo, a direita ([0][1]) vem primeiro.

## 👾Compilação e execução
* Especificações da máquina em que o código foi rodado:
  * Processador Intel Core i5, 7th Gen;
  * Sistema Operacional Windows 10;
  * Terminal do WSL: Ubuntu 20.04.5;
  * 8GB de RAM.
* | Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
  |  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## 📞Contato
<div>
 <p align="justify"> Julia Rezende</p>
 <a href="https://t.me/juliarezende34">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:juliarezende34@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>juliarezende34@gmail.com</i>
</a>
 
<div>
 <br><p align="justify"> Jullia Fernandes</p>
 <a href="https://t.me/JulliaFernandes">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:julliacefet@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>julliacefet@gmail.com</i>
</a>

<div>
 <br><p align="justify"> Letícia de Oliveira</p>
 <a href="https://t.me/letolsilva">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:letolsilva22@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>letolsilva22@gmail.com</i>
</a>

