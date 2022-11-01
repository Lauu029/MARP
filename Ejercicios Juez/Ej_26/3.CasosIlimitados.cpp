
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template <typename Valor>
using Camino = deque<Valor>;
template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()), nCaminos(g.V(),0) {
		dist[origen] = 0;
		pq.push(origen, 0);
		nCaminos[orig] = 1;
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
	int numeroDeCaminos(int v) { return nCaminos[v]; };
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<int> nCaminos;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;
	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;
			nCaminos[w] = nCaminos[v];
			pq.update(w, dist[w]);
		}
		else if (dist[w] == dist[v] + a.valor()) 
			nCaminos[w] += nCaminos[v];
		
	}
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, C;
	cin >> N >> C;
	if (!std::cin)  // fin de la entrada
		return false;
	DigrafoValorado<int> g(N);
	int v1, v2, valor;
	for (int i = 0; i < C; i++)
	{
		cin >> v1 >> v2 >> valor;
		g.ponArista({ v1 - 1,v2 - 1,valor });
		g.ponArista({ v2 - 1,v1 - 1,valor });
	}
	Dijkstra<int> dij(g,0);
	cout << dij.numeroDeCaminos(N-1);
	cout << "\n";
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
