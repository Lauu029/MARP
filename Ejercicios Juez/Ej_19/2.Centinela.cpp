
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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
class Trampas {
private:
	vector<bool> visitado;
	vector<int>distancia;
	vector <int> anterior;
	int dado;
	int ultCas;
	void bfs(Digrafo const& dig) {
		std::queue<int> q;
		distancia[0] = 0; visitado[0] = true;
		q.push(0);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int i = 1; i <= dado; i++)
			{
				int cas = v + i;
				if (cas <= ultCas) {

					distancia[cas] = distancia[v] + 1;
					if (cas == ultCas) return;
					for (int w : dig.ady(cas)) {
						//if (!visitado[w]) {
							anterior[w] = v;
							distancia[w] = distancia[cas];
							visitado[w] = true;
							q.push(w);
						//}
					}
				}
				//q.push(cas);
			}
		}
	}
public:
	Trampas(Digrafo const& dig, int K, int ult) : visitado(dig.V(), false), distancia(dig.V()), anterior(dig.V()), dado(K), ultCas(ult) {
		bfs(dig);
	}
	int nTiradas(int cas) const {
		return distancia[cas];
	}
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, K, S, E;
	cin >> N >> K >> S >> E;
	if (N == 0)
		return false;
	int n1, n2;
	int tamTablero = N * N;
	Digrafo tablero(N * N);
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		int top = K;
	//		int casilla = i * 10 + j;
	//		if (casilla + top > tamTablero)top = tamTablero - casilla;
	//		for (int k = 1; k < top; k++)
	//		{
	//			tablero.ponArista(casilla, i * 10 + j + k);
	//		}
	//	}
	//}
	for (int i = 0; i < S + E; i++)
	{
		cin >> n1 >> n2;
		tablero.ponArista(n1 - 1, n2 - 1);
	}
	// resolver el caso posiblemente llamando a otras funciones
	Trampas t(tablero, K, tamTablero-1);

	cout << t.nTiradas(tamTablero - 1) << "\n";
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
