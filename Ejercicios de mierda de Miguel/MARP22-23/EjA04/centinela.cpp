
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include <queue>  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Usuario {
public:
	//Identificador del usuario
	int ident;
	//Periodicidad del usuario
	long int perioInicial;
	//Proximo instante de tiempo desde el registro en el que se tiene que mandar info
	long int perio;
	Usuario(int identAux, long int perioAux) : ident(identAux), perio(perioAux), perioInicial(perioAux) {}
	const bool operator<(const Usuario& a) {
		if (a.perio == perio) {
			return a.ident < ident;
		}
		else {
			return a.perio < perio;
		}
	}
	const bool operator>(const Usuario& a) {
		if (a.perio == perio) {
			return a.ident > ident;
		}
		else {
			return a.perio > perio;
		}
	}
};

bool operator<(Usuario const& a, Usuario const& b) {
	if (a.perio == b.perio) {
		return a.ident < b.ident;
	}
	else {
		return a.perio < b.perio;
	}
}

bool operator>(Usuario const& a, Usuario const& b) {
	if (a.perio == b.perio) {
		return a.ident > b.ident;
	}
	else {
		return a.perio > b.perio;
	}
}

bool resuelveCaso() {

	int nNumeros;

	// leer los datos de la entrada

	std::cin >> nNumeros;

	if (nNumeros == 0)
		return false;

	std::priority_queue<Usuario, std::vector<Usuario>, std::greater<Usuario>> queue;
	int ident, perio;
	for (int i = 0; i < nNumeros; ++i) {
		std::cin >> ident >> perio;
		Usuario auxUsuario(ident, perio);
		queue.push(auxUsuario);
	}

	int maxConsultas;
	std::cin >> maxConsultas;

	while (maxConsultas > 0) {
		//Escribimos el usuario mas prioritario
		std::cout << queue.top().ident << "\n";
		//Volvemos a meter al mismo usuario en la cola pero retrasando su instante de tiempo
		Usuario auxUsuario = queue.top();
		queue.pop();
		auxUsuario.perio += auxUsuario.perioInicial;
		queue.push(auxUsuario);
		maxConsultas--;
	}

	std::cout << "---" << "\n";

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
