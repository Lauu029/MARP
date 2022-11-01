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
#include <vector>
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
using namespace std;


/*@ <answer>

Creamos un grafo valorado con la informacion de las ciudades y carreteras
Aplicamos el algoritmo de kruskal en el cual creamos un arbol de recubrimiento minimo 
Guardamos el valor de la arista mas larga que va entrando en el arbol de recubrimiento minimo.
Con ese arbol comprobamos si hay mas de un conjunto disjunto, si es así, la salida es imposible,
si no, escribimos el valor de la arista mas larga
 Coste: algoritmo kruskal-> O(AlogA)
		grafo dirigido-> O(A) (numero de veces que recorre el arbol al poner las aristas)
	coste total: O(A+AlogA)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

template <typename Valor>
class ARM_Kruskal {
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	ConjuntosDisjuntos cjtos;
	int aristaMasGrande;
public:
	Valor costeARM() const {
		return coste;
	}
	std::vector<Arista<Valor>> const& ARM() const {
		return _ARM;
	}
	ARM_Kruskal(GrafoValorado<Valor> const& g) : aristaMasGrande(0), cjtos(g.V()), coste(0) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a);
				coste += a.valor();
				if (aristaMasGrande < a.valor()) aristaMasGrande = a.valor();
				if (_ARM.size() == g.V() - 1) break;
			}
		}
	}
	int getNumConjuntosDisjuntos() {
		return cjtos.num_cjtos();
	}
	int getAristaMasGrande() {
		return aristaMasGrande;
	}

};

bool resuelveCaso() {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;

	GrafoValorado <int> g(N);
	int n1, n2, a;
	for (int i = 0; i < M; i++)
	{
		cin >> n1 >> n2 >> a;
		g.ponArista({ n1 - 1, n2 - 1, a });
	}
	ARM_Kruskal <int> sol(g);
	if (sol.getNumConjuntosDisjuntos() > 1) cout << "IMPOSIBLE\n";
	else cout << sol.getAristaMasGrande() << "\n";
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


	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
