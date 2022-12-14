
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
int numNecesitados(deque<int>& necesitados, deque<int>& disponibles) {
	int numNecesitados = 0;
	int indiceNecesitan = 0;
	int dif = 0;
	for (int numCamiseta = 0; numCamiseta < disponibles.size(); numCamiseta++) {
		if (indiceNecesitan < necesitados.size()) {

			dif = disponibles[numCamiseta] - necesitados[indiceNecesitan];
			if (dif == 0 || dif == 1)//le vale la camiseta
			{
				indiceNecesitan++;
			}
			else if(dif<0) {
				numNecesitados++;
				indiceNecesitan++;
				numCamiseta--;
			}
		}
	}
	return numNecesitados+(necesitados.size()-indiceNecesitan);
}
bool resuelveCaso() {
	int N, D;
	cin >> N >> D;
	if (!cin) return false;
	deque<int> necesitados(N, 0);
	deque<int>disponibles(D, 0);
	for (int i = 0; i < N; i++)
		cin >> necesitados[i];
	sort(necesitados.begin(), necesitados.end(), greater<int>());
	for (int i = 0; i < D; i++)
		cin >> disponibles[i];
	sort(disponibles.begin(), disponibles.end(), greater<int>());

	cout << numNecesitados(necesitados, disponibles) << "\n";
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
