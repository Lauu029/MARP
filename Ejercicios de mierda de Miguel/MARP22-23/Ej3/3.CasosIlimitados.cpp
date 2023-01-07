
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Caminos {
private:
	int maxDist; // dist[v] = aristas en el camino s-v más corto
	int s;
	int numCaminos;

public:
	Caminos(Grafo const& g, int maxDistAux, int sAux) : maxDist(maxDistAux), s(sAux) {
		std::vector<bool> visitados(g.V(), false);
		numCaminos = 0;
		dfs(g, 0, visitados, 0);
	}

	void dfs(Grafo const& G, int v, std::vector<bool> visit, int dist) {
		visit[v] = true;
		//Si hemos llegado al final es que hay otro camino posible
		if (v == s) {
			numCaminos++;
		}
		//Comprobamos si podemos continuar y si es así miramos por otros caminos
		else if (dist != maxDist) {
			for (int w : G.ady(v)) {
				if (!visit[w]) {
					dfs(G, w, visit, dist + 1);
				}
			}
		}
	}

	int getNumCaminos() {
		return numCaminos;
	}
};



bool resuelveCaso() {

	// leer los datos de la entrada
	int numRows;

	std::cin >> numRows;

	if (!std::cin)  // fin de la entrada
		return false;

	int numCols;

	std::cin >> numCols;

	Grafo grafo(numRows * numCols);

	{
		//Preparamos un vector para luego ir uniendo los puntos
		std::vector<char> auxVector(numCols, 'X');
		char auxChar;
		//Leemos los puntos y los vamos uniendo si hace falta
		for (int j = 0; j < numRows; ++j) {
			for (int i = 0; i < numCols; ++i) {
				std::cin >> auxChar;
				if (auxChar == '.') {
					if (j > 0) {
						if (auxVector[i] == '.') {
							grafo.ponArista((j - 1) * numCols + i, j * numCols + i);
						}
					}
					if (i > 0) {
						if (auxVector[i - 1] == '.') {
							grafo.ponArista(j * numCols + i - 1, j * numCols + i);
						}
					}
				}
				auxVector[i] = auxChar;
			}
		}
	}
	

	// resolver el caso posiblemente llamando a otras funciones
	Caminos caminos(grafo, (numRows - 1) + (numCols - 1), numRows * numCols - 1);

	// escribir la solución
	std::cout << caminos.getNumCaminos() << "\n";

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
