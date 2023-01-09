
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
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

struct Proyecto {
	int inicio, fin;
};

bool operator>(Proyecto const& a, Proyecto const& b) {
	if (a.inicio == b.inicio) {
		return a.fin < b.fin;
	}
	else {
		return a.inicio > b.inicio;
	}
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int C, F;
	int numProyectos;

	std::cin >> C >> F >> numProyectos;

	if (C == 0 && F == 0 && numProyectos == 0)
		return false;

	std::priority_queue<Proyecto, std::vector<Proyecto>, std::greater<Proyecto>> proyectos;
	int auxInicio, auxFin;
	Proyecto proyectoAux;
	for (int i = 0; i < numProyectos; ++i) {
		std::cin >> auxInicio >> auxFin;
		proyectoAux.inicio = auxInicio;
		proyectoAux.fin = auxFin;
		proyectos.push(proyectoAux);
	}

	// resolver el caso posiblemente llamando a otras funciones
	int numProyectosSol = 0;
	int lastProyectoFin = -1;
	int lastProyectoInicio = -1;
	bool imposible = false;
	while (!proyectos.empty() && !imposible && lastProyectoFin < F) {
		//Si no hay nada guardado utilizamos este proyecto por ejemplo para empezar si esta dentro del margen de tiempo al menos en parte
		if (lastProyectoFin == -1) {
			if (proyectos.top().inicio <= F && proyectos.top().fin >= C) {
				lastProyectoInicio = proyectos.top().inicio;
				lastProyectoFin = proyectos.top().fin;
				numProyectosSol++;
			}
		}
		else {
			//Si encontramos una tarea mejor nos quedamos con ella
			if (proyectos.top().inicio == lastProyectoInicio) {
				lastProyectoFin = max(lastProyectoFin, proyectos.top().fin);
			}
			//Si la tarea nos da mas posibilidad de tiempo que la anterior pero no la podemos reemplazar alegremente sin decidir que hay que meter otra tarea, añadimos una tarea nueva
			else if (proyectos.top().inicio > lastProyectoInicio && proyectos.top().inicio <= lastProyectoFin && proyectos.top().fin >= lastProyectoFin) {
				lastProyectoInicio = lastProyectoFin;
				lastProyectoFin = proyectos.top().fin;
				numProyectosSol++;
			}
			//Si la tarea esta muy alejada de la ultima es que no hay solucion
			else if (proyectos.top().inicio > lastProyectoFin) {
				imposible = true;
			}
		}
		
		proyectos.pop();
	}

	// escribir la solución
	if (imposible)
		std::cout << "Imposible\n";
	else
		std::cout << numProyectosSol << "\n";

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
