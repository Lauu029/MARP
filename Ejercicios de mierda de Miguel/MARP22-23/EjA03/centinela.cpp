
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include <queue>  // propios o los de las estructuras de datos de clase

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
   
   int nNumeros;

   // leer los datos de la entrada

   std::cin>>nNumeros;
   
   if (nNumeros == 0)
      return false;
   
   if (nNumeros == 1) {
       //Descartamos el numero
       std::cin >> nNumeros;
       std::cout << "0\n";
   }
   else {
       std::priority_queue<long int, std::vector<long int>, std::greater<long int>> queue;
       long int auxInt;
       for (int i = 0; i < nNumeros; ++i) {
           std::cin >> auxInt;
           queue.push(auxInt);
       }

       long int sumatorio;
       long int costeTotal = 0;
       while (queue.size() > 1) {
           //Sumamos el costo de los dos elementos y lo volvemos a guardar en la cola
           sumatorio = 0;
           sumatorio += queue.top();
           queue.pop();
           sumatorio += queue.top();
           queue.pop();
           costeTotal += sumatorio;
           queue.push(sumatorio);
       }

       //Cuando llegue aqui solo habrá un elemento en la cola, el cual sera el costo total
       std::cout << costeTotal << "\n";
   }

   // resolver el caso posiblemente llamando a otras funciones

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
