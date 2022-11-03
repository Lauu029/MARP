
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
int compraCamisetas(deque<int>& jugadores, deque<int>& tallas) {
	sort(jugadores.begin(), jugadores.end(), less<int>());
	sort(tallas.begin(), tallas.end(), less<int>());

	while (!jugadores.empty() && !tallas.empty()) {
		int a = tallas.front(); tallas.pop_front();
		if (jugadores.front() == a || jugadores.front() == a - 1) 
			jugadores.pop_front();
	}
	return jugadores.size();
}
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, M;
	cin >> N >> M;
	if (!std::cin)  // fin de la entrada
		return false;
	deque<int> jugadores(N);
	deque <int> tallas(M);
	for (int i = 0; i < N; i++)
		cin >> jugadores[i];
	for (int i = 0; i < M; i++)
		cin >> tallas[i];
	
	cout << compraCamisetas(jugadores, tallas) << "\n";
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
