
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

struct EventInfo {
    int inicio, fin;
    bool salida;
};

bool operator>(EventInfo const& a, EventInfo const& b) {
    if (a.inicio == b.inicio) {
        return a.fin > b.fin;
    }
    else {
        return a.inicio > b.inicio;
    }
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int numEventos;
    std::cin >> numEventos;

    if (numEventos == 0)
        return false;
   
    std::priority_queue<EventInfo, std::vector<EventInfo>, std::greater<EventInfo>> queue;
    int eventInicio, eventFin;
    for (int i = 0; i < numEventos; ++i) {
        std::cin >> eventInicio >> eventFin;
        queue.push({ eventInicio, eventFin, false });
    }

   // resolver el caso posiblemente llamando a otras funciones
    int currentAlumnos = -1;
    int maxAlumnos = 0;
    EventInfo currentEvent;
    while (!queue.empty()) {
        currentEvent = queue.top(); queue.pop();
        if (currentEvent.salida) {
            currentAlumnos--;
        }
        else {
            currentAlumnos++;
            maxAlumnos = max(currentAlumnos, maxAlumnos);
            //Marcamos el evento como uno de finalizacion
            //Esto solo se utiliza para poder comprobar cuando termina el evento y se libera al estudiante
            currentEvent.inicio = currentEvent.fin;
            currentEvent.salida = true;
            queue.push(currentEvent);
        }
    }
   
   // escribir la solución
    std::cout << maxAlumnos << "\n";

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
