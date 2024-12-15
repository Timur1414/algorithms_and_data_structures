#include <iostream>

using namespace std;

int graph[100][100]; // матрица смежности
int n; // количество вершин
bool visited[100]; // изначально все false

void dfs (int v) { // обход в глубину
    visited[v] = true;
    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs(i);
}

int main() {


    return 0;
}
