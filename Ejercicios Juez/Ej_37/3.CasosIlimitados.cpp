
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "EnterosInf.h"
#include "Matriz.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
EntInf minPrecio(vector<pair<int, int>>const& cordeles, int L, int N) {
	vector<EntInf> sol(L + 1, Infinito);
	sol[0] = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = cordeles[i-1].first; j <= L; j++)
		{
			
				sol[j] = min(sol[j], sol[j - cordeles[i - 1].first] + cordeles[i - 1].second);
			
		}
	}
	return sol[L];
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int N, L;
	cin >> N >> L;
	if (!std::cin)  // fin de la entrada
		return false;
	vector<pair<int, int>>cordeles(N + 1);
	cordeles[0].first = 0; cordeles[0].second = 0;
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 1; i <= N; i++)
	{
		cin >> cordeles[i].first >> cordeles[i].second;
	}
	// escribir la solución
	EntInf solucionQuimico = minPrecio(cordeles, L, N);
	if (solucionQuimico != Infinito) cout << "SI " << solucionQuimico << "\n";
	else cout << "NO\n";
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
