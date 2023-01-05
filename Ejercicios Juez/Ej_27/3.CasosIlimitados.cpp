
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "IndexPQ.h"
#include "DigrafoValorado.h"
#include <queue>
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class CaminoMasCorto {
public:
	CaminoMasCorto(GrafoValorado<int> const& g, int s) : visit(g.V(), false),
		ant(g.V()), dist(g.V()), distValor(g.V()), s(s) {
		bfs(g);
	}
	// ¿hay camino del origen a v?
	bool hayCamino(int v) const {
		return visit[v];
	}
	// número de aristas entre s y v
	int distancia(int v) const {
		return dist[v];
	}
	// número de aristas entre s y v
	int valorDistancia(int v) const {
		return distValor[v];
	}
	// devuelve el camino más corto desde el origen a v (si existe)
	deque<int> camino(int v) const {
		if (!hayCamino(v)) throw std::domain_error("No existe camino");
		deque<int> cam;
		for (int x = v; x != s; x = ant[x])
			cam.push_front(x);
		cam.push_front(s);
		return cam;
	}
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
	vector <int> distValor;
	int s;
	void bfs(GrafoValorado<int> const& g) {
		std::queue<int> q;
		dist[s] = 0; visit[s] = true;
		distValor[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto w : g.ady(v)) {
				if (!visit[w.otro(v)]) {
					ant[w.otro(v)] = v;
					dist[w.otro(v)] = dist[v] + 1;
					distValor[w.otro(v)] = distValor[v] + w.valor();
					visit[w.otro(v)] = true;
					q.push(w.otro(v));
				}
			}
		}
	}
};

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
		dist(g.V(), INF), numAristas(g.V(), 0), ulti(g.V()), pq(g.V()) {
		dist[origen] = 0;

		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
	int numeroAristas(int v) const { return numAristas[v]; }
	deque<Valor> camino(int v) const {
		deque<Valor> cam;
		// recuperamos el camino retrocediendo
		Arista<Valor> a;
		for (a = ulti[v]; a.uno() != origen; a = ulti[a.uno()])
			cam.push_front(a);
		cam.push_front(a);
		return cam;
	}
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<int> numAristas;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;
	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor() || (dist[w] == dist[v] + a.valor() && numAristas[w] > numAristas[v]+1)) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;
			numAristas[w] = numAristas[v] + 1;
			pq.update(w, dist[w]);
		}
	}
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, V;
	cin >> N >> V;
	if (!std::cin)  // fin de la entrada
		return false;
	GrafoValorado <int> g(N);
	DigrafoValorado <int> gDirigido(N);
	int a1, a2, val;
	for (int i = 0; i < V; i++)
	{
		cin >> a1 >> a2 >> val;
		g.ponArista({ a1 - 1, a2 - 1, val });
		gDirigido.ponArista({ a1 - 1, a2 - 1, val });
		gDirigido.ponArista({ a2 - 1, a1 - 1, val });

	}
	// resolver el caso posiblemente llamando a otras funciones
	int k;
	cin >> k;
	// escribir la solución
	int p1, p2;
	for (int i = 0; i < k; i++)
	{
		cin >> p1 >> p2;
		CaminoMasCorto cam(g, p1 - 1);
		Dijkstra<int> cam2(gDirigido, p1 - 1);
		if (cam.hayCamino(p2 - 1)) {
			cout << cam2.distancia(p2 - 1);
			if (cam.distancia(p2 - 1) < cam2.numeroAristas(p2 - 1))
				cout << " NO\n";
			else cout << " SI\n";
		}
		else
			cout << "SIN CAMINO\n";
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
