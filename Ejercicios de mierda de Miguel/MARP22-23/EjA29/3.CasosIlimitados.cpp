
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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
    int numAgujeros;

    std::cin >> numAgujeros;
   
   if (!std::cin)  // fin de la entrada
      return false;

   int longitudParche;

   std::cin >> longitudParche;

   std::queue<int> queue;

   int auxInt;
   for (int i = 0; i < numAgujeros; ++i) {
       std::cin >> auxInt;
       queue.push(auxInt);
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int lastPositionParche = -1;
   int currentAgujero;
   int numParchesNecesarios = 0;
   while (!queue.empty()) {
       currentAgujero = queue.front();
       if (lastPositionParche != -1 && lastPositionParche + longitudParche >= currentAgujero) {
           queue.pop();
       }else{
           lastPositionParche = currentAgujero;
           numParchesNecesarios++;
           queue.pop();
       }
   }
   
   // escribir la solución
   std::cout << numParchesNecesarios << "\n";

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
