
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
//template <typename Valor>
//class ARM_Kruskal {
//private:
//	std::vector<Arista<Valor>> _ARM;
//	Valor coste;
//	int minimo = -1;
//	ConjuntosDisjuntos cjtos;
//public:
//	Valor costeARM() const {
//		return coste;
//	}
//	std::vector<Arista<Valor>> const& ARM() const {
//		return _ARM;
//	}
//	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), cjtos(g.V()) {
//		PriorityQueue<Arista<Valor>, greater<Arista<Valor>>> pq(g.aristas());
//
//		while (!pq.empty()) {
//			auto a = pq.top(); pq.pop();
//			int v = a.uno(), w = a.otro(v);
//			if (!cjtos.unidos(v, w)) {
//				cjtos.unir(v, w);
//				_ARM.push_back(a);
//				coste += a.valor();
//				if (minimo == -1 || minimo > a.valor()) minimo = a.valor();
//				if (_ARM.size() == g.V() - 1) break;
//			}
//		}
//	}
//	int getMinArista() {
//		return minimo;
//	}
//	bool hayConexion(int a, int b) {
//		return cjtos.unidos(a, b);
//	}
//};
class camionesReparto {
private:
	vector<bool> visit;
	int ancho;
	void dfs(GrafoValorado<int> const& G, int v, int umbral) {
		visit[v] = true;
		for (auto a : G.ady(v)) {
			if (a.valor() >= umbral) {
				int w = a.otro(v);
				if (!visit[w])
					dfs(G, w, ancho);
			}
		}
	}
public:
	camionesReparto(GrafoValorado <int> const& g, int org, int a) :visit(g.V(), false), ancho(a) {
		dfs(g, org, a);
	};
	bool hayCamino(int a) { return visit[a]; }
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int V, E;
	cin >> V >> E;
	if (!std::cin)  // fin de la entrada
		return false;
	GrafoValorado<int> g(V);
	int v1, v2, val;
	for (int i = 0; i < E; i++)
	{
		cin >> v1 >> v2 >> val;
		g.ponArista({ v1 - 1, v2 - 1, val });
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> v1 >> v2 >> val;
		camionesReparto cam(g, v1 - 1, val);
		if (cam.hayCamino(v2 - 1)) cout << "SI\n";
		else cout << "NO\n";
	}

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
