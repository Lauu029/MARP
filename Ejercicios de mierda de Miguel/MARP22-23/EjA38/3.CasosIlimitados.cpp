
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"
#include "EnterosInf.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct dianaInfo {
	EntInf numTiradas = Infinito;
	std::vector<int> sectoresSolucion;
};

dianaInfo solveDiana(vector<int> const& sectores, int valorASumar) {

	Matriz<EntInf> minimoNumTiradas(sectores.size() + 1, valorASumar + 1, Infinito);
	int n = sectores.size();
	minimoNumTiradas[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		minimoNumTiradas[i][0] = 0;
		for (int j = 1; j <= valorASumar; ++j)
		{
			if (sectores[i - 1] > j) {
				minimoNumTiradas[i][j] = minimoNumTiradas[i - 1][j];
			}
			else
				minimoNumTiradas[i][j] = min(minimoNumTiradas[i - 1][j], minimoNumTiradas[i][j - sectores[i - 1]] + 1);
		}
	}

	dianaInfo auxInfo;
	auxInfo.numTiradas = minimoNumTiradas[n][valorASumar];

	// Reconstruimos la solucion
	if (minimoNumTiradas[n][valorASumar] != Infinito) {
		int i = n; //Tipos de sectores
		int j = valorASumar;
		while (j > 0) {	// Mientras no se ha alcanzado el valor total
			// Cogemos valores con los que podamos meter en la puntuacion prefiriendo los mas grandes
			if (sectores[i - 1] <= j && minimoNumTiradas[i][j] == minimoNumTiradas[i][j - sectores[i - 1]] + 1) {
				// Cogemos otro mas de tipo i
				auxInfo.sectoresSolucion.push_back(sectores[i - 1]);
				j = j - sectores[i - 1];
			}
			else {	// No tomamos mas sectores de tipo i
				--i;
			}
		}
	}

	return auxInfo;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int valorASumar;

	std::cin >> valorASumar;

	if (!std::cin)  // fin de la entrada
		return false;

	int numSectores;

	std::cin >> numSectores;

	vector<int> sectores;

	int auxSector;
	for (int i = 0; i < numSectores; ++i) {
		std::cin >> auxSector;
		sectores.push_back(auxSector);
	}

	// resolver el caso posiblemente llamando a otras funciones
	dianaInfo resultado = solveDiana(sectores, valorASumar);


	// escribir la solución
	if (resultado.numTiradas != Infinito) {
		std::cout << resultado.numTiradas << ": ";
		for (int i : resultado.sectoresSolucion) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "Imposible\n";
	}

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
