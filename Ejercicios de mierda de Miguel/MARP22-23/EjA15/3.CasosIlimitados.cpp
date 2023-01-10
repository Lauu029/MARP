
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


bool resuelveCaso() {

	int inicio;
	// leer los datos de la entrada
	std::cin >> inicio;

	if (!std::cin)  // fin de la entrada
		return false;

	int fin;
	std::cin >> fin;

	if (inicio == fin) {
		std::cout << "0\n";
		return true;
	}

	const int MAX = 10000;    //Maximo valor posible en la calculadora + 1
	const int INF = 20000;   //Valor imposible de alcanzar que solo simboliza que no se ha calculado ese valor

	std::vector<int> distancias(MAX, INF);
	distancias[inicio] = 0;

	// resolver el caso posiblemente llamando a otras funciones
	std::queue<int> queue;
	queue.push(inicio);
	//Modulo 10000 porque la maquina calculadora tiene 4 digitos, por lo que si se pasa de los 4 digitos vuelve al inicio
	//10000 == 0
	int next1, next2, next3;
	//Hacemos la asignacion en la condicion del while para que lo haga todo solo una vez y optimizar
	while (((next1 = ((queue.front() + 1) % MAX)) != fin) && ((next2 = ((queue.front() * 2) % MAX)) != fin) && ((next3 = (queue.front() / 3)) != fin)) {
		if (distancias[next1] == INF) {
			distancias[next1] = distancias[queue.front()] + 1;
			queue.push(next1);
		}
		if (distancias[next2] == INF) {
			distancias[next2] = distancias[queue.front()] + 1;
			queue.push(next2);
		}
		if (distancias[next3] == INF) {
			distancias[next3] = distancias[queue.front()] + 1;
			queue.push(next3);
		}
		queue.pop();
	}

	// escribir la solución
	std::cout << distancias[queue.front()] + 1 << "\n";

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
