
/*@ <answer>
 *
 * Nombre y Apellidos: Laura Gómez Bodego
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Queue_Medianas.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool resuelveCaso() {

	// leer los datos de la entrada

	long int n;
	cin >> n;
	if (!std::cin)  // fin de la entrada
		return false;
	queue_medianas medianos = queue_medianas();

	for (long int i = 0; i < n; i++)
	{
		int entry;
		cin >> entry;

		if (entry != 0) medianos.addElemento(entry);
		else medianos.getMediana();

	}
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
