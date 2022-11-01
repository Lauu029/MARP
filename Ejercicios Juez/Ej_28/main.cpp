/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Laura Gómez Bodego MARP19
  * Estudiante 2: Miguel Hernández García  MARP22
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <deque>

using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"
/*@ <answer>

 Utilizamos el algotitmo Dijkstra con el grafo inverso para calcular los caminos más óptimos desde la salida
 a cada casilla. Luego comprobamos si la distancia desde cada nodo a la salida es menor que el tiempo t, ese
 ratón ha salido y se suma a la salida

 Coste: O(Alog V) siendo A el numero de aristas del grafo valorado y V el número de vértices
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

template <typename Valor>
using Camino = std::deque<Valor>;
template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
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
	Camino<Valor> camino(int v) const {
		Camino<Valor> cam;
		// recuperamos el camino retrocediendo
		AristaDirigida<Valor> a;
		for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
			cam.push_front(a);
		cam.push_front(a);
		return cam;
	}
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;
	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor(); ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}
};

bool resuelveCaso() {

	// leemos la entrada
	int N, S, T, P;
	cin >> N >> S >> T >> P;

	if (!cin)
		return false;

	// leer el resto del caso y resolverlo
	DigrafoValorado<int> laberinto(N);
	int a1, a2, valor;
	for (int i = 0; i < P; i++)
	{
		cin >> a1 >> a2 >> valor;
		laberinto.ponArista(AristaDirigida<int>(a1 - 1, a2 - 1, valor));
	}
	Dijkstra<int> sol(laberinto.inverso(), S - 1);
	int sale = 0;
	for (int i = 0; i < N; i++)
	{
		if (i != S - 1) {
			if (sol.distancia(i) <= T)
				sale++;
		}
	}
	cout << sale << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// system("PAUSE");
#endif
	return 0;
}
