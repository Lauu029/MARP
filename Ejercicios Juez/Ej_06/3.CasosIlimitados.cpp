
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct periodico {
    int ini;
    int fin;
    int periodo;
};
bool resuelveCaso() {
   
   // leer los datos de la entrada
   
   if (!std::cin)  // fin de la entrada
      return false;
   int N, M, T;
   cin >> N >> M >> T;
   periodico agenda;
   PriorityQueue <periodico> tareas;
   for (int i = 0; i < N; i++)
   {
       cin >> agenda.ini >> agenda.fin;
       agenda.periodo = 0;
       tareas.push(agenda);
   }
   for (size_t i = 0; i < M; i++)
   {
       cin >> agenda.ini >> agenda.fin >> agenda.periodo;
       tareas.push(agenda);
   }
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
