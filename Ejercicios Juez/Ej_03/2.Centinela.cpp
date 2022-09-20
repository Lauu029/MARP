
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

 // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {

	// leer los datos de la entrada
	int nElems;
	cin >> nElems;

	if (nElems == 0)
		return false;
	PriorityQueue <long int> sumas;
	long int valor;
	for (int i = 0; i < nElems; i++)
	{
		cin >> valor;
		sumas.push(valor);
	}
	long int val1, val2;
	valor = 0;
	while (!sumas.empty()) {
		val1 = sumas.top();
		sumas.pop();
		if (sumas.empty()) break;
		val2 = sumas.top() + val1;
		valor += val2;
		sumas.pop();

		sumas.push(val2);
	}
	cout << valor << "\n";
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

