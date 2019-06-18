#include <bits/stdc++.h>
#define MAX 50
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_array(x, _size) cerr << #x << ":"; for(int i=0; i<_size; ++i){cerr << " " << x[i];} cerr << endl;

using namespace std;

vector<int> nos;
int memo[MAX];

int peso_total(int quantidade_de_nos);
vector<pair<int, int>> backtrack_peso_total(int quantidade_de_nos);
int algoritmo_a(vector<int> copia_nos);
int algoritmo_b(int quantidade_de_nos);


int main(){
	memset(memo, -1, sizeof memo);
	int N;
	cerr << "Insira a quantidade de nós do path: ";
	cin >> N;
	for(int i=0; i<N; ++i){
		cerr << "Insira o peso do nó " << i+1 << ": ";
		int peso;
		cin >> peso;
		nos.push_back(peso);
	}
	cerr << endl;
	
	int peso_final = algoritmo_a(nos);
	cout << "Peso total a partir do algoritmo (a): " << peso_final << endl;

	peso_final = algoritmo_b(N);
	cout << "Peso total a partir do algoritmo (b): " << peso_final << endl;

	peso_final = peso_total(N-1);
	//debug_array(memo, 5);
	vector<pair<int, int>> backtrack = backtrack_peso_total(N-1);
	cout << "Peso total = " << peso_final << endl;
	int _size = backtrack.size();
	//debug(_size);
	cout << "O conjunto de nós escolhido foi: (";
	for(int i=0; i<_size; ++i){
		cout << backtrack[i].first+1 << (i+1==_size? ")\n":", ");
	}
}


int peso_total(int quantidade_de_nos){
	//debug_array(memo, 5);
	if(memo[quantidade_de_nos]!= -1) return memo[quantidade_de_nos];
	return memo[quantidade_de_nos] = max(peso_total(quantidade_de_nos-1),
								peso_total(quantidade_de_nos-2) + nos[quantidade_de_nos]); 
}

vector<pair<int, int>> backtrack_peso_total(int quantidade_de_nos){
	vector<pair<int, int>> backtrack;
	int i;
	for(i= quantidade_de_nos; i>0;){
		if(memo[i] == memo[i-1]){
			i--;
		}
		else{
			backtrack.emplace_back(i, nos[i]);
			i-=2;
		}
	}
	if(!i){
		backtrack.emplace_back(i, nos[i]);
	}
	reverse(backtrack.begin(), backtrack.end());
	return backtrack;
}

int algoritmo_a(vector<int> copia_nos){
	int peso_total = 0;
	while(!copia_nos.empty()){
		int maior = -1, posicao_maior = -1;
		int _size = copia_nos.size();
		for(int i=0; i< _size; ++i){
			if(copia_nos[i] > maior){
				maior = copia_nos[i];
				posicao_maior = i;
			}
		}
		peso_total += maior;
		if(posicao_maior > 0&&posicao_maior+1 < _size){
			copia_nos.erase(copia_nos.begin() + (posicao_maior-1),
							copia_nos.begin() + (posicao_maior+2));
		}
		else if(posicao_maior > 0){
			copia_nos.erase(copia_nos.begin() + (posicao_maior-1),
							copia_nos.begin() + posicao_maior+1);
		}
		else if(posicao_maior+1 < _size){
			copia_nos.erase(copia_nos.begin() + posicao_maior,
							copia_nos.begin() + (posicao_maior+2));	
		}
		else{
			copia_nos.erase(copia_nos.begin() + posicao_maior);
		}
		//debug(maior);
		//debug(posicao_maior);
		//debug_array(copia_nos, copia_nos.size());

	}
	return peso_total;
}

int algoritmo_b(int quantidade_de_nos){
	int soma_impar = 0, soma_par = 0;
	for(int i=1; i<=quantidade_de_nos; ++i){
		if(i%2){
			soma_impar += nos[i-1];
		}
		else{
			soma_par += nos[i-1];
		}
	}
	return max(soma_par, soma_impar);
}