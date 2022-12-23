
/*@ <answer>
 *
 * Nombre y Apellidos:
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

void resuelveRecursivo(const Grafo& grafo, std::vector<bool>& visitados, int v, bool& grafoLibre, int anterior, int& numVerticesVisitados) {
    if (grafoLibre) {
        std::vector<int> adyacentes = grafo.ady(v);
        visitados[v] = true;
        numVerticesVisitados++;
        for (int i = 0; i < adyacentes.size(); ++i) {
            if (adyacentes[i] != anterior) {
                if (anterior != adyacentes[i]) {
                    if (!visitados[adyacentes[i]]) {
                        resuelveRecursivo(grafo, visitados, adyacentes[i], grafoLibre, v, numVerticesVisitados);
                    }
                    else {
                        grafoLibre = false;
                    } 
                }
            }
        }
    }
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    /*int numV, numA;

    std::cin >> numV;*/

    Grafo grafo = Grafo(std::cin, 0);

    if (!std::cin)  // fin de la entrada
      return false;

    /*Grafo* grafo = new Grafo(numV);

    std::cin >> numA;

    for (int i = 0; i < numA; ++i){
    }*/
   
   // resolver el caso posiblemente llamando a otras funciones
   
    int numV = grafo.V();
    bool grafoLibre = true;
    std::vector<bool> visitados(numV);
    std::vector<int> adyacentes;
    visitados[0] = true;
    int numVerticesVisitados = 1;


    adyacentes = grafo.ady(0);
    for (int i = 0; i < adyacentes.size(); ++i) {
        resuelveRecursivo(grafo, visitados, adyacentes[i], grafoLibre, 0, numVerticesVisitados);
    }

   // escribir la solución

    if (grafoLibre && numVerticesVisitados == grafo.V())
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

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
