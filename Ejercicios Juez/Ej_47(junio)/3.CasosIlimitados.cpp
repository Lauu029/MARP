
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "Grafo.h"
#include <deque>

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class CaminosDFS {
private:
	vector<bool> vistit;
	vector<int>ant;
	int s;
	int costeTotal = 0;
	int inf = 100000;
	void dfs(Grafo const& G, int v, vector<int> const& costes, int& minimo) {
		if (!vistit[v]) {
			vistit[v] = true;
			minimo = min(costes[v], minimo);
			for (int w : G.ady(v))
			{
				if (!vistit[w])
				{
					ant[w] = v;
					dfs(G, w, costes, minimo);
				}
			}
		}
	}

public:
	CaminosDFS(Grafo const& G, int s, vector<int> const& costes) : vistit(G.V(), false), ant(G.V()), s(s) {

		for (int i = 0; i < G.V(); i++)
		{
			if (!vistit[i]) {
				int min = inf;
				dfs(G, i, costes, min);
				costeTotal += min;
			}
		}
	}
	bool hayCamino(int v)const {
		return vistit[v];
	}
	int getTotal() { return costeTotal; }
	deque<int> camino(int v)const {
		if (!hayCamino(v))
			throw domain_error("No hay camino");
		deque<int> res;
		for (int w = v; w != s; w = ant[w])
			res.push_front(w);
		res.push_front(s);
		return res;
	};
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int N, V;
	cin >> N >> V;
	if (!std::cin)  // fin de la entrada
		return false;
	vector<int> costes(N);
	for (int i = 0; i < N; i++)
	{
		cin >> costes[i];
	}
	Grafo g(N);
	int v1, v2;
	for (int i = 0; i < V; i++)
	{
		cin >> v1 >> v2;
		g.ponArista(v1 - 1, v2 - 1);
	}
	CaminosDFS c(g, 0, costes);
	cout << c.getTotal() << endl;

	// escribir la solución

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
