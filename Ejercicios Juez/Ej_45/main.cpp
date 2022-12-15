/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Laura Gómez Bodego Marp19
  * Estudiante 2: Miguel Hernández García Marp22
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Matriz.h"
using namespace std;


//  IMPORTANTE: NO se admiten soluciones basadas en el algoritmo (y recurrencia)
//  de Floyd. Hay que pensar una recurrencia específica para este problema
//  que intente sacar partido de que el río solamente se puede recorrer en un
//  sentido.


/*@ <answer>
Recursión:

	si i>=j viaje(i,j)=0 (solo nos interesa lo de encima de la diagonal porque solo se
			puede ir en una dirección)
	viaje(i,j) = minimo{ i < K <= j }-> minimo(alquiler(i,k) + viaje(k,j))

Coste del algoritmo:
	O(N*N*N)= O(N^3) siendo N el numero de ciudades y K la ciudad intermedia en caso de que se pare
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

void minimosCostes(Matriz<int>& viajes, Matriz<int> const& alquileres, int N) {

	for (int d = 1; d < N; d++)
	{
		for (int i = 0; i < N - d; i++)
		{
			int j = i + d;
			if (i >= j)
				viajes[i][j] = 0;
			else {
				int minimo = 100000000;
				for (int k = i + 1; k <= j; k++)
				{
					int coste = alquileres[i][k] + viajes[k][j];
					if (minimo > coste)
						minimo = coste;
				}
				viajes[i][j] = minimo;
			}
		}
	}
}
bool resuelveCaso() {

	// leemos la entrada
	int N;
	cin >> N;

	if (!cin)
		return false;

	// leemos los alquileres
	Matriz<int> alquiler(N, N, 0);
	for (int i = 0; i < N - 1; ++i)
		for (int j = i + 1; j < N; ++j)
			cin >> alquiler[i][j];
	// resolver el caso
	Matriz<int> viaje(N, N, 0);
	minimosCostes(viaje, alquiler, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
			cout << viaje[i][j] << " ";
		cout << "\n";
	}
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
