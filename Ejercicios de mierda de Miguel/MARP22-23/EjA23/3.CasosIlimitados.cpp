
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"
#include "ARM.h"

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
   
   // leer los datos de la entrada
    int V;

    std::cin >> V;

   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones

   int A;

   std::cin >> A;

   GrafoValorado<int> grafo(V);
   int primero, segundo, coste;
   //set<Arista<int>> aristasOrdenadas;
   for (int i = 0; i < A; ++i) {
       std::cin >> primero >> segundo >> coste;
       grafo.ponArista({ primero - 1, segundo - 1, coste });
       //aristasOrdenadas.insert({ primero - 1, segundo - 1, coste });
   }

   ARM_Kruskal<int> arm(grafo);

   /*ConjuntosDisjuntos conjunto(V);
   set<Arista<int>>::iterator it = aristasOrdenadas.begin();
   int costo = 0;
   while (it != aristasOrdenadas.end()) {
       Arista<int> auxArista = *it;
       if (!conjunto.unidos(auxArista.uno(), auxArista.otro(auxArista.uno()))) {
           conjunto.unir(auxArista.uno(), auxArista.otro(auxArista.uno()));
           costo += auxArista.valor();
       }
       it++;
   }*/
   
   // escribir la solución
   if (arm.numConjuntos() > 1) {
       std::cout << "No hay puentes suficientes\n";
   }
   else
       std::cout << arm.costeARM() << "\n";

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
