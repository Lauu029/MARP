
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <math.h>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int bfsModificado(Digrafo const& grafo, int actual, int final, int K) {
    std::queue<int> cola;
    cola.push(actual);
    int numTurnos = -1;
    bool llegadoAlFinal = false;
    std::vector<int> dist(final, 0);
    while (!cola.empty() && !llegadoAlFinal) {
        int v = cola.front(); cola.pop();
        for (int i = 1; i < K + 1; ++i) {
            if (v + i >= final - 1) {
                llegadoAlFinal = true;
                numTurnos = dist[v] + 1;
                break;
            }
            else {
                if (grafo.ady(v + i).size() > 0) {
                    if (dist[grafo.ady(v + i)[0]] == 0) {
                        dist[grafo.ady(v + i)[0]] = dist[v] + 1;
                        cola.push(grafo.ady(v + i)[0]);
                    }
                }
                else {
                    if (dist[v + i] == 0) {
                        dist[v + i] = dist[v] + 1;
                        cola.push(v + i);
                    }
                }
            }
        }
    }
    return numTurnos;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N, K, S, E;

    std::cin >> N >> K >> S >> E;
   
   if (N==0 && K==0 && S==0 && E==0)
      return false;

   if (N == 0 || K == 0) {
       std::cout << "0\n";
       return true;
   }

   Digrafo grafo(N * N);

   int inicial, final;
   for (int i = 0; i < S; ++i) {
       std::cin >> inicial >> final;
       grafo.ponArista(final, inicial);
   }
   for (int i = 0; i < E; ++i) {
       std::cin >> inicial >> final;
       grafo.ponArista(inicial, final);
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   bool llegadoAlFinal;

   
   int numTurnos = bfsModificado(grafo, 0, N * N, K);
   
   // escribir la solución
   std::cout << numTurnos << "\n";

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
