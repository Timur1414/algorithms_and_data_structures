#include <iostream>
using namespace std;

int graph[100][100];
int color[100];
int g_size;

int sorted_graph[100][100];

int stack[100];
int s_size;

void push(int x) {
    stack[s_size++] = x;
}

int pop() {
    return stack[--s_size];
}

int top() {
    return stack[s_size - 1];
}

void dfs(int v) {
    if (color[v] != 0)
      return;
    color[v] = 1;
    for (int i=0; i < g_size; i++)
        if (graph[v][i] == 1)
            dfs(i);
    color[v] = 2;
    push(v);
}

int main() {
    g_size = 4;
    for (int i = 0; i < g_size; i++)
        for (int j = 0; j < g_size; j++)
            graph[i][j] = 0;

    graph[0][1] = 1;
    graph[2][0] = 1;
    graph[0][3] = 1;
    graph[3][1] = 1;

    for (int i = 0; i < g_size; i++) {
        if (color[i] == 0)
            dfs(i);
    }

    // топологическая сортировка
    int arr[100] = {};
    for (int i = 0; i < g_size; i++) {
        arr[pop()] = i;
    }
    cout << endl;
    // перенумерование вершин
    for (int i = 0; i < g_size; i++)
        for (int j = 0; j < g_size; j++)
            if (graph[i][j] == 1)
                sorted_graph[arr[i]][arr[j]] = 1;

    for (int i = 0; i < g_size; i++) {
        for (int j = 0; j < g_size; j++) {
            cout << sorted_graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
