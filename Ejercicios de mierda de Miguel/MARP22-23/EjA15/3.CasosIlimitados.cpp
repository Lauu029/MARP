
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

struct numIntermedio {
    int num;    //Numero para hacer los calculos
    int dist;   //Distancia desde el origen
    numIntermedio(int numAux, int distAux) : num(numAux), dist(distAux){}
};

bool resuelveCaso() {
   
    int inicio;
   // leer los datos de la entrada
    std::cin >> inicio;
   
   if (!std::cin)  // fin de la entrada
      return false;

   int fin;
   std::cin >> fin;
   
   if (inicio == fin) {
       std::cout << "0\n";
       return true;
   }

   // resolver el caso posiblemente llamando a otras funciones
   std::queue<numIntermedio> queue;
   queue.push(numIntermedio(inicio, 0));
   //Modulo 10000 porque la maquina calculadora tiene 4 digitos, por lo que si se pasa de los 4 digitos vuelve al inicio
   //10000 == 0
   int next1, next2, next3;
   //Hacemos la asignacion en la condicion del while para que lo haga todo solo una vez y optimizar
   while (((next1 = ((queue.front().num + 1) % 10000)) != fin) && ((next2 = ((queue.front().num * 2) % 10000)) != fin) && ((next3 = (queue.front().num / 3)) != fin)) {
       queue.push(numIntermedio(next1, queue.front().dist + 1));
       queue.push(numIntermedio(next2, queue.front().dist + 1));
       queue.push(numIntermedio(next3, queue.front().dist + 1));
       queue.pop();
   }
   
   // escribir la solución
   std::cout << queue.front().dist + 1 << "\n";

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
