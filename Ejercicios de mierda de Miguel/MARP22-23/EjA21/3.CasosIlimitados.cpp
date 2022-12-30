
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

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
   
   if (!std::cin)  // fin de la entrada
      return false;

   int M;

   std::cin >> M;

   ConjuntosDisjuntos conjunto(N*M);
   std::vector<std::vector<bool>> manchados(N, std::vector<bool>(M));

   std::string elementRead;
   for (int i = 0; i < N; ++i) {
       //std::cin.get(elementRead, M);
       //AAAAAAAAAAAAAAAAA Hay que conseguir que pueda leer una linea entera mis muertos odio programar, nada funciona
       getline(std::cin, elementRead);
       //std::cin.getline(std::cin);
       for (int j = 0; j < M; ++j) {
           if (elementRead[j] == '#') {
               manchados[i][j] = true;
               if (j > 0) {
                   if (manchados[i][j - 1]) {
                       if (!conjunto.unidos(N * i + j, N * (i) + j - 1))
                           conjunto.unir(N * i + j, N * (i) + j - 1);
                   }
                   if (i > 0) {
                       if (manchados[i - 1][j - 1]) {
                           if (!conjunto.unidos(N * i + j, N * (i - 1) + j - 1))
                               conjunto.unir(N * i + j, N * (i - 1) + j - 1);
                       }
                   }
                   if (i < N - 1) {
                       if (manchados[i + 1][j - 1]) {
                           if (!conjunto.unidos(N * i + j, N * (i + 1) + j - 1))
                               conjunto.unir(N * i + j, N * (i + 1) + j - 1);
                       }
                   }
               }
               if (i > 0) {
                   if (manchados[i - 1][j]) {
                       if (!conjunto.unidos(N * i + j, N * (i - 1) + j))
                           conjunto.unir(N * i + j, N * (i - 1) + j);
                   }
                   if (j < N - 1) {
                       if (manchados[i - 1][j + 1]) {
                           if (!conjunto.unidos(N * i + j, N * (i - 1) + j + 1))
                               conjunto.unir(N * i + j, N * (i - 1) + j + 1);
                       }
                   }
               }
           }
       }
   }
   
   int tamanioMayor = 0;
   int contador = 0;
   while (contador < N * M) {
       if (conjunto.cardinal(contador) > tamanioMayor)
           tamanioMayor = conjunto.cardinal(contador);
       contador++;
   }

   cout << tamanioMayor << " ";

   int k;

   std::cin >> k;

   int F, C;
   for (int i = 0; i < k; ++i) {
       std::cin >> F >> C;
       F -= 1;
       C -= 1;
       if (!manchados[F][C]) {
           manchados[F][C] = true;
           if (C > 0) {
               if (manchados[F][C - 1]) {
                   if (!conjunto.unidos(N * F + C, N * F + C - 1))
                       conjunto.unir(N * F + C, N * F + C - 1);
               }
           }
           if (F > 0) {
               if (manchados[F - 1][C]) {
                   if (!conjunto.unidos(N * F + C, N * (F - 1) + C))
                       conjunto.unir(N * F + C, N * (F - 1) + C);
               }
               if (C > 0) {
                   if (manchados[F - 1][C - 1]) {
                       if (!conjunto.unidos(N * F + C, N * (F - 1) + C - 1))
                           conjunto.unir(N * F + C, N * (F - 1) + C - 1);
                   }
               }
               if (C < N - 1) {
                   if (manchados[F - 1][C + 1]) {
                       if (!conjunto.unidos(N * F + C, N * (F - 1) + C + 1))
                           conjunto.unir(N * F + C, N * (F - 1) + C + 1);
                   }
               }
           }
           if (C < N - 1) {
               if (manchados[F][C + 1]) {
                   if (!conjunto.unidos(N * F + C, N * F + C + 1))
                       conjunto.unir(N * F + C, N * F + C + 1);
               }
           }
           if (F < M - 1) {
               if (manchados[F + 1][C]) {
                   if (!conjunto.unidos(N * F + C, N * (F + 1) + C))
                       conjunto.unir(N * F + C, N * (F + 1) + C);
               }
               if (C > 0) {
                   if (manchados[F + 1][C - 1]) {
                       if (!conjunto.unidos(N * F + C, N * (F + 1) + C - 1))
                           conjunto.unir(N * F + C, N * (F + 1) + C - 1);
                   }
               }
               if (C < N - 1) {
                   if (manchados[F + 1][C + 1]) {
                       if (!conjunto.unidos(N * F + C, N * (F + 1) + C + 1))
                           conjunto.unir(N * F + C, N * (F + 1) + C + 1);
                   }
               }
           }
       }

       tamanioMayor = 0;
       contador = 0;
       while (contador < N * M) {
           if (conjunto.cardinal(contador) > tamanioMayor)
               tamanioMayor = conjunto.cardinal(contador);
           contador++;
       }

       cout << tamanioMayor << " ";
   }
   
   cout << "\n";
   

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
