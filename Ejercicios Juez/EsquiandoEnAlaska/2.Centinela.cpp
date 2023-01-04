
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
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
int minimaDiferencia(deque<int>& tallas, deque<int>& actores) {
	int dif=0;
	while (!tallas.empty() && !actores.empty()) {
		int t = tallas.front(); tallas.pop_front();
		int a = actores.front(); actores.pop_front();
		dif += abs(t - a);
	}
	return dif;
}
bool resuelveCaso() {
	int numEsquiadores;
	cin >> numEsquiadores;
	// leer los datos de la entrada

	if (numEsquiadores == 0)
		return false;

	deque<int> tallas;
	deque <int> actores;
	int aux;
	for (int i = 0; i < numEsquiadores; i++)
	{
		cin >> aux;
		tallas.push_back(aux);
	}
	sort(tallas.begin(), tallas.end(), less<int>());
	for (int i = 0; i < numEsquiadores; i++)
	{
		cin >> aux;
		actores.push_back(aux);
	}
	sort(actores.begin(), actores.end(), less<int>());
	cout << minimaDiferencia(tallas, actores) << "\n";
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
