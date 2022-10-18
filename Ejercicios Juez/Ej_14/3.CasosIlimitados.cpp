
/*@ <answer>
 *
 * Nombre y Apellidos: Laura Gómez Bodego MARP19
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include "Grafo.h"
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
class longitudCamino {
protected:
	vector<bool> visitada;
	vector<int>distancia;

public:
	void bfs(Grafo const& gr, int origen, int ttl) {
		queue<int> q;
		std::fill(visitada.begin(), visitada.end(), false);
		distancia[origen] = 0;
		visitada[origen] = true;
		q.push(origen);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			for (int w : gr.ady(v))
			{
				if (!visitada[w]) {
					distancia[w] = distancia[v] + 1;
					if (distancia[w] > ttl) return;
					visitada[w] = true;
					q.push(w);
				}
			}

		}
	}
	int noVisitados() {
		int v = 0;
		for (int i = 0; i < visitada.size(); i++)
		{
			if (!visitada[i]) v++;
		}
		return v;
	}
	longitudCamino(Grafo const& gr) : visitada(gr.V(), false), distancia(gr.V(), -1) {

	}
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, C;
	cin >> N >> C;
	if (!std::cin)  // fin de la entrada
		return false;

	Grafo red(N);
	int a1, a2;
	for (int i = 0; i < C; i++)
	{
		cin >> a1 >> a2;
		red.ponArista(a1 - 1, a2 - 1);
	}
	int K;
	cin >> K;
	int org, ttl;
	longitudCamino visitados(red);
	for (int i = 0; i < K; i++)
	{
		cin >> org >> ttl;
		visitados.bfs(red, org-1, ttl);
		cout << visitados.noVisitados() << "\n";
	}



	cout << "---\n";
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
