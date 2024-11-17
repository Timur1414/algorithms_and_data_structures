#include <iostream>

using namespace std;

void choiceInserts(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}


int main() {
    int n = 10;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    choiceInserts(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}