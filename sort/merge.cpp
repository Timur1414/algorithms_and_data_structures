#include <iostream>

using namespace std;

void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* left_arr = new int[n1];
    int* right_arr = new int[n2];
    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (int i = 0 ; i < n2; i++)
        right_arr[i] = arr[mid + 1 + i];
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i] < right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    delete[] left_arr;
    delete[] right_arr;
}

void mergeSort(int* arr, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main() {
    int n = 10;
    int arr[] = {10, 9, 8, 7, 5, 5, 4, 3, 2, 1};
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}
