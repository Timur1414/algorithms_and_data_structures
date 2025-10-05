#include <iostream>

using namespace std;

double power(double a, int n) {
    double res = 1;
    double a_in_power2 = a; // a^2^i
    while (n > 0) {
        if (n & 1 == 1)
            res *= a_in_power2;
        a_in_power2 *= a_in_power2;
        n = n >> 1;  // если n отрицательное, то цикл будет бесконечным, так как знаковый бит не участвует в битовом сдвиге.
    }
    return res;
}

int main() {
    double a = 2;
    int n = 8;
    cout << power(a, n);


    return 0;
}