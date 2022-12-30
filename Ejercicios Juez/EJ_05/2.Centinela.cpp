
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
struct infoPaciente {
	string nombre;
	long int id;
	long int pachucho;
};
bool operator < (infoPaciente const& a, infoPaciente const& b) {
	if (a.pachucho > b.pachucho) return true;
	else if (a.pachucho == b.pachucho)return a.id < b.id;
	else return false;
}

bool resuelveCaso() {
	int eventos;
	cin >> eventos;
	if (!eventos)
		return false;
	infoPaciente malito;
	PriorityQueue<infoPaciente, less<infoPaciente>> tanPalArrastre;
	char queHacemos;
	long int id = 0;
	for (int i = 0; i < eventos; i++)
	{
		cin >> queHacemos;
		if (queHacemos == 'I') {
			malito.id = id;
			id++;
			cin >> malito.nombre >> malito.pachucho;
			tanPalArrastre.push(malito);
		}
		else if (queHacemos == 'A') {
			if (!tanPalArrastre.empty()) {
				malito = tanPalArrastre.top(); tanPalArrastre.pop();
				cout << malito.nombre << "\n";
			}
		}
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
