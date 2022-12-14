
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

struct infoUsuario {
	long int id;
	long int periodo;
	long int turno;
};
bool operator < (infoUsuario const& a, infoUsuario const& b) {
	if (a.turno < b.turno) return true;
	else if (a.turno == b.turno) return a.id < b.id;
	else return false;
}
void awa(PriorityQueue<infoUsuario, less<infoUsuario>>& uwu, long int iwi) {
	infoUsuario ewe;
	for (int i = 0; i < iwi; i++)
	{
		ewe = uwu.top();
		uwu.pop();
		cout << ewe.id << "\n";
		ewe.turno += ewe.periodo;
		uwu.push(ewe);
	}
}
bool resuelveCaso() {
	long int ewe, iwi;
	cin >> ewe;
	if (!ewe)
		return false;
	PriorityQueue<infoUsuario, less<infoUsuario>> uwu;
	infoUsuario owo;
	for (int i = 0; i < ewe; i++)
	{
		cin >> owo.id >> owo.periodo;
		owo.turno = owo.periodo;
		uwu.push(owo);
	}
	cin >> iwi;
	awa(uwu, iwi);
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

