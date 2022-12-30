
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
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
int numDiasFelices(deque<int>& bizcocho) {
	int laura, paula;
	int felicidad = 0;
	while (!bizcocho.empty()) {
		laura = bizcocho.front();
		bizcocho.pop_front();
		if (laura == bizcocho.front()) {
			bizcocho.pop_front();
			if (laura)
				felicidad++;
		}
		else {
			paula = bizcocho.back();
			bizcocho.pop_back();
			if (laura == paula && laura) felicidad++;
		}
	}
	return felicidad;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int numDias;
	cin >> numDias;
	if (!std::cin)  // fin de la entrada
		return false;

	// resolver el caso posiblemente llamando a otras funciones
	deque<int> frutas;
	int trozoBizcocho;
	for (int i = 0; i < numDias; i++)
	{
		cin >> trozoBizcocho;
		frutas.push_back(trozoBizcocho);
	}
	// escribir la solución
	cout << numDiasFelices(frutas) << "\n";
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
