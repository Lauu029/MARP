
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase
#include "Matriz.h"

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Tesoro {
    int coste, valor;
};

double mochila_rec(vector<Tesoro> const& obj, int i, int j,
    Matriz<double>& mochila) {
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    if (i == 0 || j == 0) mochila[i][j] = 0;
    else if (obj[i - 1].coste > j)
        mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
    else
        mochila[i][j] = max(mochila_rec(obj, i - 1, j, mochila),
            mochila_rec(obj, i - 1, j - obj[i - 1].coste, mochila)
            + obj[i - 1].valor);
    return mochila[i][j];
}

double mochila(vector<Tesoro> const& objetos, int M, vector<bool>& sol, int& numTesorosRecuperados) {
    int n = objetos.size();
    Matriz<double> mochila(n + 1, M + 1, -1);
    double valor = mochila_rec(objetos, n, M, mochila);
    // cálculo de los objetos
    int i = n, j = M;
    sol = vector<bool>(n, false);
    while (i > 0 && j > 0) {
        if (mochila[i][j] != mochila[i - 1][j]) {
            sol[i - 1] = true; numTesorosRecuperados++; j = j - objetos[i - 1].coste;
        }
        --i;
    }
    return valor;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int segundosBotella;

    std::cin >> segundosBotella;
   
   if (!std::cin)  // fin de la entrada
      return false;

   int numTesoros;

   std::cin >> numTesoros;

   std::vector<Tesoro> tesoros;

   int auxCoste, auxValor;
   for (int i = 0; i < numTesoros; ++i) {
       std::cin >> auxCoste >> auxValor;
       Tesoro tesoroAux;
       tesoroAux.coste = auxCoste + auxCoste * 2;
       tesoroAux.valor = auxValor;
       tesoros.push_back(tesoroAux);
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   Matriz<int> matriz;
   std::vector<bool> sol;
   int numTesorosRecuperados = 0;
   std::cout<<mochila(tesoros, segundosBotella, sol, numTesorosRecuperados)<<"\n";
   
   // escribir la solución
   std::cout << numTesorosRecuperados << "\n";
   for (int i = 0; i < sol.size(); ++i) {
       if (sol[i])
           std::cout << tesoros[i].coste / 3 << " " << tesoros[i].valor << "\n";
   }
   std::cout << "---\n";

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
