
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <list>
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
    int numCubos;

    std::cin >> numCubos;
   
   if (numCubos == 0)
      return false;
   
   std::list<int> cubos;

   int auxNum;
   for (int i = 0; i < numCubos; ++i) {
       std::cin >> auxNum;
       cubos.push_back(auxNum);
   }

   // resolver el caso posiblemente llamando a otras funciones

   bool nosToca = true;
   int puntuacionTotal = 0;
   while (!cubos.empty()) {
       if (nosToca) {
           // Nuestro razonamiento:
           
           //Pensamos un paso por delante si hay suficientes cubos para hacerlo
           if (cubos.size() > 3) {
               auto it = cubos.begin();
               it++; // Comprobamos el segundo cubo por delante

               auto itEnd = cubos.end();
               itEnd--;
               itEnd--;
               
               //Nos renta mas pillar el de atras
               if (*it + cubos.back() > *itEnd + cubos.front()) {
                   puntuacionTotal += cubos.back();
                   cubos.pop_back();
               }
               //Nos renta mas coger el de alante
               else if (it._Ptr + cubos.back() < itEnd._Ptr + cubos.front()) {
                   puntuacionTotal += cubos.front();
                   cubos.pop_front();
               }
               //Sino son iguales
               else {
                   if (cubos.front() > cubos.back()) {
                       puntuacionTotal += cubos.front();
                       cubos.pop_front();
                   }
                   else {
                       puntuacionTotal += cubos.back();
                       cubos.pop_back();
                   }
               }
           }
           else {
               //Sino pues simplemente cogemos el mas grande
               if (cubos.front() > cubos.back()) {
                   puntuacionTotal += cubos.front();
                   cubos.pop_front();
               }
               else {
                   puntuacionTotal += cubos.back();
                   cubos.pop_back();
               }
           }
       }
       //Devoradora
       else {
           if (cubos.front() > cubos.back()) {
               cubos.pop_front();
           }
           else {
               cubos.pop_back();
           }
       }


       nosToca = !nosToca;
   }
   

   
   // escribir la solución
   std::cout << puntuacionTotal << "\n";

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
