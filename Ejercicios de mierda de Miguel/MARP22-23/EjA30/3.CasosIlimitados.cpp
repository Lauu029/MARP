
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
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
    int numCiudades;

    std::cin >> numCiudades;
   
   if (!std::cin)  // fin de la entrada
      return false;

   //Colas de prioridad para ordenar los enemigos de menor a mayor y los aliados de mayor a menor
   std::priority_queue<int, std::vector<int>, std::less<int>> enemigos;
   std::priority_queue<int, std::vector<int>, std::less<int>> aliados;

   int auxInt;
   //Leemos todos los enemigos que hay en cada una de las ciudades
   for (int i = 0; i < numCiudades; ++i) {
       std::cin >> auxInt;
       enemigos.push(auxInt);
   }
   //Leemos los aliados que tenemos disponibles
   for (int i = 0; i < numCiudades; ++i) {
       std::cin >> auxInt;
       aliados.push(auxInt);
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int numVictorias = 0;
   while (!enemigos.empty()) {
       //Si se puede ganar gastamos una tropa para lidiar con la armada de esa ciudad, sino nos guardamos las fuerzas
       if (enemigos.top() <= aliados.top()) {
           aliados.pop();
           numVictorias++;
       }
       enemigos.pop();
   }
   
   // escribir la solución
   std::cout << numVictorias << "\n";

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
