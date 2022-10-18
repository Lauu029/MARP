
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
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
class OrdenaTareas {
private:
	vector <bool> visitadas;
	deque<int> _orden;
	vector <bool> apilado;
	bool ciclo;
	void dfs(Digrafo const& d, int v) {
		apilado[v] = true;
		visitadas[v] = true;
		for (int w : d.ady(v))
		{
			 if (ciclo) break;
			if (!visitadas[w])
				dfs(d, w);
			else if (apilado[w])
				ciclo = true;
		}
		apilado[v] = false;
		_orden.push_front(v);
	}
public:
	OrdenaTareas(Digrafo const& d) : visitadas(d.V(), false), apilado(d.V(), false), ciclo(false) {
		for (int i = 0; i < d.V(); i++)
		{
			if (!visitadas[i])
				dfs(d, i);
		}
	};
	bool hayCiclo() {
		return ciclo;
	}
	deque <int> const& orden() {
		return _orden;
	}
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int V, A;
	cin >> V;
	if (!std::cin)  // fin de la entrada
		return false;
	cin >> A;
	Digrafo tareas(V);
	int n1, n2;
	for (int i = 0; i < A; i++)
	{
		cin >> n1 >> n2;
		tareas.ponArista(n1 - 1, n2 - 1);
	}
	// resolver el caso posiblemente llamando a otras funciones
	OrdenaTareas O(tareas);

	if (O.hayCiclo()) cout << "IMPOSIBLE";
	else {
		deque <int> salidaOrden = O.orden();
		while (!salidaOrden.empty()) {
			cout << salidaOrden.front() + 1<<" ";
			salidaOrden.pop_front();
		}
	}
	cout << "\n";
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
