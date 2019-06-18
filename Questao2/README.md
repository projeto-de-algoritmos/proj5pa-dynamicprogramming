## Questão 2, página 312

**2.** Suppose you’re managing a consulting team of expert computer hackers, and each week you have to choose a job for them to undertake. Now, as you can well imagine, the set of possible jobs is divided into those that are low-stress (e.g., setting up a Web site for a class at the local elementary school) and those that are high-stress (e.g., protecting the nation’s most valuable secrets, or helping a desperate group of Cornell students finish a project that has something to do with compilers). The basic question, each week, is whether to take on a low-stress job or a high-stress job.
<p align="justify">&emsp;&emsp;
If you select a low-stress job for your team in week i, then you get a
revenue of li > 0 dollars; if you select a high-stress job, you get a revenue of hi > 0 dollars. The catch, however, is that in order for the team to take on a high-stress job in week i, it’s required that they do no job (of either type) in week i − 1; they need a full week of prep time to get ready for the crushing stress level. On the other hand, it’s okay for them to take a low- stress job in week i even if they have done a job (of either type) in week i − 1.
<p align="justify">&emsp;&emsp;
So, given a sequence of n weeks, a plan is specified by a choice of
“low-stress,” “high-stress,” or “none” for each of the n weeks, with the property that if “high-stress” is chosen for week i > 1, then “none” has to be chosen for week i − 1. (It’s okay to choose a high-stress job in week 1.) The value of the plan is determined in the natural way: for each i, you add li to the value if you choose “low-stress” in week i, and you add hi to the value if you choose “high-stress” in week i. (You add 0 if you choose “none” in week i.)
<p align="justify">&emsp;&emsp;
**The problem.** Given sets of values l1 , l2 , . . . , ln and h1 , h2 , . . . , hn , find a plan of maximum value. (Such a plan will be called optimal.)
**Example.** Suppose n = 4, and the values of li and hi are given by the following table. Then the plan of maximum value would be to choose
“none” in week 1, a high-stress job in week 2, and low-stress jobs in weeks 3 and 4. The value of this plan would be 0 + 50 + 10 + 10 = 70

|     | Week 1 | Week 2 | Week 3 | Week 4 |
| :-: | :----: | :----: | :----: | :----: |
|  l  |   10   |    1   |   10   |    10  |
|  h  |    5   |   50   |    5   |     1  |

<p align="justify">&emsp;

**(a)** Show that the following algorithm does not correctly solve this
problem, by giving an instance on which it does not return the correct
answer.
```
For iterations i = 1 to n
	If h i+1 >  i +  i+1 then
		Output "Choose no job in week i "
		Output "Choose a high-stress job in week i + 1 "
		Continue with iteration i + 2
	Else
		Output "Choose a low-stress job in week i "
		Continue with iteration i + 1
	Endif
End
```

<p align="justify">&emsp;&emsp;
To avoid problems with overflowing array bounds, we define
hi = li = 0 when i > n.
<p align="justify">&emsp;&emsp;
In your example, say what the correct answer is and also what
the above algorithm finds.

<p align="justify">&emsp;
**(b)** Give an efficient algorithm that takes values for l1 , l2 , . . . , ln and h1 , h2 , . . . , hn and returns the value of an optimal plan.

#### Contextualização
Esse problema tem um ponto específico que forma o padrão de árvore encontrado nos algorítmos de DP. O fator de um serviço high ter de ser precedido por um dia sem serviço gera a ambiguidade na questão, sendo a base da árvore, que pode ser descrito na questão "realizar o serviço pesado ou não" e, desse modo, gerar a recursão de (week atual - 2 + valor do serviço pesado) ou week atual - 1 + valor do serviço leve). 

#### Algoritmo
O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio2.cpp```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```, o resultado dos mesmos podem ser vistos na pasta ```output```.

Para compilar o código foram usadas as seguintes tags:
```-std=c++11 -O2 -Wall```

O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.

Por fim, para utilizá-lo basta seguir os passos:
```$g++ -std=c++11 -O2 -Wall exercicio13.cpp```
```$./a.out```

Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$./a.out < input/in*```, onde * deve ser substituído pelo valor 1 ou 2.

Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .cpp.

Todos os debugs foram deixados comentados no projeto. Para vê-los, basta descomentá-los.
