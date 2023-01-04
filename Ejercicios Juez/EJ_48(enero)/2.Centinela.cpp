
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include "PriorityQueue.h"
#include <algorithm>
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
struct infoCharla {
	int horaIni;
	int horaFin;
};
int minimoAmigos(deque<infoCharla>& numCharlas) {
	int amigos = 0;
	PriorityQueue<int> finAmigos;
	int miCharla;
	if (!numCharlas.empty())
		miCharla = numCharlas.front().horaFin; numCharlas.pop_front();
	while (!numCharlas.empty()) {
		if (!numCharlas.empty()) {
			if (miCharla > numCharlas.front().horaIni) {
				if (!finAmigos.empty() && finAmigos.top() < numCharlas.front().horaIni) {
					finAmigos.pop();
					finAmigos.push(numCharlas.front().horaIni);
				}
				else {
					amigos++;
					finAmigos.push(numCharlas.front().horaFin);//me guardo la hora de fin de la charla
					numCharlas.pop_front();//quito la charla
				}
			}
			else {
				miCharla = numCharlas.front().horaFin; numCharlas.pop_front();
			}
		}
	}
	return amigos;
}
bool operator<(const infoCharla& c1, const infoCharla& c2) {
	return c1.horaIni < c2.horaIni;
}
bool resuelveCaso() {
	int numCharlas;
	// leer los datos de la entrada
	cin >> numCharlas;
	if (numCharlas == 0)
		return false;
	deque<infoCharla> charlas;
	infoCharla c;
	for (int i = 0; i < numCharlas; i++)
	{
		cin >> c.horaIni >> c.horaFin;
		charlas.push_back(c);
	}
	sort(charlas.begin(), charlas.end(), less<infoCharla>());
	// resolver el caso posiblemente llamando a otras funciones
	cout << minimoAmigos(charlas) << "\n";
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
