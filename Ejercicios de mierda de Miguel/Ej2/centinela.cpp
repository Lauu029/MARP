
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

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
   
   int nArbol;

   // leer los datos de la entrada

   std::cin>>nArbol;
   
   if (nArbol == 0)
      return false;
   
   Set<long int> tree;

   long int auxInt;
   for (int i = nArbol; i > 0; --i){
      std::cin >> auxInt;
      tree.insert(auxInt);
   }

   // resolver el caso posiblemente llamando a otras funciones

   int numConsultas;

   std::cin >> numConsultas;

   long int kEsimo;
   for (int i = numConsultas; i > 0; --i){
      std::cin >> auxInt;
      try{
         kEsimo = tree.kesimo(auxInt);
         std::cout << kEsimo << "\n";
      }
      catch(const std::invalid_argument& e){
         std::cout<<"??\n";
      }
   }

   std::cout<<"---\n";

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
