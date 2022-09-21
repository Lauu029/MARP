
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
struct paciente {
	string nombre;
	long int gravedad;
	long int turno;
};

bool operator>(paciente const& a, paciente const& b) {
	return a.gravedad > b.gravedad || (a.gravedad == b.gravedad && a.turno < b.turno);
}
bool resuelveCaso() {

	// leer los datos de la entrada
	int nCasos;
	cin >> nCasos;
	if (!cin)
		return false;
	char accion;

	PriorityQueue<paciente, greater<paciente>> urgencias;

	cin >> accion;
	string paciente;
	long int gravedad;
	int t = 0;
	while (nCasos--) {

		if (accion == 'I') {
			cin >> paciente >> gravedad;
			urgencias.push({ paciente,gravedad,t });
			t++; 
		}
		else if (!urgencias.empty()) {
			cout << urgencias.top().nombre << "\n";
			urgencias.pop();
		}
		cin >> accion;
	}
	cout << "---\n";
	// resolver el caso posiblemente llamando a otras funciones

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
