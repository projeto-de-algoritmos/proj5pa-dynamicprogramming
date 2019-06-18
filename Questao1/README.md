## Questão 1, página 312

**1.** Let _G = (V , E)_ be an undirected graph with _n_ nodes. Recall that a subset of the nodes is called an independent set if no two of them are joined by an edge. Finding large independent sets is difficult in general; but here we’ll see that it can be done efficiently if the graph is “simple” enough. 
<p align="justify">&emsp;&emsp;
Call a graph _G = (V , E)_ a path if its nodes can be written as _V1 , V2 , . . . , Vn_ , with an edge between _Vi_ and _Vj_ if and only if the numbers _i_ and _j_ differ by exactly 1. With each node _Vi_ , we associate a positive integer **weight** _Wi_ .
<p align="justify">&emsp;&emsp;
Consider, for example, the five-node path drawn in Figure 6.28. The
_weights_ are the numbers drawn inside the nodes.
<p align="justify">&emsp;&emsp;
The goal in this question is to solve the following problem:
<p align="justify">&emsp;&emsp;
_Find an independent set in a path G whose total weight is as large as possible._
<p align="justify">&emsp;

**(a)** Give an example to show that the following algorithm does not always find an independent set of maximum total weight.
```
The "heaviest-first" greedy algorithm
	Start with S equal to the empty set
	While some node remains in G
		Pick a node v i of maximum weight
		Add v i to S
		Delete v i and its neighbors from G
	Endwhile
Return S
```
<p align="justify">&emsp;

**(b)** Give an example to show that the following algorithm also does not always find an independent set of maximum total weight.
```
Let S 1 be the set of all v i where i is an odd number
Let S 2 be the set of all v i where i is an even number
(Note that S 1 and S 2 are both independent sets)
Determine which of S 1 or S 2 has greater total weight, and return this one
```

<p align="justify">&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
1 <-> 8 <-> 6 <-> 3 <-> 6


**Figure 6.28** A paths with weights on the nodes. The maximum weight of an independent set is 14.

#### Contextualização
Ao analisar os possíveis casos de conjuntos indepentes formados em caminhos simples nota-se o padrão de duas escolhas válidas para cada nó existente, essas escolhas são: utilizá-lo no conjunto ou não.
Esse padrão é muito semelhante ao encontrado no caso do _Weighted Interval Scheduling_, encontrado no próprio livro, e, a partir disso, é possível encontrar um algorítmo similar, que faz a busca por todos os casos possíveis e encontra o melhor caminho em tempo linear.

#### Algoritmo
O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio1.cpp```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```, o resultado dos mesmos podem ser vistos na pasta ```output```.

Para compilar o código foram usadas as seguintes tags:
```-std=c++11 -O2 -Wall```

O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.

Por fim, para utilizá-lo basta seguir os passos:
```$g++ -std=c++11 -O2 -Wall exercicio13.cpp```
```$./a.out```

Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$./a.out < input/in*```, onde * deve ser substituído pelo valor 1, 2, 3 ou 4.

Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .cpp.

Todos os debugs foram deixados comentados no projeto. Para vê-los, basta descomentá-los.
