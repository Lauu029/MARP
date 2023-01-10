
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

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
	int numAEmparejar;

	std::cin >> numAEmparejar;

	if (numAEmparejar == 0)
		return false;

	std::priority_queue<int, std::vector<int>, std::greater<int>> alturaEsquiadores;
	int auxInt;
	for (int i = 0; i < numAEmparejar; ++i) {
		std::cin >> auxInt;
		alturaEsquiadores.push(auxInt);
	}
	

	std::priority_queue<int, std::vector<int>, std::greater<int>> esquis;
	for (int i = 0; i < numAEmparejar; ++i) {
		std::cin >> auxInt;
		esquis.push(auxInt);
	}

	// resolver el caso posiblemente llamando a otras funciones
	int diferenciaTotal = 0;
	while (!alturaEsquiadores.empty()) {
		diferenciaTotal += abs(esquis.top() - alturaEsquiadores.top());
		esquis.pop();
		alturaEsquiadores.pop();
	}

	// escribir la solución
	std::cout << diferenciaTotal << "\n";

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
