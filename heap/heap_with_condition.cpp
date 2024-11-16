#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int* heap;
int* arr;
int* where;
int heap_size;


void heap_swap(int a, int b) {
    swap(heap[a], heap[b]);
    where[heap[a]] = a;
    where[heap[b]] = b;
}

void siftUp(int v) { // ДЛЯ МИНИМАЛЬНОЙ
    while (v > 0 && arr[heap[v]] < arr[heap[(v - 1) / 2]]) {
        heap_swap(v, (v - 1) / 2);
        v = (v - 1) / 2;
    }
}

void siftDown(int v) { // ДЛЯ МИНИМАЛЬНОЙ
    while (2 * v + 1 < heap_size) {
        int left = 2 * v + 1;
        int right = 2 * v + 2;
        int minCh = left;
        if (right < heap_size && arr[heap[right]] < arr[heap[left]])
            minCh = right;
        if (arr[heap[v]] <= arr[heap[minCh]])
            return;
        heap_swap(v, minCh);
        v = minCh;
    }
}

int extractMin() {
    int t = heap[0];
    heap_swap(0, heap_size - 1);
    --heap_size;
    where[t] = -1;
    siftDown(0);
    return t;
}

void insert(int x) {
    heap[heap_size++] = x;
    where[x] = heap_size - 1;
    siftUp(heap_size - 1);
}

void erase(int x) {
    if (where[x] != -1) {
        arr[x] = pow(-10,9)-1;
        siftUp(where[x]);
        extractMin();
    }
}

int getMin() {
    return arr[heap[0]];
}


int main() {
    int n, k;
    cin >> n >> k;
    heap_size = 0;
    heap = new int[heap_size];
    arr = new int[n];
    where = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
        insert(i);
    int l = 0, r = k;
    while (r <= n) {
        cout << getMin() << endl;
        insert(r);
        erase(l);
        l++; r++;
    }

    delete[] arr;
    delete[] heap;
    delete[] where;

    return 0;
}
