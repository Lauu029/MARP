
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int numTrim(PriorityQueue<char>& letrasPalabra) {
	int trim = 0;
	while (!letrasPalabra.empty()) {
		char letra = letrasPalabra.top(); letrasPalabra.pop();
		trim++;
		while (!letrasPalabra.empty() && letrasPalabra.top() == letra) 
			letrasPalabra.pop();
	}
	return trim;
}
bool resuelveCaso() {

	// leer los datos de la entrada
	string entrada;
	cin >> entrada;
	if (!std::cin)  // fin de la entrada
		return false;
	//para que las letras estén juntas
	PriorityQueue<char> letrasPalabra;
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i < entrada.size(); i++)
	{
		letrasPalabra.push(entrada[i]);
	}
	// escribir la solución
	cout << numTrim(letrasPalabra) << "\n";
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
