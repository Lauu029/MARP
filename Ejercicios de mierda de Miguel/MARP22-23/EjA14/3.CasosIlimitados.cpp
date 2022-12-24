
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void recursivoAlcanceTTL(Grafo const& grafo, std::vector<bool>& visitados, int v, int TTL, int& tam) {
    if (visitados[v] == false) {
        visitados[v] = true;
        tam++;
    }
    if (TTL > 0) {
        for (int w : grafo.ady(v)) {
            recursivoAlcanceTTL(grafo, visitados, w, TTL - 1, tam);
        }
    }
}

void bfs(Grafo const& g, std::vector<bool>& visit, int v, int TTL, int& tam) {
    std::queue<int> q;
    visit[v] = true;
    tam++;
    q.push(v);
    std::vector<int> TTLs(g.V());
    TTLs[v] = TTL;
    if (TTL > 0) {
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (TTLs[v] > 0) {
                for (int w : g.ady(v)) {
                    if (!visit[w]) {
                        visit[w] = true;
                        tam++;
                        TTLs[w] = TTLs[v] - 1;
                        q.push(w);
                    }
                }
            }
        }
    }
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    Grafo grafo = Grafo(std::cin, 1);

    if (!std::cin)
        return false;

   int numConsultas;
   std::cin >> numConsultas;

   int nodoInicial;
   int TTL;
   int tam = 0;
   for (int i = 0; i < numConsultas; ++i) {
       std::vector<bool> visitados(grafo.V(), false);
       std::cin >> nodoInicial >> TTL;
       tam = 0;
       /*recursivoAlcanceTTL(grafo, visitados, nodoInicial - 1, TTL, tam);*/
       bfs(grafo, visitados, nodoInicial - 1, TTL, tam);
       std::cout << grafo.V() - tam << "\n";
   }

   std::cout << "---\n";
   
   // resolver el caso posiblemente llamando a otras funciones
   
   // escribir la solución

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
