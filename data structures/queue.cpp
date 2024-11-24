#include <iostream>

using namespace std;

int arr[100];
int arr_size = 0;
int max_size = 100;
int R = 0, L = 0;

void push (int x) {
    arr[R] = x;
    R = (R + 1) % max_size;
}

int top() {
    return arr[L];
}

int pop() {
    int t = top();
    L = (L + 1) % max_size;
    return t;
}


int size() {
    if (L <= R)
        return R - L;
    else
        return max_size + (R - L);
}


int main() {


    return 0;
}
