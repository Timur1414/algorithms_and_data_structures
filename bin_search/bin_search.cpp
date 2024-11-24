#include <iostream>

using namespace std;

bool bin_search(int* arr, int n, int p) {  // left binary search
    int l = -1;
    int r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (arr[mid] < p)
            l = mid;
        else
            r = mid;
    }
    return arr[r] == p;
}


int main() {
    int n = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << bin_search(arr, n, 3);


    return 0;
}