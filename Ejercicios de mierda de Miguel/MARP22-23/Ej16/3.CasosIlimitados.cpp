
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

EntInf devolver_cambio(vector<int> const& M, std::vector<EntInf>& posibilidades, EntInf& maxPosibilidades, int C, int monedaActual) {
	//int n = M.size();
	//Matriz<EntInf> monedas(n + 1, C + 1, Infinito);
	//std::vector<EntInf> tiposManeras(n + 1, 0);
	//monedas[0][0] = 0;
	//tiposManeras[0][0] = Infinito;
	//for (int i = 1; i <= n; ++i) {
	//	monedas[i][0] = 0;
	//	tiposManeras[i][0] = Infinito;
	//	for (int j = 1; j <= C; ++j)
	//		if (M[i - 1] > j) {
	//			monedas[i][j] = monedas[i - 1][j];
	//			tiposManeras[i][j] = tiposManeras[i - 1][j];
	//		}
	//		else {
	//			monedas[i][j] = min(monedas[i - 1][j], monedas[i][j - M[i - 1]] + 1);
	//			//tiposManeras[i][j] = 
	//		}
	//			
	//}
	if (C == 0)
		return 0;
	
	posibilidades[C] = devolver_cambio(M, posibilidades, maxPosibilidades, C % M[monedaActual], monedaActual) + 1;
	if (posibilidades[C] != Infinito)
		maxPosibilidades = max(posibilidades[C], maxPosibilidades);
	

	/*for (int j = 1; j <= C; ++j) {
		tiposManeras[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if ()
		}
	}*/

	return posibilidades[C];
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int C;

	std::cin >> C;

	if (!std::cin)  // fin de la entrada
		return false;

	int numTipos;

	std::cin >> numTipos;

	std::vector<int> monedas;
	int auxInt;
	for (int i = 0; i < numTipos; ++i) {
		std::cin >> auxInt;
		monedas.push_back(auxInt);
	}

	// resolver el caso posiblemente llamando a otras funciones
	std::vector<EntInf> posibilidades(C + 1, Infinito);
	EntInf maxPosibilidades = 0;
	posibilidades[0] = 0;

	for (int i = 1; i < monedas.size(); ++i) {
		devolver_cambio(monedas, posibilidades, maxPosibilidades, C, i - 1);
	}
	

	// escribir la solución
	std::cout << maxPosibilidades << "\n";

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
