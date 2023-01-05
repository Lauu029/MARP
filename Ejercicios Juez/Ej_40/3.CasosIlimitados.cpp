
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct infoCofre {
	int prof;
	int valor;
};
//recursión: rescate(i,j) maximo valor que conseguimos rescatar con tiempo máximo j, considerando los cofres de 1 a i
//casos base: i=0-> no hay objetos, valor=0
//			j=0-> no hay tiempo, valor=0
int rescate(int i, int j, Matriz<int>& resultados, vector<infoCofre>& cofres) {
	if (resultados[i][j] != -1)
		return resultados[i][j];
	if (i == 0 || j == 0) resultados[i][j] = 0;
	else {
		//¿valido?-> coste de subir y bajar(3*prof-> 1 bajar 2 subir) < tiempo  total
		if (cofres[i-1].prof * 3 > j)
			//va a por el objeto anterior
			resultados[i][j] = rescate(i - 1, j, resultados, cofres);
		else
			resultados[i][j] = max(rescate(i - 1, j, resultados, cofres), rescate(i-1, j - 3 * cofres[i-1].prof, resultados, cofres) + cofres[i-1].valor);
	}
	return resultados[i][j];
}
bool resuelveCaso() {

	int T, N;
	cin >> T >> N;
	if (!std::cin)
		return false;
	vector<infoCofre> cofres;
	infoCofre c;
	for (int i = 0; i < N; i++)
	{
		cin >> c.prof >> c.valor;
		cofres.push_back(c);
	}
	Matriz<int>resultados(N + 1, T + 1, -1);
	cout << rescate(N, T, resultados, cofres)<<"\n";
	int numRescatados = 0;
	vector<bool> solucion(N, false);
	int i = N, j = T;
	while (i > 0 && j > 0) {
		if (resultados[i][j] != resultados[i - 1][j]) {
			j -= 3 * cofres[i - 1].prof;
			numRescatados++;
			solucion[i-1] = true;
		}
		i--;
	}
	cout << numRescatados << "\n";
	for (int i = 0; i < solucion.size(); i++)
	{
		if (solucion[i])cout << cofres[i].prof << " " << cofres[i].valor << "\n";
	}

	cout << "---\n";
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
