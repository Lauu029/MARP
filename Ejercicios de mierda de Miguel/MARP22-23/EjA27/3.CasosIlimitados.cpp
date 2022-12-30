
/*@ <answer>
 *
 * Nombre y Apellidos: Miguel Hernández García
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Vertice {
    int num;
    int dist;
    std::vector<int> ulti;

    Vertice() {
        dist = -1;
    }

    bool operator<(const Vertice& other) {
        return dist < other.dist;
    }

    
};

bool operator>(const Vertice& a, const Vertice& b) {
    return a.dist > b.dist;
}

void relaja(Arista<int> actual, int fin, int distTotal, std::vector<int> ulti, std::vector<bool>& visit) {

}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   
    GrafoValorado<int> grafo = GrafoValorado<int>(std::cin, 1);

   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   int numConsultas;

   std::cin >> numConsultas;

   int inicio, fin;
   int distTotal = 0;
   std::priority_queue<Vertice, std::vector<Vertice>, std::greater<Vertice>> dist;
   std::vector<int> ulti;
   std::vector<bool> visit(grafo.V());

   std::vector<Vertice> vertices(grafo.V());
   int contadorVertices = 1;
   for (Vertice verticeTemp : vertices) {
       vertices[contadorVertices - 1].num = contadorVertices;
       contadorVertices++;
   }

   std::priority_queue<Vertice, std::vector<Vertice>, std::greater<Vertice>> cola;
   Vertice verticeActual;
   bool llegadoPorCaminoMasCorto = true;

   int actual;
   for (int i = 0; i < numConsultas; ++i) {
       std::cin >> inicio >> fin;
       actual = inicio;
       cola.push(vertices[inicio - 1]);
       verticeActual = vertices[inicio - 1];

       verticeActual.dist = 0;

       while (verticeActual.num != fin && !cola.empty()) {
           //Marcamos el nodo actual como visitado
           
           cola.pop();

           if (!visit[verticeActual.num - 1]) {
               visit[verticeActual.num - 1] = true;


               for (Arista<int> w : grafo.ady(verticeActual.num)) {
                   if (!visit[w.otro(verticeActual.num)]) {
                       if (vertices[w.otro(verticeActual.num) - 1].dist == -1 || vertices[w.otro(verticeActual.num) - 1].dist > vertices[verticeActual.num - 1].dist + w.valor()) {
                           if (w.otro(verticeActual.num) == fin) {
                               llegadoPorCaminoMasCorto = false;
                           }
                           if (vertices[w.otro(verticeActual.num) - 1].dist == -1) {
                               vertices[w.otro(verticeActual.num) - 1].dist = vertices[verticeActual.num - 1].dist + w.valor();
                           }
                           else
                               vertices[w.otro(verticeActual.num) - 1].dist += vertices[verticeActual.num - 1].dist + w.valor();
                           cola.push(vertices[w.otro(verticeActual.num) - 1]);
                       }
                   }
               }
           }
           if (!cola.empty())
            verticeActual = cola.top();
       }

       if (verticeActual.num == fin) {
           std::cout << verticeActual.dist;
           if (llegadoPorCaminoMasCorto) {
               std::cout << " SI\n";
           }
           else {
               std::cout << " NO\n";
           }
       }
       else {
           std::cout << "SIN CAMINO\n";
       }

       //while (!cola.empty()) {
       //    relaja(cola.top(), fin, distTotal, ulti, visit);
       //    cola.pop();
       //}

       /*ulti.push_back(actual);

       while (actual != fin || actual != grafo.V() + 1) {


           
       }*/
   }
   
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

