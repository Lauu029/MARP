
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

long int costeSuma(PriorityQueue<long int>& numeros) {
	long int n1, n2;
	long int costeTotal=0;

	while (!numeros.empty()) {
		n1 = numeros.top(); numeros.pop();
		if (numeros.empty()) 
			break;
		n2 = numeros.top()+ n1;
		costeTotal += n2;
		numeros.pop();
		numeros.push(n2);
	}
	return costeTotal;
}
bool resuelveCaso() {
	int numNumerosSuma;
	cin >> numNumerosSuma;
	if (numNumerosSuma==0) 
		return false;
	 
	PriorityQueue<long int> costeSumas;
	long int numero;
	for (int i = 0; i < numNumerosSuma; i++)
	{
		cin >> numero;
		costeSumas.push(numero);
	}
	cout << costeSuma(costeSumas) << "\n";
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

