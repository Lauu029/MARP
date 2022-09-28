
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

struct periodico {
	int ini;
	int fin;
	int periodo;
};
bool operator< (periodico const& a, periodico const& b) {
	return a.ini < b.ini || (a.ini == b.ini && a.fin < b.fin);
}

bool resuelveCaso() {

	// leer los datos de la entrada

	int N, M, T;
	cin >> N >> M >> T;
	if (!std::cin)  // fin de la entrada
		return false;
	periodico agenda;
	PriorityQueue <periodico, less<periodico>> tareas;
	for (int i = 0; i < N; i++)
	{
		cin >> agenda.ini >> agenda.fin;
		agenda.periodo = 0;
		tareas.push(agenda);
	}
	for (size_t i = 0; i < M; i++)
	{
		cin >> agenda.ini >> agenda.fin >> agenda.periodo;
		tareas.push(agenda);
	}
	// resolver el caso posiblemente llamando a otras funciones

	int tFin = 0;

	bool daConflicto = false;
	while (!tareas.empty() && tareas.top().ini < T) {
		periodico p = tareas.top();
		tareas.pop();

		if (p.ini >= tFin) {
			tFin = p.fin;
			if (p.periodo > 0) {
				p.ini += p.periodo;
				p.fin += p.periodo;
				tareas.push(p);
			}
		}
		else {
			if (T > p.ini)
				daConflicto = true;
			break;
		}		
	}
	if (daConflicto) cout << "SI\n";
	else cout << "NO\n";
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
