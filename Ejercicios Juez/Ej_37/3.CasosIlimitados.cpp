
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "EnterosInf.h"
#include "Matriz.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct infoCordel {
	int longitud;
	int precio;
};

//Numero de cordeles con matriz
EntInf numCordelesM(vector<infoCordel>const& cordeles, int L) {
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < cordeles.size(); j++)
		{
			if (cordeles[i, j].longitud > L)
				;

		}
	}
}
//Precio con matriz
EntInf precioM(vector<infoCordel>const& cordeles, int L) {


}
//formas de hacerlo con matriz
EntInf FormasM(vector<infoCordel>const& cordeles, int L) {

}
//Numero de cordeles con vector
EntInf numCordelesV(vector<infoCordel>const& cordeles, int L) {

}

//Precio con vector
EntInf precioV(vector<infoCordel>const& cordeles, int L) {

}
//formas con vector
EntInf formasV(vector<infoCordel>const& cordeles, int L) {

}
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, L;
	cin >> N >> L;
	if (!std::cin)  // fin de la entrada
		return false;
	vector<infoCordel>cordeles(N);
	// resolver el caso posiblemente llamando a otras funciones
	for (int i = 0; i < N; i++)
		cin >> cordeles[i].longitud >> cordeles[i].precio;

	Matriz<EntInf> minimoPrecio(N + 1, L + 1, Infinito);
	Matriz<EntInf> minimasCuerdas(N + 1, L + 1, Infinito);

	// escribir la solución
	EntInf solucionEconomista = precioM(cordeles, L);
	EntInf costeMinimo = numCordelesM(cordeles, L);
	EntInf solucionMatematico = FormasM(cordeles, L);
	if (costeMinimo != Infinito)
		cout << "SI " << solucionMatematico << " " << costeMinimo << " " << solucionEconomista << "\n";
	else cout << "NO\n";
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
