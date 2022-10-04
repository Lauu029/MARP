
/*@ <answer>
 *
 * Nombre y Apellidos: Laura Gómez Bodego MARP19
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "Camino.h"
using namespace std;

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
    int V, A;
    cin >> V >> A;
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   Grafo arbol(V);
   int a1, a2;
   for (int i = 0; i < A; i++)
   {
       cin >> a1 >> a2;
       arbol.ponArista(a1, a2);
   }
   CaminoDFS recorridos(arbol, 0);

   if (recorridos.esArbolLibre(arbol)) cout << "SI\n";
   else cout << "NO\n";
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
