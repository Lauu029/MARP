#pragma once
#include "Grafo.h"
#include <vector>

using namespace std;
class mayorNumConexiones {
protected:
	vector<bool> visitado;
	int orig;
	int maximo;
	int dfs(Grafo const& gr, int vertice) {
		int tam = 1;
		visitado[vertice] = true;
		for (auto v: gr.ady(vertice))
		{
			if (!visitado[v]) {
				tam += dfs(gr, v);
			}
		}
		return tam;
	}
public:
	mayorNumConexiones(Grafo const& gr): visitado(gr.V(),false), maximo(0) {
		for (int i = 0; i < gr.V(); i++)
		{
			if (!visitado[i]);
			int numAmigos = dfs(gr, i);
			maximo = max(maximo, numAmigos);
		}
	}

	int mayorGrupo() const {
		return maximo;
	}
};