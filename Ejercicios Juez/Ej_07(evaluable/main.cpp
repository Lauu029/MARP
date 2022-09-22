/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Laura Gómez Bodego  MARP19
  * Estudiante 2: Miguel Hernández García  MARP22
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include "PriorityQueue.h"

using namespace std;


/*@ <answer>


 Coste del algoritmo: O(NlogN + ClogN) siendo N el número de cajas y C el número de clientes

 Solución: Se utiliza una cola de prioridad para guardar las cajas, para C número de clientes se suma su tiempo al de la caja
 con menor tiempo acumulado y se vuelve a meter esta en la cola. La caja que tenga mayor prioridad en la cola es la que tiene
 menos tiempo de espera.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
struct caja {
	int numCaja;
	int tiempo;
};
bool operator< (caja const& a, caja const& b) {
	return a.tiempo < b.tiempo || (a.tiempo == b.tiempo && a.numCaja < b.numCaja);
}


bool resuelveCaso() {

	// leemos la entrada
	int N, C;
	cin >> N >> C;
	if (N == 0)
		return false;

	PriorityQueue<caja, less<caja>> colas;

	// leer el resto del caso y resolverlo
	//Identificador de las cajas
	int time = 0;
	caja aten;
	for (int i = 1; i <= N; i++)
		colas.push({ i,0 });

	for (int i = 0; i < C; i++)
	{
		aten = colas.top();
		colas.pop();
		cin >> time;
		aten.tiempo += time;
		colas.push(aten);
	}
	cout << colas.top().numCaja << "\n";

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

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
