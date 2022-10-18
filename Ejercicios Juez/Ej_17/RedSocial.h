#include "Grafo.h"
#include <vector>

using namespace std;

class redSocial {
protected:
	vector<bool> visitados;
	vector<int> nAmigosGrupo;
	vector<int> grupo;

	int dfs(Grafo const& gr, int vertice, int nGrupo) {
		visitados[vertice] = true;
		grupo[vertice] = nGrupo;
		int tamGrupo = 1;
		for (int a : gr.ady(vertice))
		{
			if (!visitados[a]) {
				tamGrupo += dfs(gr, a, nGrupo);
			}
		}
		return tamGrupo;
	}
public:
	redSocial(Grafo const& gr) : visitados(gr.V(), false) , grupo(gr.V(),-1), nAmigosGrupo(gr.V(),-1) {
		int nGrupo = 0;
		for (int i = 0; i < gr.V(); i++)
		{
			if (!visitados[i]) {
				nAmigosGrupo[nGrupo] = dfs(gr, i, nGrupo);
				nGrupo++;
			}
		}
	}

	int getAmigos(int persona) {
		return nAmigosGrupo[grupo[persona]];
	}
};
