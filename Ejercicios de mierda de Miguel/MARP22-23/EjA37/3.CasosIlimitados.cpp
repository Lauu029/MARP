
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"
#include "EnterosInf.h"

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct cordelInfo {
    EntInf minimoNumCuerdas = Infinito;
    EntInf coste = Infinito;
	long long int numPosibilidades = 0;
};

cordelInfo coste_Cordeles(vector<int> const& costes, vector<int> const& longitud, int longitudPedida) {

	vector<EntInf> costesCuerdas(longitudPedida + 1, Infinito);
	vector<EntInf> minimoNumCuerdas(longitudPedida + 1, Infinito);
	vector<long long int> numPosibilidades(longitudPedida + 1, 0);
	int n = costes.size();
	costesCuerdas[0] = 0;
	minimoNumCuerdas[0] = 0;
	numPosibilidades[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = longitudPedida; j >= longitud[i]; --j) {
			numPosibilidades[j] = numPosibilidades[j - longitud[i]] + numPosibilidades[j];
		}
	}
	if (numPosibilidades[longitudPedida] > 0) {
		for (int i = 0; i < n; i++)
		{
			for (int j = longitudPedida; j >= longitud[i]; --j)
			{
				costesCuerdas[j] = min(costesCuerdas[j], costesCuerdas[j - longitud[i]] + costes[i]);
				minimoNumCuerdas[j] = min(minimoNumCuerdas[j], minimoNumCuerdas[j - longitud[i]] + 1);
			}
		}
	}
	
	cordelInfo auxInfo;
	auxInfo.coste = costesCuerdas[longitudPedida];
	auxInfo.minimoNumCuerdas = minimoNumCuerdas[longitudPedida];
	auxInfo.numPosibilidades = numPosibilidades[longitudPedida];
	return auxInfo;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int numCordeles;

    std::cin >> numCordeles;

    if (!std::cin)  // fin de la entrada
      return false;

    int longitudPedida;

    std::cin >> longitudPedida;

	vector<int> longitudes;
	vector<int> costes;

	int auxLongitud, auxCoste;
	for (int i = 0; i < numCordeles; ++i) {
		std::cin >> auxLongitud >> auxCoste;
		longitudes.push_back(auxLongitud);
		costes.push_back(auxCoste);
	}
   
   // resolver el caso posiblemente llamando a otras funciones
	cordelInfo resultado = coste_Cordeles(costes, longitudes, longitudPedida);
   

   // escribir la solución
	if (resultado.numPosibilidades != 0) {
		std::cout << "SI " << resultado.numPosibilidades << " " << resultado.minimoNumCuerdas << " " << resultado.coste << "\n";
	}
	else {
		std::cout << "NO\n";
	}

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
