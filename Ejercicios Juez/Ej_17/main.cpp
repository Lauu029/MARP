/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Laura Gómez Bodego MARP19
  * Estudiante 2: Miguel Hernandez García MARP22
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

#include "Grafo.h"
#include "RedSocial.h"

using namespace std;


/*@ <answer>
Para resolver el problema hacemos un recorrido en profundidad de un grafo para hallar la cantidad de vértices
conectados a cada vértice, y así ver cuantos amigos reciben la noticia desde cada nodo inicial.
La clase redSocial recibe un grafo y declara un vector que comprueba si cada vértice se ha visitado, un vector
que guarda el grupo al que pertenece cada vértice y un vector que guarda la cantidad de amigos de cada grupo.

RedSocial hace el recorrido en profundidad y devuelve la cantidad de vértices visitados desde uno
para saber cuantos usuarios están conectados a uno solo se devuelve el contenido del vector de cantidad de cada grupo
del grupo al que pertenece el vértice

Coste del algoritmo: O(V+A) siendo v el número de personas y A el número de conexiones de cada persona
porque se ha implementado un algoritmo de recorrido en profundidad en el que cada vértice se visita una sola vez

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>



bool resuelveCaso() {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;


	Grafo redes(N);

	int nPersonas;

	for (int i = 0; i < M; i++)
	{
		cin >> nPersonas;
		if (nPersonas > 0) {
			int a1, a2;
			cin >> a1;
			for (int j = 0; j < nPersonas - 1; j++)
			{
				cin >> a2;
				redes.ponArista(a1 - 1, a2 - 1);
			}
		}
	}

	redSocial red(redes);
	for (int i = 0; i < N; i++)
	{
		cout << red.getAmigos(i)<<" ";
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
