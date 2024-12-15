int l = 0, r = 0, queue[10000];

void push(int x) {
    queue[r++] = x;
}
int top() {
    return queue[l];
}
int pop() {
    return queue[l++];
}
int size() {
    return r - l;
}

int graph[100][100];
int n;
int dist[100];
int visited[100];

void bfs(int v) {
    push(v);
    visited[v] = true;
    dist[v] = 0;

    while(size() > 0) {
        int x = pop();
        for(int i = 0; i < n; ++i) {
            if (graph[x][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = true;
                dist[i] = dist[x] + 1;
            }
        }
    }
}