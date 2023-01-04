
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================a
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct infoComic {
	int idComic;
	int pila;
};
bool operator<(infoComic const& a, infoComic const& b) {
	return a.idComic < b.idComic;
}
bool resuelveCaso() {

	// leer los datos de la entrada
	long int N;
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	vector<stack<int>> colas;
	long int t, n, minimo=10e8;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		stack<int> cola;
		for (int j = 0; j < t; j++)
		{
			cin >> n;
			minimo = min(minimo, n);
			cola.push(n);
		}
		colas.push_back(cola);
	}
	PriorityQueue<infoComic> comics;
	int numeroCola = 1;
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i < N; i++)
	{
		comics.push( { colas[i].top(), i });
	}
	while (comics.top().idComic!=minimo) {
		infoComic mejor = comics.top(); comics.pop();
		colas[mejor.pila].pop();
		if (!colas[mejor.pila].empty()) {
			comics.push({ colas[mejor.pila].top(), mejor.pila });
		}
		numeroCola++;
	}
	cout << numeroCola << "\n";
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
