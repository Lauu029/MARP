
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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
	int min;
	int hor;

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
	bool operator<(const hora& h) {
		if (hor >= h.hor) return false;
		if (hor == h.hor && min >= h.min) return false;
		return true;		
	}

};
struct infoPeli {
	hora ini;
	int dur;
	hora fin;
};
bool operator<(const infoPeli& inf, const infoPeli& inf2) {
	return inf.ini < inf2.ini;
}
bool resuelveCaso() {

	// leer los datos de la entrada
	int numPelis;
	cin >> numPelis;

	if (!numPelis)
		return false;
	vector<infoPeli> horasPelis(numPelis);
	for (int i = 0; i < numPelis; i++)
	{
		cin >> horasPelis[i].ini >> horasPelis[i].dur;
		horasPelis[i].fin = horasPelis[i].ini + (horasPelis[i].dur+10);
	}
	for (int i = 0; i < numPelis; i++)
	{
		cout << horasPelis[i].ini << horasPelis[i].dur<<" " <<horasPelis[i].fin << "\n";
	}
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
