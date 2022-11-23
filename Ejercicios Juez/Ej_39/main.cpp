/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1:
  * Estudiante 2:
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "EnterosInf.h"
#include "Matriz.h"
using namespace std;


/*@ <answer>
* Laura Gómez Bodego MARP19
* Miguel Hernández García MARP22
* 
Coste de la solución:
	tamaño en memoria: pMax, ya que utilizamos un vector para sacar la solución óptima
	coste en tiemppo: pMax * n siendo n el número de bombillas

	para sacar la solución tenemos un vector que va almacenando las soluciones con menor coste
	el vector está inicializado a 0 para una potencia de 0 y a infinito para el resto de los casos
	en cada vuelta al vector comprueba el menor coste entre utilizar el coste de la bombilla anterior o
	utilizar su valor, resta la potencia de la bombilla a la total y añade el coste que supondría coger esa bombilla
	cuando tenemos el vector completo buscamos el mínimo de ese vector y guardamos en que posición está ese mínimo
	para saber que potencia se ha utilizado
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
EntInf coste_bombillas(vector<int> const& costes, vector<int> const& potencias, int pMin, int pMax, int& pos) {

	vector<EntInf> costesBombillas(pMax + 1, Infinito);
	int n = costes.size();
	costesBombillas[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= pMax; j++)
		{
			if (potencias[i] <= j)
				costesBombillas[j] = min(costesBombillas[j], costesBombillas[j - potencias[i]] + costes[i]);

		}
	}
	EntInf minimo = Infinito;
	for (int i = pMin; i <= pMax; i++)
	{
		if (minimo > costesBombillas[i]) {
			minimo = costesBombillas[i];
			pos = i;
		}
	}
	return minimo;
}

bool resuelveCaso() {

	int N, PMax, PMin;
	cin >> N >> PMax >> PMin;
	if (!cin)  return false;

	vector<int> potencias(N);
	vector<int> costes(N);

	for (int i = 0; i < N; i++)
		cin >> potencias[i];
	for (int i = 0; i < N; i++)
		cin >> costes[i];

	if (N == 0)
		return false;
	int pos = -1;
	EntInf sol = coste_bombillas(costes, potencias, PMin, PMax, pos);
	// leer el resto del caso y resolverlo

	if (pos == -1)
		cout << "IMPOSIBLE\n";
	else
		cout << sol << " " << pos << "\n";

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
