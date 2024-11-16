#include <algorithm>
#include <iostream>

using namespace std;

int* heap;
int heap_size;

void siftUp(int v) { // ДЛЯ МАКСИМАЛЬНОЙ
    while (v > 0 && heap[v] > heap[(v - 1) / 2]) {
        std::swap(heap[v], heap[(v - 1) / 2]);
        v = (v - 1) / 2;
    }
}

void siftDown(int v) { // ДЛЯ МАКСИМАЛЬНОЙ
    while (2 * v + 1 < heap_size) {
        int left = 2 * v + 1;
        int right = 2 * v + 2;
        int maxCh = left;
        if (right < heap_size && heap[right] > heap[left])
            maxCh = right;
        if (heap[maxCh] <= heap[v])
            return;
        std::swap(heap[maxCh], heap[v]);
        v = maxCh;
    }
}

void insert(int x) {
    heap[heap_size++] = x;
    siftUp(heap_size - 1);
}

int getMax() {
    return heap[0];
}

int extractMax() {
    int t = heap[0];
    heap[0] = heap[--heap_size];
    siftDown(0);
    return t;
}

int main() {
    heap_size = 0;
    heap = new int[heap_size];
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            heap_size = 0;
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            insert(x);
        }
        else {
            if (heap_size == 0)
                cout << "CANNOT\n";
            else
                cout << extractMax() << endl;
        }
    }
    delete[] heap;

    return 0;
}