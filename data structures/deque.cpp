#include <iostream>

using namespace std;

int arr[100];
int arr_size = 0;
int max_size = 100;
int R = 0, L = 0;

void push_front(int x) {
    L = (L + max_size - 1) % max_size;
    arr[L] = x;
}

void push_back(int x) {
    R = (R + 1) % max_size;
    arr[R] = x;
}

int front() {
    return arr[L];
}

int back() {
    return arr[R];
}

int pop_front() {
    int t = front();
    L = (L + 1) % max_size;
    return t;
}

int pop_back() {
    int t = back();
    R = (R + max_size - 1) % max_size;
    return t;
}

int size() {
    if (L <= R) return R - L + 1;
    return (R + max_size - L + 1) % max_size;
}

int main() {


    return 0;
}
