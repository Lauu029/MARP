
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
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

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N;

    std::cin >> N;

    if (N == 0)
        return false;

   if (!std::cin)  // fin de la entrada
      return false;

   DigrafoValorado<int> grafo = DigrafoValorado<int>(N);

   std::vector<int> cargaPagina;

   int cargaTemp;
   for (int i = 0; i < N; ++i) {
       std::cin >> cargaTemp;
       cargaPagina.push_back(cargaTemp);
   }

   int numConexiones;

   std::cin >> numConexiones;

   int paginaInicio, paginaFin, tiempoCarga;
   for (int i = 0; i < numConexiones; ++i) {
       std::cin >> paginaInicio >> paginaFin >> tiempoCarga;

       grafo.ponArista(AristaDirigida<int>(paginaInicio - 1, paginaFin - 1, tiempoCarga + cargaPagina[paginaFin - 1]));
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   Dijkstra cosaPocha = Dijkstra(grafo, 0);
   bool hayCamino = cosaPocha.hayCamino(N - 1);

   if (hayCamino) {
       int distancia = cosaPocha.distancia(N - 1) + cargaPagina[0];

       std::cout << distancia << "\n";
   }
   else
       std::cout << "IMPOSIBLE" << "\n";

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
