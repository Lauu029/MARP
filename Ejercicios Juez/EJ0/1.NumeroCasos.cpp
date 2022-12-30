
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <map>
#include <math.h>
#include <vector>
#include "bintree.h"  // propios o los de las estructuras de datos de clase

using namespace std;
///*@ <answer>
//
// Escribe aquí un comentario general sobre la solución, explicando cómo
// se resuelve el problema y cuál es el coste de la solución, en función
// del tamaño del problema.
//
// @ </answer> */
//
//
// // ================================================================
// // Escribe el código completo de tu solución aquí debajo
// // ================================================================
// //@ <answer>
//
//
//bool esAVL(const bintree<int>& caso, bool& noEs, int& alt) {
//	if (noEs == false) return false;
//	if (caso.empty()) return true;
//	if (caso.left().empty() && caso.right().empty()) {
//		alt = 1;
//		return true;
//	}
//	int izq = 0, der = 0;
//	bool izqAVL = true, derAVL = true;
//	if (!caso.left().empty()) {
//		izqAVL = esAVL(caso.left(), noEs, izq);
//	}
//	if (!caso.right().empty()) {
//		derAVL = esAVL(caso.right(), noEs, der);
//	}
//	alt = 1 + max(izq, der);
//	noEs = (abs(izq - der) <= 1) && izqAVL && derAVL;
//	return noEs;
//}
//bool esBinario(const bintree<int>& caso) {
//	if (caso.empty())return true;
//	vector<int> inorden = caso.inorder();
//	int i = 0;
//	while (i + 1 < inorden.size())
//	{
//		if (inorden[i] >= inorden[i + 1]) return false;
//		++i;
//	}
//	bool avl = true;
//	int alt = 0;
//	return esAVL(caso, avl, alt);
//}
//void resuelveCaso() {
//
//	// leer los datos de la entrada
//	bintree<int> caso;
//	caso = leerArbol(-1);
//	// resolver el caso posiblemente llamando a otras funciones
//	if (esBinario(caso)) cout << "SI\n";
//	else cout << "NO\n";
//	// escribir la solución
//}

bool esAVL(bintree<int> arbol, int& h, bool& avl) {
	if (!avl) return false;
	if (arbol.empty())
		return true;
	if (arbol.left().empty() && arbol.right().empty()) {
		h = 1;
		return true;
	}
	int izq = 0, der = 0;
	bool izqAVL = true, derAVL = true;
	if (!arbol.left().empty())
		izqAVL = esAVL(arbol.left(), izq, izqAVL);
	if (!arbol.right().empty())
		derAVL = esAVL(arbol.right(), der, derAVL);
	h = 1+ max(izq, der);
	avl = izqAVL && derAVL && abs(izq - der) <= 1;
	return avl;
}
bool esBinario(bintree<int>& arbol) {
	if (arbol.empty()) return true;
	vector<int> in = arbol.inorder();
	int i = 0;
	bool bin = true;
	while (i < in.size() - 1 && bin) {
		bin = in[i] < in[i + 1];
		i++;
	}
	int h = 0;
	return esAVL(arbol,h,bin);
}
void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int h = 0;
	bool avl = true;
	if (esBinario(arbol)) 
			cout << "SI\n";
	else cout << "NO\n";
}
//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
