
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

#include "PriorityQueue.h"

using namespace std;

struct usuario {
	long int id;
	long int periodo;
	long int turno;
};

bool operator< (usuario const& a, usuario const& b) {
	return a.turno < b.turno || (a.turno == b.turno && a.id < b.id);
}
bool resuelveCaso() {

	// leer los datos de la entrada
	int nElems;
	cin >> nElems;

	if (nElems == 0)
		return false;
	PriorityQueue <usuario> prioridad;
	long int id, periodo;
	for (int i = 0; i < nElems; i++)
	{
		cin >> id >> periodo;
		prioridad.push({ id,periodo,periodo });
	}
	int nEnvios;
	cin >> nEnvios;
	usuario primero;
	while (nEnvios--) {
		primero = prioridad.top();
		prioridad.pop();
		cout << primero.id << "\n";
		primero.turno += primero.periodo;
		prioridad.push(primero);
	}
	cout << "---\n";
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

