
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
   
    int numJugadores;

    std::cin >> numJugadores;

    if (!std::cin)  // fin de la entrada
        return false;

    int numEquipaciones;

    std::cin >> numEquipaciones;

    //Colas de prioridad para ordenar los jugadores de menor a mayor y los equipaciones de mayor a menor
    std::priority_queue<int, std::vector<int>, std::greater<int>> jugadores;
    std::priority_queue<int, std::vector<int>, std::greater<int>> equipaciones;

    int auxInt;
    //Leemos todos los jugadores que hay
    for (int i = 0; i < numJugadores; ++i) {
        std::cin >> auxInt;
        jugadores.push(auxInt);
    }
    //Leemos los equipaciones que tenemos disponibles
    for (int i = 0; i < numEquipaciones; ++i) {
        std::cin >> auxInt;
        equipaciones.push(auxInt);
    }

    // resolver el caso posiblemente llamando a otras funciones
    int numEquipacionesAComprar = 0;
    while (!jugadores.empty() && !equipaciones.empty()) {
        //Si el jugador se puede equipar la equipacion entonces todo bien
        if (jugadores.top() == equipaciones.top() || jugadores.top() + 1 == equipaciones.top()) {
            equipaciones.pop();
            jugadores.pop();
        }
        //Si no hay nada lo suficientemente pequeño para ese jugador se pasa de el
        else if (equipaciones.top() > jugadores.top()) {
            jugadores.pop();
            numEquipacionesAComprar++;
        }
        //Si ya nadie puede usar este equipamiento porque es muy pequeño se descarta
        else {
            equipaciones.pop();
        }
    }

    //Si aun quedan jugadores por equipar hay que contar tambien con ellos
    numEquipacionesAComprar += jugadores.size();

    // escribir la solución
    std::cout << numEquipacionesAComprar << "\n";

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
