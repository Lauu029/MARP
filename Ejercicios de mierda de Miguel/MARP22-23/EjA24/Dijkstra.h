#pragma once

#include "IndexPQ.h"
#include <queue>
#include <climits>
#include "DigrafoValorado.h"


using Camino = std::deque<AristaDirigida<int>>;
class CaminosMinimos {
public:
	CaminosMinimos(DigrafoValorado<int> const& g, int origen);
	int distancia(int v) const;
	Camino camino(int v) const;
};


class Dijkstra {
public:
	Dijkstra(DigrafoValorado<int> const& g, int orig) : origen(orig),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	bool hayCamino(int v) const { return dist[v] != INF; }
	int distancia(int v) const { return dist[v]; }
	Camino camino(int v) const {
		Camino cam;
		// recuperamos el camino retrocediendo
		AristaDirigida<int> a;
		for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
			cam.push_front(a);
		cam.push_front(a);
		return cam;
	}

private:
	const int INF = INT_MAX;
	int origen;
	std::vector<int> dist;
	std::vector<AristaDirigida<int>> ulti;
	IndexPQ<int> pq;
	void relajar(AristaDirigida<int> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor(); ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}
};