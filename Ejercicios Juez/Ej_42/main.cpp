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

#include "EnterosInf.h"
#include "Matriz.h"
using namespace std;


/*@ <answer>

Coste del algoritmo o(n*m) siendo n la longitud de la primera palabra y m de la segunda

Para resolver el problema, primero sacamos la longitud de la palabra mas larga de forma ascendente, metiendo cada
valor en una matriz, si la letra es igual se pone la longitud anterior mas uno y si no se pone el maximo entre la longitud
guardada por la letra anterior de la primera o la segunda palabra.

Luego reconstruimos la palabra recorriendo la matriz, si la letra coincide para las dos palabras se añade y se avanza en diagonal, si no
se avanza hacia abajo o la derecha en la matriz, dependiendo de donde se situe el mayor valor de longitud de palabra

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>


void tamMaxsubsecuencia(const string& p1, const string& p2, Matriz<int>& sub) {
	for (int i = p1.length() - 1; i >= 0; i--) {
		for (int j = p2.length() - 1; j >= 0; j--) {

			if (p1[i] == p2[j])
				sub[i][j] = sub[i + 1][j + 1] + 1;
			else
				sub[i][j] = max(sub[i + 1][j], sub[i][j + 1]);
		}
	}
}
void reconstruir(string const& pal1, string const& pal2, Matriz<int> const& sol, string& solucion) {

	int i = 0;
	int j = 0;
	while (i < pal1.length() && j < pal2.length()) {
		if (pal1[i] == pal2[j]) {
			solucion += pal1[i];
			i++;
			j++;
		}
		else if (sol[i + 1][j] >= sol[i][j+ 1]) {
			i++;
		}
		else j++;
	}

}
bool resuelveCaso() {

	// leemos la entrada
	string X, Y;
	cin >> X >> Y;

	if (!cin)
		return false;

	Matriz<int>sub(X.length() + 1, Y.length() + 1, 0);

	// resolver el caso
	tamMaxsubsecuencia(X, Y, sub);
	string solucion = "";
	reconstruir(X, Y, sub, solucion);

	cout << solucion << "\n";



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
