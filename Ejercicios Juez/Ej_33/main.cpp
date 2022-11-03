/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Laura Gómez Bodego MARP19
  * Estudiante 2: Miguel Hernández García  MARP22
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>

#include "PriorityQueue.h"
using namespace std;


/*@ <answer>

La estrategia voraz consiste en hallar la mayor diferencia posible en los partidos entre los puntos de los Broncos y
los puntos del equipo rival. Para esto metemos los datos en dos Priority Queue, la de los puntos de los rivales de 
menores y la de los del equipo de mayores, de tal manera que se van a juntar los máximos puntos de los Broncos con 
los mínimos de los rivales, formando así la diferencia máxima. Si no han ganado los Broncos se ignoran los resultados
de ahi en adelante, porque al ser una cola de menores y una de mayores, no se van a encontrar más casos en los que ganen
los Broncos.
El coste de este algoritmo es de O(N logN),siendo N el número de partidos, porque ordena las priority queue y las recorre 
enteras una vez en el caso peor.

Las soluciones son parejas de puntos cuya diferencia es la mayor posible. Para comparar las soluciones del algoritmo voraz
con la solución óptima se colocan ambas colas con su orden correspondiente

sol Voraz->
	-rivales: r[1] <= r[2] <= r[3] <= r[4] .............|<= r[i] ..... <= r[j]
	-Broncos: b[1] >= b[2] >= b[3] >= b[4] .............|>= b[i] ..... >= b[j]
				=		=		=		=				|   !=
sol Óptima->  o[1] .. o[2] .. o[3] .. o[4] .............|.. o[j] ........ o[i]

En este caso o[j] < b[i], ya que el vector está ordenado de forma descendente, cualquier valor j será menor que el de
la solución voraz, ya que los elementos mayores ya han sido utilizados anteriormente.
 -Si o[j] < b[i] quiere decir que b[j] sería menor que b[i] y la diferencia ya no sería máxima


@ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
int difMaxima(PriorityQueue<int, less<int>>& pRivales, PriorityQueue<int, greater<int>>& pEquipo) {
	int dif = 0;
	while (!pEquipo.empty()&&pEquipo.top() > pRivales.top()) {
		dif += pEquipo.top() - pRivales.top();
		pRivales.pop();
		pEquipo.pop();
	}
	return dif;
}


bool resuelveCaso() {
	int N;
	cin >> N;  // número de partidos
	if (N == 0)
		return false;
	// leer el resto del caso y resolverlo
	PriorityQueue<int, less<int>> pRivales;
	PriorityQueue<int, greater<int>> pEquipo;
	int p;
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		pRivales.push(p);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		pEquipo.push(p);
	}
	cout << difMaxima(pRivales, pEquipo) << "\n";
	return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

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
	// system("PAUSE");
#endif
	return 0;
}
