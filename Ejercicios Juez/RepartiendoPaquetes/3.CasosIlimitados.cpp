
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"// propios o los de las estructuras de datos de clase

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
	deque<Valor> camino(int v) const {
		deque<Valor> cam;
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

	// leer los datos de la entrada
	int N, C;
	cin >> N >> C;
	if (!std::cin)  // fin de la entrada
		return false;
	DigrafoValorado <int> pueblo(N);
	DigrafoValorado <int> vueltaPueblo(N);
	int p1, p2, cam;
	for (int i = 0; i < C; i++)
	{
		cin >> p1 >> p2 >> cam;
		pueblo.ponArista({ p1 - 1,p2 - 1,cam });
		vueltaPueblo.ponArista({ p2 - 1,p1 - 1,cam });
	}
	int casaOrigen;
	cin >> casaOrigen;
	// resolver el caso posiblemente llamando a otras funciones
	Dijkstra<int> valorCamino(pueblo, casaOrigen-1);
	Dijkstra<int> valorVuelta(vueltaPueblo, casaOrigen-1);
	int numRepartos;
	cin >> numRepartos;
	bool factible = true;
	int valTotal = 0;
	int casa;
	for (int i = 0; i < numRepartos; i++)
	{
		cin >> casa;
		if (valorCamino.hayCamino(casa-1)) {
			valTotal += valorCamino.distancia(casa-1);
			if (valorVuelta.hayCamino(casa-1))
				valTotal += valorVuelta.distancia(casa-1);
			else factible = false;
		}
		else factible = false;
	}
	// escribir la solución
	if (factible)
		cout << valTotal << "\n";
	else cout << "Imposible\n";
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
