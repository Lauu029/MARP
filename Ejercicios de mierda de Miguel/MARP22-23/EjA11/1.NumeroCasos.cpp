
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

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

int recursivo(Grafo const& grafo, std::vector<bool>& visitados, int v) {
    visitados[v] = true;
    int tam = 1;
    for (int w : grafo.ady(v)) {
        if (!visitados[w]) {
            tam += recursivo(grafo, visitados, w);
        }
    }
    return tam;
}

void resuelveCaso() {
   
   // leer los datos de la entrada
    Grafo grafo = Grafo(std::cin, 1);
    
   // resolver el caso posiblemente llamando a otras funciones
    std::vector<bool> visitados(grafo.V(), false);
    int maximo = 0;

    for (int v = 0; v < grafo.V(); ++v) {
        if (!visitados[v]) {
            int tam = recursivo(grafo, visitados, v);
            maximo = max(maximo, tam);
        }
    }

   // escribir la solución
    std::cout << maximo << "\n";
}



//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
