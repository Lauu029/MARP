
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#include "IndexPQ.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"// propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
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
class ARM_Kruskal {
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	ConjuntosDisjuntos cjtos;
public:
	Valor costeARM() const {
		return coste;
	}
	std::vector<Arista<Valor>> const& ARM() const {
		return _ARM;
	}
	bool ciudadUnida() { return cjtos.num_cjtos() == 1; }
	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), cjtos(g.V()) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a); coste += a.valor();
				if (_ARM.size() == g.V() - 1) break;
			}
		}
	}
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, V;
	cin >> N >> V;

	if (!std::cin)  // fin de la entrada
		return false;
	int a1, a2, val;
	GrafoValorado <int> graf(N);
	for (int i = 0; i < V; i++)
	{
		cin >> a1 >> a2 >> val;
		graf.ponArista({ a1 - 1,a2 - 1,val });
	}
	ARM_Kruskal <int> kr(graf);
	// resolver el caso posiblemente llamando a otras funciones
	if (kr.ciudadUnida()) {
		cout << kr.costeARM();
	}
	else cout << "IMPOSIBLE";
	cout << "\n";
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
