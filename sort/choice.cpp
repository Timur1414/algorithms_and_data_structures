#include <iostream>

using namespace std;

void choiceSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(arr[i], arr[min]);
    }
}


int main() {
    int n = 10;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    choiceSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}