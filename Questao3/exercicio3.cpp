#include <bits/stdc++.h>
#define MAX 50
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_array(x, _size) cerr << #x << ":"; for(int i=0; i<_size; ++i){cerr << " " << x[i];} cerr << endl;

using namespace std;

using ii = pair<int, int>;

vector<int> grafo[MAX];
int distancias[MAX];

int longest_path(int inicio, int destino, int N);
int algoritmo_a(int inicio, int cumprimento);

int main(){
	int N, M;
	cerr << "Insira a quantidade de vértices do grafo: ";
	cin >> N;
	cerr << "Insira a quantidade de arestas do grafo: ";
	cin >> M;

	for(int i=0; i<M; ++i){
		cerr << "Insira os vértices da aresta " << i+1 << ": ";
		int no1, no2;
		cin >> no1 >> no2;
		grafo[no1].push_back(no2);
	}
	cerr << endl;
	
	cout << "Caminho mais longo a partir do algoritmo dado: ";
	cout << algoritmo_a(1, 0) << endl;

	cout << "Caminho mais longo a partir do criado: ";
	cout << longest_path(1, N, N) << endl;
	//debug_array(distancias, MAX);
}

int longest_path(int inicio, int destino, int N) {
    memset(distancias, -1, sizeof distancias);

    priority_queue<ii> para_visitar;

    distancias[inicio] = 0;
    para_visitar.push(ii(distancias[inicio], inicio));

    while(!para_visitar.empty()) {
        // Distancia d :: Veritice v
        auto distancia_atual = para_visitar.top().first;
        auto vertice_atual = para_visitar.top().second;
        para_visitar.pop();

        // Caso a distancia seja maior do que a distancia já registrada
        if (distancia_atual < distancias[vertice_atual]) continue;

        for(auto vertice_vizinho: grafo[vertice_atual]) {
            if (distancias[vertice_atual] + 1 > distancias[vertice_vizinho]) {
                distancias[vertice_vizinho]  = distancias[vertice_atual] + 1;
                para_visitar.push(ii(distancias[vertice_vizinho], vertice_vizinho));
            }
        }
    }

    return distancias[destino];
}

int algoritmo_a(int inicio, int cumprimento){
	int vertice_atual = inicio;
	while(!grafo[vertice_atual].empty()){
		sort(grafo[vertice_atual].begin(), grafo[vertice_atual].end());
		vertice_atual = grafo[vertice_atual][0];
		cumprimento+= 1;
	}
	
	return cumprimento;	
}