
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream> 
#include <vector>
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

int numParches(vector<int> const& posiciones, int L) {
	int numParches = 1;
	int distancia = posiciones[0] + L;
	for (int i = 0; i < posiciones.size(); i++)
	{
		if (posiciones[i] > distancia) {
			numParches++;
			distancia = posiciones[i] + L;
		}
	}
	return numParches;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int N, L;
	cin >> N >> L;
	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> posiciones;
	int pos;
	for (int i = 0; i < N; i++)
	{
		cin >> pos;
		posiciones.push_back(pos);
	}
	cout << numParches(posiciones, L) << "\n";
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
