## Questão 3, página 314

#### Contextualização
Para resolver esse exercício foi usada uma variação do algoritmo de Shortest Path in a Graph (página 137), de modo que ele encontra o maior caminho, ao invés do menor, não sendo necessário o uso de programação dinâmica.
Durante o desenvolvimento da questão, também foi pensada uma forma recursiva de resolver o problema, porém sem um vetor ou matriz de memoização, o que tornou a complexidade do algorítmo muito alta.

#### Algoritmo
O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio3.cpp```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```, o resultado dos mesmos podem ser vistos na pasta ```output```.

Para compilar o código foram usadas as seguintes tags:
```-std=c++11 -O2 -Wall```

O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.

Por fim, para utilizá-lo basta seguir os passos:
```$g++ -std=c++11 -O2 -Wall exercicio13.cpp```
```$./a.out```

Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$./a.out < input/in*```, onde * deve ser substituído pelo valor 1, 2 ou 3.

Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .cpp.

Todos os debugs foram deixados comentados no projeto. Para vê-los, basta descomentá-los.
