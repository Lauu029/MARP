
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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
int ciudadesDefendidas(deque<int>& enemigos, deque<int>& equipos) {
	int def = 0;
	sort(enemigos.begin(), enemigos.end(), less<int>());
	sort(equipos.begin(), equipos.end(), less<int>());
	while(!equipos.empty()) {
		int a = equipos.front(); equipos.pop_front();
		if (enemigos.front() <= a) {
			def++;
			enemigos.pop_front();
		}
	}
	return def;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	deque<int> enemigos(N);
	deque<int> equipos(N);
	for (int i = 0; i < N; i++)
		cin >> enemigos[i];
	for (int i = 0; i < N; i++)
		cin >> equipos[i];
	cout << ciudadesDefendidas(enemigos, equipos) << "\n";
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
