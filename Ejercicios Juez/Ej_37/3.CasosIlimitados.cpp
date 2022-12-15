
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
	int n = cordeles.size();
	Matriz<EntInf> cordelesMinimos(n + 1, L + 1, Infinito);
	cordelesMinimos[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		cordelesMinimos[i][0] = 0;
		for (int j = 1; j <= L; ++j)
			if (cordeles[i - 1].longitud > j)
				cordelesMinimos[i][j] = cordelesMinimos[i - 1][j];
			else
				cordelesMinimos[i][j] = min(cordelesMinimos[i - 1][j], cordelesMinimos[i - 1][j - cordeles[i - 1].longitud] + 1);
	}
	return cordelesMinimos[n][L];
}
//Precio con matriz
EntInf precioM(vector<infoCordel>const& cordeles, int L) {
	int n = cordeles.size();
	Matriz<EntInf> cordelesMinimos(n + 1, L + 1, Infinito);
	cordelesMinimos[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		cordelesMinimos[i][0] = 0;
		for (int j = 1; j <= L; ++j)
			if (cordeles[i - 1].longitud > j)
				cordelesMinimos[i][j] = cordelesMinimos[i - 1][j];
			else
				cordelesMinimos[i][j] = min(cordelesMinimos[i - 1][j], cordelesMinimos[i - 1][j - cordeles[i - 1].longitud] + cordeles[i - 1].precio);
	}
	return cordelesMinimos[n][L];
}
//formas de hacerlo con matriz
EntInf FormasM(vector<infoCordel>const& cordeles, int L) {
	int n = cordeles.size();
	Matriz<EntInf> cordelesMinimos(n + 1, L + 1, 0);
	cordelesMinimos[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		cordelesMinimos[i][0] = 1;
		for (int j = 1; j <= L; ++j) {
			if (cordeles[i-1].longitud > j)
				cordelesMinimos[i][j] = cordelesMinimos[i - 1][j];
			else
				cordelesMinimos[i][j] = cordelesMinimos[i - 1][j] + cordelesMinimos[i-1][j - cordeles[i-1].longitud];
		}
	}
	return cordelesMinimos[n][L];
}
//Numero de cordeles con vector
EntInf numCordelesV(vector<infoCordel>const& cordeles, int L) {
	int n = cordeles.size();
	vector<EntInf> cordelesMinimos(L + 1, Infinito);
	cordelesMinimos[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = L; j >= cordeles[i - 1].longitud; --j)
			if (cordeles[i - 1].longitud <= j)
				cordelesMinimos[j] = min(cordelesMinimos[j], cordelesMinimos[j - cordeles[i - 1].longitud] + 1);
	}
	return cordelesMinimos[L];
}

//Precio con vector
EntInf precioV(vector<infoCordel>const& cordeles, int L) {
	int n = cordeles.size();
	vector<EntInf> cordelesMinimos(L + 1, Infinito);
	cordelesMinimos[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = L; j >= cordeles[i - 1].longitud; --j)
			if (cordeles[i - 1].longitud <= j)
				cordelesMinimos[j] = min(cordelesMinimos[j], cordelesMinimos[j - cordeles[i - 1].longitud] + cordeles[i - 1].precio);
	}
	return cordelesMinimos[L];
}
//formas con vector
EntInf formasV(vector<infoCordel>const& cordeles, int L) {
	int n = cordeles.size();
	vector<EntInf> cordelesMinimos(L + 1, 0);
	cordelesMinimos[0] = 1;
	for (int i = 1; i <=n; ++i) {
		for (int j = L; j >= cordeles[i-1].longitud; --j) {
			cordelesMinimos[j] = cordelesMinimos[j - cordeles[i-1].longitud] + cordelesMinimos[j];
		}
	}
	return cordelesMinimos[L];
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
	Matriz<int> minimasCuerdas(N + 1, L + 1, -1);
	// escribir la solución
	EntInf solucionIngeniero = numCordelesM(cordeles, L);
	EntInf solucionEconomista = precioM(cordeles, L);
	EntInf solucionMatematico = FormasM(cordeles, L);
	if (solucionIngeniero != Infinito)
		cout << "SI " << solucionMatematico << " " << solucionIngeniero << " " << solucionEconomista << "\n";
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
