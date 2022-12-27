
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "Dijkstra.h"

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

std::vector<bool> visit;

void dfs(GrafoValorado<int> const& G, int v, int final, std::vector<int>& caminoActual, int longitudActual, int& longitudCaminoMasCorto, int& numManeras) {
    visit[v] = true;
    caminoActual.push_back(v);

    if (v == final){
        if (longitudActual < longitudCaminoMasCorto) {
            longitudCaminoMasCorto = longitudActual;
            numManeras = 1;
        }
        else {
            if (longitudActual == longitudCaminoMasCorto)
                numManeras++;
        }
    }
    else {
        for (auto a : G.ady(v)) {
            int w = a.otro(v);
            if (!visit[w])
                dfs(G, w, final, caminoActual, longitudActual + a.valor(), longitudCaminoMasCorto, numManeras);
        }
    }
    
    visit[v] = false;
    caminoActual.pop_back();
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    GrafoValorado<int> grafo = GrafoValorado<int>(std::cin, 1);

   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones

   Dijkstra grafoDij = Dijkstra(grafo, 0);

   grafoDij.distancia(grafo.V() - 1);

   visit = std::vector<bool>(grafo.V(), false);

   std::vector<int> camino;
   int longitudCaminoMasCorto, numManeras;

   longitudCaminoMasCorto = INT_MAX;
   numManeras = 0;

   dfs(grafo, 0, grafo.V() - 1, camino, 0, longitudCaminoMasCorto, numManeras);

   // escribir la solución
   std::cout << numManeras << "\n";

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
