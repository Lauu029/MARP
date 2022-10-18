/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Laura Gómez Bodego MARP19
  * Estudiante 2: Miguel Hernandez García MARP22
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Digrafo.h"
using namespace std;



/*@ <answer>

Creamos un grafo dirigido en el que cada vértice es una instrucción.
Para la lectura del grafo distinguimos los tres casos posibles de instrucciones, si es A, se une un nodo con el 
siguiente, si es J se une con el destino del salto y si es C se une con el siguiente y con el destino del salto.
Hemos añadido la clase necronomicon que hace un recorrido en profundidad del arbol. Guardamos los nodos visitados
y los apilados en vectores de booleanos, al analizar un nodo, comprueba si es el último, si es así ha llegado al final
y si no es así continúa. Al comprobar los adyacentes comprueba si alguno de ellos ya estaba apilado, si es así,
hay un ciclo. si hay un ciclo y ha terminado el programa se acaba el recorrido en profundidad.

Coste: O(V+A) porque en el caso peor recorre todo el grafo en profundidad.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
class necronomicon {
protected:
	vector <bool> visitado;
	vector <bool> apilado;
	bool ciclo, final;
	void dfs(Digrafo const& d, int v) {
		visitado[v] = true;
		apilado[v] = true;
		if (v == d.V() - 1) final = true;
		for (int a : d.ady(v))
		{
			if (ciclo&&final) break;
			if (!visitado[a]) dfs(d, a);
			else if(apilado[a]) ciclo = true;
		}
		apilado[v] = false;
	}

public:
	necronomicon(Digrafo const& dig, int s) :visitado(dig.V(), false), apilado(dig.V(),false),
		ciclo(false), final(false) {
		
		dfs(dig, s);
	}

	bool getCiclo() {
		return ciclo;
	}
	bool getFinal() {
		return final;
	}
};

bool resuelveCaso() {

	int L;
	cin >> L;
	if (!cin) return false;

	Digrafo programa(L + 1);

	char entrada;
	int salto;
	for (int i = 0; i < L; i++)
	{
		cin >> entrada;
		switch (entrada)
		{
		case'A':
			programa.ponArista(i, i + 1);
			break;
		case 'J':
			cin >> salto;
			programa.ponArista(i, salto - 1);
			break;
		case 'C':
			cin >> salto;
			programa.ponArista(i, salto - 1);
			programa.ponArista(i, i + 1);
			break;
		default:
			break;
		}
	}
	necronomicon n(programa, 0);

	if (n.getCiclo() && n.getFinal()) cout << "A VECES\n";
	else if (n.getCiclo()) cout << "NUNCA\n";
	else cout << "SIEMPRE\n";

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


	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
