
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

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Proyecto {
	int inicio, fin;
};

bool operator>(Proyecto const& a, Proyecto const& b) {
	if (a.inicio == b.inicio) {
		return a.fin < b.fin;
	}
	else {
		return a.inicio > b.inicio;
	}
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int numEdificios;

	std::cin >> numEdificios;

	if (numEdificios == 0)
		return false;

	std::priority_queue<Proyecto, std::vector<Proyecto>, std::greater<Proyecto>> edificios;
	int auxInicio, auxFin;
	Proyecto edificioAux;
	for (int i = 0; i < numEdificios; ++i) {
		std::cin >> auxInicio >> auxFin;
		edificioAux.inicio = auxInicio;
		edificioAux.fin = auxFin;
		edificios.push(edificioAux);
	}

	// resolver el caso posiblemente llamando a otras funciones
	int numTuneles = 0;
	int lastPositionTunelFin = -1;
	int lastPositionTunelInicio = -1;
	while (!edificios.empty()) {
		//Si seguimos entrando dentro del rango donde podemos meter otro tunel con la misma disposicion
		if ((edificios.top().inicio >= lastPositionTunelInicio && edificios.top().inicio < lastPositionTunelFin) ||
			(edificios.top().fin > lastPositionTunelInicio && edificios.top().fin <= lastPositionTunelFin)) {
			lastPositionTunelInicio = max(lastPositionTunelInicio, edificios.top().inicio);
			lastPositionTunelFin = min(lastPositionTunelFin, edificios.top().fin);
		}
		else {
			lastPositionTunelInicio = edificios.top().inicio;
			lastPositionTunelFin = edificios.top().fin;
			numTuneles++;
		}
		edificios.pop();
	}

	// escribir la solución
	std::cout << numTuneles << "\n";

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
