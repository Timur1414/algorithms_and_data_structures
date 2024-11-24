#include <iostream>

using namespace std;

int arr[100];
int arr_size = 0;

void push (int x) {
    arr[arr_size++] = x;
}

int top() {
    return arr[arr_size - 1];
}

int pop() {
    return arr[--arr_size];
}


int main() {


    return 0;
}
