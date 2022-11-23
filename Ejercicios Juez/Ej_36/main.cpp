/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Laura Gomez Bodego Marp19
  * Estudiante 2: Miguel Hernández García Marp22
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
using namespace std;


/*@ <answer>
 Para resolver el problema recogemos en una cola doble los pesos y la ordenamos de mayor a menor, luego
 sacamos a una variable al mayor de la cola; comparamos la suma del mayor con el menor de la cola, si es
 menor o igual que el peso maximo soportado mandamos a los dos, sacando tambien al ultimo de la cola, y se suma
 una silla, si no, no se saca al ultimo de la cola y se manda solo al primero.

 coste: O(NlogN), siendo N el número de personas de la cola.

 Demostración:
	cola: c[0] >= c[1] >= ....... c[i] >= ....c[j] >= c[n]

	Sol voraz: (c[1], c[n]), (c[2], c[n-1]), ... |(c[i],c[j]), ..., (c[k],c[l])
					=				=			 |	  !=
	Sol óptima:(c[1], c[n]), (c[2], c[n-1]), ... |(c[i],c[l]),  ..., (c[k],c[j])

	Por el método de reducción de diferencias:
		¿Podemos intercambiar c[l] por c[j] y que la solución siga siendo óptima?
	
		-c[l] => c[j], por tanto la suma de c[i] + c[j] va a ser <= que c[i] + c[l],
		siendo posible cambiar entonces c[l] por c[j] en la solución óptima, creando así una
		suma de pesos menor, que sigue manteniendo la cantidad óptima de sillas utilizada

		-si c[l] es un espacio vacío, al intercambiarlo por c[j] la solución sigue siendo óptima porque
		se montan dos en la misma silla(c[i], c[j]), y el número de sillas utilizadas no aumenta

		-si c[j] es un espacio vacío, al intercambiarlo por c[l] la solución sigue siendo óptima porque
		pasan de montarse 2 a montarse 1 en la silla, pero número de sillas utilizadas no aumenta

	En todos los casos la estrategia voraz es mejor o igual que la solución óptima

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
int nSillasUsadas(deque<int>& pesosFila, int pMax) {
	int nSillas = 0;
	while (!pesosFila.empty()) {
		int p1 = pesosFila.front();
		pesosFila.pop_front();
		if (!pesosFila.empty() && p1 + pesosFila.back() <= pMax) {
			pesosFila.pop_back();
		}
		nSillas++;
	}
	return nSillas;
}


bool resuelveCaso() {

	int pMax, N;
	cin >> pMax >> N;

	if (!cin)
		return false;

	// leer el resto del caso y resolverlo
	deque<int> pesosFila;
	int p;
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		pesosFila.push_back(p);
	}
	sort(pesosFila.begin(), pesosFila.end(), greater<int>());
	cout << nSillasUsadas(pesosFila, pMax) << "\n";

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
