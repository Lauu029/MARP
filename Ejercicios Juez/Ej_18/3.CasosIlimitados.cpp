
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class Sumideros {
private:
	vector<int> gEntrada;
	vector<int> gSalida;
	int nVertices;
	void dfs(Digrafo const& dig, int org) {
		gSalida[org] = dig.ady(org).size();
		for (auto v : dig.ady(org))
		{
			gEntrada[v]++;
		}
	}
public:
	Sumideros(Digrafo const& dig) : gSalida(dig.V(), 0), gEntrada(dig.V(), 0), nVertices(dig.V()) {
		for (int i = 0; i < dig.V(); i++)
		{
			dfs(dig, i);
		}
	}
	int haySumidero() {
		int i = 0;
		while (i < gEntrada.size()) {
			if (gSalida[i] == 0 && gEntrada[i] == nVertices - 1) return i;
			i++;
		}
		return -1;
	}
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int V, A;
	cin >> V >> A;
	if (!std::cin)  // fin de la entrada
		return false;
	Digrafo dig(V);
	int n1, n2;
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i < A; i++)
	{
		cin >> n1 >> n2;
		dig.ponArista(n1, n2);
	}

	Sumideros s(dig);
	int salida = s.haySumidero();
	// escribir la solución
	if (salida != -1) cout << "SI " << salida;
	else cout << "NO";

	cout << "\n";
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
