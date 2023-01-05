
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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
    int tamTablero;

    std::cin >> tamTablero;
   
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   std::vector<int> previousRow(tamTablero, 0);
   std::vector<int> currentRow(tamTablero);

   int elementoNuevo;
   //Filas
   for (int i = 0; i < tamTablero; ++i) {
       //Columnas de cada fila
       for (int j = 0; j < tamTablero; ++j) {
           std::cin >> elementoNuevo;
           //Le asignamos de momento la posicion de justo arriba porque tiene que tener si o si
           currentRow[j] = currentRow[j] + elementoNuevo;

           //Si hay elementos por la izquierda comprobamos el de arriba a la izquierda
           if (j > 0) {
               currentRow[j] = max(currentRow[j], previousRow[j - 1] + elementoNuevo);
           }

           //Si hay elementos por la derecha comprobamos el de arriba a la derecha
           if (j < tamTablero - 1) {
               currentRow[j] = max(currentRow[j], previousRow[j + 1] + elementoNuevo);
           }
       }
       previousRow = currentRow;
   }

   //Comprobamos el elemento mas grande y su posicion
   int posicionElementoMayor = 0;
   int elementoMayor = 0;
   for (int i = 0; i < tamTablero; ++i) {
       if (currentRow[i] > elementoMayor) {
           posicionElementoMayor = i + 1;
           elementoMayor = currentRow[i];
       }
   }
   
   // escribir la solución
   std::cout << elementoMayor << " " << posicionElementoMayor << "\n";

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
