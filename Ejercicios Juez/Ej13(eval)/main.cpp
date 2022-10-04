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
#include <limits>
#include <queue>
#include "Queue_pajaros.h"
using namespace std;


/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Hemos implementado una clase queue pajaros que tiene dos colas de prioridad, una con los jovenes y otra con los viejos
 En esta clase hay un constructor al que se le mete el valor inicial y un addElemento; 
 addElemento mete el nuevo valor en una de las colas dependiendo si es mayor o no que top de la cola de jovenes(que es la mediana)
 luego equilibra las dos colas para que tengan la misma longitud o que como mucho jovenes tiene un elemento mas que viejos

 Coste-> O(2clogn) siendo c el numero de parejas que entran
	-el algoritmo addElemento tiene coste logn porque hace un numero equilibrado de push y pop y este se llama 2 veces por pareja de pajaros
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>



bool resuelveCaso() {
	long int primerPajaro, c;
	cin >> primerPajaro >> c;
	if (primerPajaro == 0) return false;

	queue_pajaros pajaro = queue_pajaros(primerPajaro);
	long int nuevoPajaro;
	for (long int i = 0; i < c; i++)
	{
		cin >> nuevoPajaro;
		pajaro.addElement(nuevoPajaro);
		cin >> nuevoPajaro;
		pajaro.addElement(nuevoPajaro);

		cout << pajaro.consultaMediana() << " ";
	}
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
  
  // Resolvemos
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
