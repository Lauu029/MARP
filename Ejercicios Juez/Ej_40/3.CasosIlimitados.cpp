
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

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

struct cofre {
	int distancia;
	int valor;
};

int maxOro(vector<cofre>const& cof, Matriz<int>& oro, int i, int j) {
	if (oro[i][j] != -1)
		return oro[i][j];
	if (i == 0 || j == 0)
		oro[i][j] = 0;
	else if (3 * cof[i - 1].distancia > j)
		oro[i][j] = maxOro(cof, oro, i - 1, j);
	else
		oro[i][j] = max(maxOro(cof, oro, i - 1, j), maxOro(cof, oro, i - 1, j - 3 * cof[i - 1].distancia) + cof[i - 1].valor);

	return oro[i][j];		
}

bool resuelveCaso() {

	int T, N;
	cin >> T >> N;
	if (!std::cin)
		return false;
	vector<cofre> c(N);
	Matriz<int> oro(N + 1, T + 1, -1);
	vector<cofre> sol;
	for (int i = 0; i < N; i++)
		cin >> c[i].distancia >> c[i].valor;
	cout << maxOro(c, oro, N, T ) << "\n";
	int i = N;
	int j = T;
	while (i > 0 && j > 0) {
		if (oro[i][j] != oro[i - 1][j]) {
			sol.push_back({ c[i-1].distancia,c[i-1].valor });
			j = j -3* c[i - 1].distancia;
		}
		--i;
	}
	cout << sol.size() << "\n";
	for (int i = sol.size()-1; i >=0; i--)
		cout << sol[i].distancia << " " << sol[i].valor << "\n";
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
