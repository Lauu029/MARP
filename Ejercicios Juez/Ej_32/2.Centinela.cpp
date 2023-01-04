
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class hora {
protected:
	int hor;
	int min;

public:
	friend std::istream& operator>>(std::istream& i, hora& h) {
		char c = ':';
		i >> h.hor >> c >> h.min;
		return i;
	}
	friend std::ostream& operator<<(std::ostream& o, const hora& h) {
		if (h.hor < 10) o << "0";
		o << h.hor << ":";
		if (h.min < 10)o << "0";
		o << h.min << " ";
		return o;
	}
	hora operator+(int duracion) {
		hora h;
		h.min = min;
		h.hor = hor;
		h.min += duracion;
		while (h.min > 59) {
			h.min -= 60;
			h.hor += 1;
		}
		return h;
	}
	int getMin() const { return min; }
	int getHora() const { return hor; }

};
bool operator<(const hora& h1, const hora& h2) {
	if (h1.getHora() >= h2.getHora()) return false;
	if (h1.getHora() == h2.getHora()) return h1.getMin() < h2.getMin();
	return true;
}
bool operator>(const hora& h1, const hora& h2) {
	if (h1.getHora() < h2.getHora()) return false;
	if (h1.getHora() == h2.getHora()) return h1.getMin() > h2.getMin();
	return true;
}
struct infoPeli {
	hora ini;
	int dur;
	hora fin;
};
bool operator<(const infoPeli& inf, const infoPeli& inf2) {
	return inf.ini < inf2.ini;
}
int numPelisVistas(deque<infoPeli>& horasPelis) {
	int pelis = 0;
	while (!horasPelis.empty()) {
		infoPeli p = horasPelis.front(); horasPelis.pop_front();
		pelis++;//mira la peli
		if (!horasPelis.empty()) {
			if (p.fin > horasPelis.front().ini)
				horasPelis.pop_front();//descarta la siguiente película si no puede verla
		}
	}
	return pelis;
}
bool resuelveCaso() {

	// leer los datos de la entrada
	int numPelis;
	cin >> numPelis;

	if (!numPelis)
		return false;
	deque<infoPeli> horasPelis(numPelis);
	for (int i = 0; i < numPelis; i++)
	{
		cin >> horasPelis[i].ini >> horasPelis[i].dur;
		horasPelis[i].fin = horasPelis[i].ini + (horasPelis[i].dur + 10);
	}
	sort(horasPelis.begin(), horasPelis.end(), less<infoPeli>());

	cout << numPelisVistas(horasPelis) << "\n";
	// resolver el caso posiblemente llamando a otras funciones

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
