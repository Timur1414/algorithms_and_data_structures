#include <algorithm>
#include <iostream>


int* heap = new int[10];
int SIZE = 10;

void siftUp(int v) { // ДЛЯ МАКСИМАЛЬНОЙ
    while (v > 0 && heap[v] > heap[(v - 1) / 2]) {
        std::swap(heap[v], heap[(v - 1) / 2]);
        v = (v - 1) / 2;
    }
}

void siftDown(int v) { // ДЛЯ МАКСИМАЛЬНОЙ
    while (2 * v + 1 < SIZE) {
        int left = 2 * v + 1;
        int right = 2 * v + 2;
        int maxCh = left;
        if (right < SIZE && heap[right] > heap[left])
            maxCh = right;
        if (heap[maxCh] <= heap[v])
            return;
        std::swap(heap[maxCh], heap[v]);
        v = maxCh;
    }
}

void insert(int x) {
    heap[SIZE++] = x;
    siftUp(SIZE - 1);
}

int getMin() {
    return heap[0];
}

int extractMin() {
    int t = heap[0];
    heap[0] = heap[--SIZE];
    siftDown(0);
    return t;
}

int main() {
    int k;
    std::cin >> k;


    return 0;
}