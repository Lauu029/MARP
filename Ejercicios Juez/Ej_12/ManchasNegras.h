#pragma once
#include "Grafo.h"
#include <vector>

using namespace std;
class manchasNegras {
protected:
	int F, C;
	vector<vector<bool>> visitado;
	int maximo;
	int numManchas;
	const vector < pair <  int, int> > posiciones = { {1,0},{0,1},{-1,0},{0,-1} };

	bool esCorrecta(int i, int j) {
		return i >= 0 && i < F&& j >= 0 && j < C;
	}

	int dfs(vector<string> const& mapa, int i, int j) {
		visitado[i][j] = true;
		int tam = 1;
		for (auto v : posiciones)
		{
			int ni = i + v.first, nj = j + v.second;
			if (esCorrecta(ni, nj) && mapa[ni][nj] == '#' && !visitado[ni][nj])
				tam += dfs(mapa, ni, nj);

		}
		return tam;
	}
public:
	manchasNegras(vector<string> const& mapa) : visitado(F, vector<bool>(C, false)), maximo(0), numManchas(0), F(mapa.size()), C(mapa[0].size()) {
		for (int i = 0; i < F; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if(!visitado[i][j] && mapa[i][j] == '#') {
					++numManchas;
					int tamMancha = dfs(mapa, i, j);
					maximo = max(maximo, tamMancha);
				}
			}
		}
	}

	int mayorGrupo() const {
		return maximo;
	}
	int numGrupos() const {
		return numManchas;
	}
};