//
///*@ <answer>
// *
// * Nombre y Apellidos:
// *
// *@ </answer> */
//
//#include <iostream>
//#include <fstream>
//#include <climits>
//using namespace std;
//
//#include "GrafoValorado.h" // propios o los de las estructuras de datos de clase
//
///*@ <answer>
//
// Escribe aquí un comentario general sobre la solución, explicando cómo
// se resuelve el problema y cuál es el coste de la solución, en función
// del tamaño del problema.
//
// @ </answer> */
//
//
// // ================================================================
// // Escribe el código completo de tu solución aquí debajo
// // ================================================================
// //@ <answer>
//
//class RecorreGrafo {
//public:
//    RecorreGrafo(GrafoValorado<int> const& G, int v, int destino) : caminoCorto(true), distancia(0), distanciaFinal(INT_MAX), visit(G.V(), false), numIntersecciones(0), numMinIntersecciones(INT_MAX) {
//
//        dfs(G, v, destino);
//    }
//
//    bool esCorto() { return caminoCorto; }
//
//    int recorrido() { return distanciaFinal; }
//
//private:
//    vector<bool> visit;
//    int distancia;
//    int distanciaFinal;
//    bool caminoCorto;
//    int numIntersecciones;
//    int numMinIntersecciones;
//
//
//    // visita los nodos alcanzables desde v respetando el umbral
//    void dfs(GrafoValorado<int> const& G, int v, int destino) {
//
//        visit[v] = true;
//
//        for (auto a : G.ady(v)) {
//
//            //Si he llegado al final
//            if (a.otro(v) != destino) {
//
//                int w = a.otro(v);
//                if (!visit[w]) {
//                    distancia += a.valor();
//
//                    numIntersecciones++;
//
//                    dfs(G, w, destino);
//
//                    //Una vez hago mi recorrido lo borro
//                    visit[w] = false;
//                    distancia -= a.valor();
//                    numIntersecciones--;
//                }
//            }
//            //Si he encontrado el ultimo vertice...
//            else {
//                //Le sumo la distancia
//                distancia += a.valor();
//                numIntersecciones++;
//
//                if (distancia < distanciaFinal) {
//
//                    if (numIntersecciones < numMinIntersecciones) {
//                        caminoCorto = true;
//                        numMinIntersecciones = numIntersecciones;
//                    }
//                    else
//                        caminoCorto = false;
//
//                    distanciaFinal = distancia;
//                }
//
//                //Y se la resto una vez esta guardada
//                distancia -= a.valor();
//                numIntersecciones--;
//                break;
//            }
//        }
//
//    }
//};
//
//bool resuelveCaso() {
//
//    // leer los datos de la entrada
//    int numIntersecciones, numCalles;
//
//    cin >> numIntersecciones >> numCalles;
//
//    if (!std::cin)  // fin de la entrada
//        return false;
//
//    GrafoValorado<int> g(numIntersecciones);
//
//    int desde, hasta, valor;
//
//    for (int i = 0; i < numCalles; i++) {
//        cin >> desde >> hasta >> valor;
//        Arista<int> aux(desde - 1, hasta - 1, valor);
//
//        g.ponArista(aux);
//    }
//
//    int numConsultas;
//
//    cin >> numConsultas;
//
//    int origen, destino;
//
//    for (int i = 0; i < numConsultas; i++) {
//        cin >> origen >> destino;
//
//        // resolver el caso posiblemente llamando a otras funciones
//        RecorreGrafo sol(g, origen - 1, destino - 1);
//
//        // escribir la solución
//
//        //Si no ha llegado si quiera a modificar el valor...
//        if (sol.recorrido() == INT_MAX)
//            //Es porque no ha llegado a tocarle
//            cout << "SIN CAMINO\n";
//        //Si ha llegado a tocar el vertice...
//        else {
//            //Escribimos la distancia
//            cout << sol.recorrido();
//
//            if (sol.esCorto())
//                cout << " SI\n";
//            else
//                cout << " NO\n";
//        }
//    }
//
//    cout << "---\n";
//
//    return true;
//}
//
////@ </answer>
////  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
//
//int main() {
//    // ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    std::ifstream in("casos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf());
//#endif
//
//    while (resuelveCaso());
//
//    // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif
//    return 0;
//}