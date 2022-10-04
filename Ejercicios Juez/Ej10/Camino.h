#pragma once
#include "Grafo.h"
#include <vector>

using namespace std;
class CaminoDFS {
private:
	vector<bool> visitado;
	vector<int> anterior;
	int origen;
	bool libre;
public:

	/*
	* devuelve si hay camino del origen a un vertice
	*/
	bool hayCamino(int v) {
		return visitado[v];
	}

	bool esArbolLibre(Grafo const& gr) {
		//primero comprueba si el arbol tenia solo un camino para cada par de vertices
		if (!libre) return false;
		//Caso en el que el árbol no es conexo
		for (auto v : visitado) {
			if (!v) return false;
		}
		return true;
	}
private:
	bool dfs(Grafo const& gr, int vertice) {
		visitado[vertice] = true;
		for (auto v : gr.ady(vertice))
		{
			if (!visitado[v]) {
				anterior[v] = vertice;
				dfs(gr, v);
			}
			//Comprueba que solo haya un camino
			else {
				if (anterior[vertice] != v) return false;
			}
		}
		return true;
	}
public:
	CaminoDFS(Grafo const& gr, int o) : visitado(gr.V(), false), anterior(gr.V()), origen(o) {
		libre = dfs(gr, o);
	};
};