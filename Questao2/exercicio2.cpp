#include <bits/stdc++.h>
#define MAX 50
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_array(x, _size) cerr << #x << ":"; for(int i=0; i<_size; ++i){cerr << " " << x[i];} cerr << endl;

using namespace std;

vector<int> trabalhos_leves;
vector<int> trabalhos_pesados;
int memo[MAX];

int valor_maximo(int quantidade_de_servicos);
vector<pair<int, int>> backtrack_valor_maximo(int quantidade_de_servicos);
int algoritmo_a(int quantidade_de_servicos);


int main(){
	memset(memo, -1, sizeof memo);
	int N;
	cerr << "Insira a quantidade de semanas de trabalho: ";
	cin >> N;
	for(int i=0; i<N; ++i){
		cerr << "Insira  o valor  do serviço leve " << i+1 << ": ";
		int valor;
		cin >> valor;
		trabalhos_leves.push_back(valor);

		cerr << "Insira o valor do serviço pesado " << i+1 << ": ";
		cin >> valor;
		trabalhos_pesados.push_back(valor);
	}
	trabalhos_leves.push_back(0);
	trabalhos_pesados.push_back(0);
	cerr << endl;

	int valor_total = algoritmo_a(N);
	cout << "Valor máximo a partir do algoritmo (a): " <<
	valor_total << endl << endl;

	valor_total = valor_maximo(N-1);
	debug_array(memo, 5);
	vector<pair<int, int>> backtrack = backtrack_valor_maximo(N);
	int _size = backtrack.size();
	//debug(_size);
	cout << "O serviços escolhido foram:\n";
	for(int i=0; i<_size; ++i){
		cout << "Semana " << i+1 << ": ";
		if(backtrack[i].first == 1){
			cout << "Leve, com valor R$" << backtrack[i].second;
		}
		else if(backtrack[i].first == 2){
			cout << "Pesado, com valor R$" << backtrack[i].second;
		}
		else{
			cout << "Nenhum";
		}
		cout << ".\n";
	}
	cout << "Total = R$" << valor_total << endl;
}


int valor_maximo(int quantidade_de_servicos){
	debug_array(memo, 5);
	if(quantidade_de_servicos < 0) return 0;
	if(memo[quantidade_de_servicos]!= -1) return memo[quantidade_de_servicos];
	return memo[quantidade_de_servicos] = max(valor_maximo(quantidade_de_servicos-1) +
											  trabalhos_leves[quantidade_de_servicos],
											  valor_maximo(quantidade_de_servicos-2) +
											  trabalhos_pesados[quantidade_de_servicos]);
}

vector<pair<int, int>> backtrack_valor_maximo(int quantidade_de_servicos){
	vector<pair<int, int>> backtrack(quantidade_de_servicos);
	int i;
	for(i= quantidade_de_servicos-1; i>0;){
		if(memo[i] - trabalhos_leves[i] == memo[i-1]){
			backtrack[i] = {1, trabalhos_leves[i]};
			i--;
		}
		else{
			backtrack[i] = {2, trabalhos_pesados[i]};
			i-=2;
		}
	}
	if(!i){
		if(memo[i] == trabalhos_leves[i]){
			backtrack[i] = {1, trabalhos_leves[i]};
			i--;
		}
		else{
			backtrack[i] = {2, trabalhos_pesados[i]};
			i-=2;
		}
	}
	return backtrack;
}

int algoritmo_a(int quantidade_de_servicos){
	int valor_total = 0;
	for(int i=0; i<quantidade_de_servicos;){
		if(trabalhos_pesados[i+1] >
		   trabalhos_leves[i] + trabalhos_leves[i+1]){
			valor_total += trabalhos_pesados[i+1];
			i+=2;
		}
		else{
			valor_total += trabalhos_leves[i];
			i++;
		}
	}
	return valor_total;
}