#include <iostream>

using namespace std;

void qSort(int* arr, int l, int r) {
    if (r - l <= 1)
        return;
    int mid = arr[(l + r) / 2];
    int x = l, y = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < mid) {
            swap(arr[i], arr[x]);
            if (x != y)
                swap(arr[i], arr[y]);
            x++;
            y++;
        }
        else if (arr[i] == mid) {
            swap(arr[i], arr[y]);
            y++;
        }
    }
    qSort(arr, l, x);
    qSort(arr, y, r);
}


int main() {
    int n = 10;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    qSort(arr, 0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}