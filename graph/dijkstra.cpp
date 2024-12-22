#include <iostream>
#include <cmath>

const int MAXN = 100, INF = 100000000;
int n, dist[MAXN], used[MAXN], graph[MAXN][MAXN];

void relax(int v) {
    for (int i = 0; i < n; ++i)
        dist[i] = std::min(dist[i], dist[v] + graph[v][i]);
}

int get_min_dist() {
    int minv = 0, mind = INF;
    for (int i = 0; i < n; ++i)
        if (mind > dist[i] && !used[i]) {
            mind = dist[i];
            minv = i;
        }

    return minv;
}

int dijkstra(int s, int f) {
    // prepare
    for (int i = 0; i < n; ++i)
        dist[i] = INF;
    dist[s] = 0;
    // dijkstra
    for (int i = 0; i < n; ++i) {
        int v = get_min_dist();
        used[v] = 1;
        relax(v);
    }

    return dist[f];
}
