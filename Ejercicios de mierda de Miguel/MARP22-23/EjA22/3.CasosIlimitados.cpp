
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void canTransit(GrafoValorado<int>*& grafo, std::vector<int>& visitados, int origen, int destino, int umbral, bool& llegado) {
    visitados[origen] = true;
    if (origen == destino) {
        llegado = true;
    }
    else {
        for (auto a : grafo->ady(origen)) {
            if (a.valor() >= umbral) {
                int w = a.otro(origen);
                if (!visitados[w]) {
                    canTransit(grafo, visitados, w, destino, umbral, llegado);
                }
            }
        }
    }
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   
    GrafoValorado<int>* grafo = new GrafoValorado<int>(std::cin, 1);

   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   int numCasos, origen, destino, umbral;

   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i) {
       std::vector<int> visitados(grafo->V());
       bool llegado = false;
       std::cin >> origen >> destino >> umbral;
       canTransit(grafo, visitados, origen - 1, destino - 1, umbral, llegado);
       if (llegado)
           std::cout << "SI\n";
       else
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
