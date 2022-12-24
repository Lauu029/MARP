
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
std::vector<int> ant; // ant[v] = vértice anterior en el camino a v
std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
int numRecorrido;
bool hayciclo;

void dfs(Digrafo const& g, int v, Digrafo const& grafoInverso) {
    apilado[v] = true;
    visit[v] = true;
    ant[numRecorrido] = v;
    numRecorrido++;
    for (int w : g.ady(v)) {
        if (hayciclo) // si hemos encontrado un ciclo terminamos
            return;
        if (!visit[w]) { // encontrado un nuevo vértice, seguimos
            bool canUse = true;
            for (int w : grafoInverso.ady(w)) {
                if (!visit[w])
                    canUse = false;
            }
            if (canUse)
                dfs(g, w, grafoInverso);
        }
        else if (apilado[w]) { // hemos detectado un ciclo
     // se recupera retrocediendo
            hayciclo = true;
        }
    }
    apilado[v] = false;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada

    Digrafo grafo = Digrafo(std::cin, 1);

   if (!std::cin)  // fin de la entrada
      return false;

   ant = std::vector<int>(grafo.V(), 0);
   visit = std::vector<bool>(grafo.V(), false);
   apilado = std::vector<bool>(grafo.V(), false);
   numRecorrido = 0;

   Digrafo grafoInverso = grafo.inverso();

   // resolver el caso posiblemente llamando a otras funciones
   int verticeAComprobar = 0;
   while (!hayciclo && verticeAComprobar < grafo.V()) {
       bool canUse = true;
       for (int w : grafoInverso.ady(verticeAComprobar)) {
           if (!visit[w])
               canUse = false;
       }
       if (!visit[verticeAComprobar] && canUse) {
           dfs(grafo, verticeAComprobar, grafoInverso);
       }
       verticeAComprobar++;
   }

   // escribir la solución

   if (!hayciclo && numRecorrido == grafo.V()) {
       for (int a : ant) {
           std::cout << a + 1 << " ";
       }
       std::cout << "\n";
   }
   else {
       std::cout << "Imposible\n";
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
