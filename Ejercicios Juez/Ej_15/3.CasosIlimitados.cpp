
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const int TOP = 10000;

int ady(int org, int boton) {
	switch (boton)
	{
	case 0:
		return (org + 1) % TOP;
		break;
	case 1:
		return (org * 2) % TOP;
		break;
	case 2:
		return org / 3;
		break;
	default:
		break;
	}
}

int bfs(int org, int dest) {
	if (org == dest)return 0;
	vector<int> distancia(TOP, -1);
	distancia[org] = 0;
	queue<int> pila;
	pila.push(org);
	while (!pila.empty()) {
		int w = pila.front();
		pila.pop();
		for (int i = 0; i < 3; i++)
		{
			int v = ady(w, i);
			if (distancia[v] == -1) {
				distancia[v] = distancia[w] + 1;
				if (v == dest) return distancia[v];
				else pila.push(v);
			}
		}
	}
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int nIni, nFin;
	cin >> nIni >> nFin;

	if (!std::cin)  // fin de la entrada
		return false;
	// resolver el caso posiblemente llamando a otras funciones

	cout << bfs(nIni, nFin) << "\n";
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
