#include <iostream>

using namespace std;

void counterSort(int* arr, int n) {
    int count[100] = {};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index] = i;
            index++;
        }
    }
}


int main() {
    int n = 10;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    counterSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}