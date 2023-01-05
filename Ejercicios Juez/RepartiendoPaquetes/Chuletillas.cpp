//template <typename Valor>
//class Dijkstra {
//public:
//	Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
//		dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
//		dist[origen] = 0;
//		pq.push(origen, 0);
//		while (!pq.empty()) {
//			int v = pq.top().elem; pq.pop();
//			for (auto a : g.ady(v))
//				relajar(a);
//		}
//	}
//	bool hayCamino(int v) const { return dist[v] != INF; }
//	Valor distancia(int v) const { return dist[v]; }
//	Camino<Valor> camino(int v) const {
//		Camino<Valor> cam;
//		// recuperamos el camino retrocediendo
//		AristaDirigida<Valor> a;
//		for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
//			cam.push_front(a);
//		cam.push_front(a);
//		return cam;
//	}
//private:
//	const Valor INF = std::numeric_limits<Valor>::max();
//	int origen;
//	std::vector<Valor> dist;
//	std::vector<AristaDirigida<Valor>> ulti;
//	IndexPQ<Valor> pq;
//	void relajar(AristaDirigida<Valor> a) {
//		int v = a.desde(), w = a.hasta();
//		if (dist[w] > dist[v] + a.valor()) {
//			dist[w] = dist[v] + a.valor(); ulti[w] = a;
//			pq.update(w, dist[w]);
//		}
//	}
//};
//---------------------------------------------------------------------
//template <typename Valor>
//class ARM_Kruskal {
//private:
//	std::vector<Arista<Valor>> _ARM;
//	Valor coste;
//public:
//	Valor costeARM() const {
//		return coste;
//	}
//	std::vector<Arista<Valor>> const& ARM() const {
//		return _ARM;
//	}
//	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0) {
//		PriorityQueue<Arista<Valor>> pq(g.aristas());
//		ConjuntosDisjuntos cjtos(g.V());
//		while (!pq.empty()) {
//			auto a = pq.top(); pq.pop();
//			int v = a.uno(), w = a.otro(v);
//			if (!cjtos.unidos(v, w)) {
//				cjtos.unir(v, w);
//				_ARM.push_back(a); coste += a.valor();
//				if (_ARM.size() == g.V() - 1) break;
//			}
//		}
//	}
//};
//------------------------------------------------------------------
//class CaminosDFS {
//private:
//	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
//	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
//	int s; // vértice origen
//	void dfs(Grafo const& G, int v) {
//		visit[v] = true;
//		for (int w : G.ady(v)) {
//			if (!visit[w]) {
//				ant[w] = v;
//				dfs(G, w);
//			}
//		}
//	}
//public:
//	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
//		ant(g.V()), s(s) {
//		dfs(g, s);
//	}
//	// ¿hay camino del origen a v?
//	bool hayCamino(int v) const {
//		return visit[v];
//	}
//	using Camino = std::deque<int>; // para representar caminos
//	// devuelve un camino desde el origen a v (debe existir)
//	Camino camino(int v) const {
//		if (!hayCamino(v))
//			throw std::domain_error("No existe camino");
//		Camino cam;
//		// recuperamos el camino retrocediendo
//		for (int x = v; x != s; x = ant[x])
//			cam.push_front(x);
//		cam.push_front(s);
//		return cam;
//	}
//};
//-------------------------------------------------------------------
//using Mapa = vector<string>; // grafo implícito en el mapa
//class Manchas {
//public:
//	Manchas(Mapa const& M) : F(M.size()), C(M[0].size()),
//		visit(F, vector<bool>(C, false)), num(0), maxim(0) {
//		for (int i = 0; i < F; ++i) {
//			for (int j = 0; j < C; ++j) {
//				if (!visit[i][j] && M[i][j] == '#') { // se recorre una nueva mancha
//					++num;
//					int nuevotam = dfs(M, i, j);
//					maxim = max(maxim, nuevotam);
//				}
//			}
//		}
//	}
//	int numero() const { return num; }
//	int maximo() const { return maxim; }
//private:
//	int F, C; // tamaño del mapa
//	vector<vector<bool>> visit; // visit[i][j] = se ha visitado el píxel <i,j>?
//	int num; // número de manchas
//	int maxim; // tamaño de la mancha más grande
//	bool correcta(int i, int j) const {
//		return 0 <= i && i < F && 0 <= j && j < C;
//	}
//	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };
//	int dfs(Mapa const& M, int i, int j) {
//		visit[i][j] = true;
//		int tam = 1;
//		for (auto d : dirs) {
//			int ni = i + d.first, nj = j + d.second;
//			if (correcta(ni, nj) && M[ni][nj] == '#' && !visit[ni][nj]) {
//				tam += dfs(M, ni, nj);
//			}
//		}
//		return tam;
//	}
//};