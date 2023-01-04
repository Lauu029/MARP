
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
struct infoFesti {
	long long int grupos;
	long long int precio;
};

long long int numFestivales(vector<infoFesti>& festivales, long long int P, long long int N) {
	Matriz<long long int> maxArtistas(N + 1, P + 1, 0);
	for (long long int i = 1; i <= N; i++)
	{
		for (long long int j = 1; j <= P; j++)
		{
			if (festivales[i - 1].precio > j)
				maxArtistas[i][j] = maxArtistas[i - 1][j];
			else
				maxArtistas[i][j] = max(maxArtistas[i - 1][j], maxArtistas[i - 1][j - festivales[i - 1].precio] + festivales[i - 1].grupos);
		}
	}
	return maxArtistas[N][P];
}
bool resuelveCaso() {

	// leer los datos de la entrada
	int P, N;
	cin >> P >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	vector<infoFesti>festivales;
	infoFesti f;
	for (int i = 0; i < N; i++) {
		cin >> f.grupos >> f.precio;
		festivales.push_back(f);
	}
	cout << numFestivales(festivales, P, N) << "\n";
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
