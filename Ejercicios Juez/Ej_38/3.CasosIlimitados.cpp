
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "EnterosInf.h"
#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

EntInf numTiradas(vector<int> const& circulos, int puntos, vector<int>& tiradas) {
	vector<EntInf> sol(puntos + 1, Infinito);
	sol[0] = 0;
	for (int i = 0; i < circulos.size(); i++)
	{
		for (int j = 0; j <= puntos; j++)
		{
			if (circulos[i] <= j)
				sol[j] = min(sol[j], sol[j - circulos[i]] + 1);
		}
	}
	if (sol[puntos] < Infinito) {

		int i = circulos.size()-1, j = puntos;
		while (j > 0) {
			if (circulos[i] <= j && sol[j] == sol[j - circulos[i]] + 1) {
				tiradas.push_back(circulos[i]);
				j -= circulos[i];
			}
			else --i;
		}
	}
	return sol[puntos];
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int puntos, nCirculos;
	cin >> puntos >> nCirculos;
	if (!std::cin)  // fin de la entrada
		return false;
	vector <int> circulos(nCirculos);
	for (int i = 0; i < nCirculos; i++)
	{
		cin >> circulos[i];
	}
	// resolver el caso posiblemente llamando a otras funciones

	// escribir la solución
	vector<int> salida;
	EntInf tiradas = numTiradas(circulos, puntos, salida);
	if (tiradas != Infinito) {
		cout << tiradas << ": ";
		for (int i = 0; i < salida.size(); i++)
		{
			cout << salida[i] << " ";
		}
	}
	else cout << "IMPOSIBLE";

	cout << "\n";
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
