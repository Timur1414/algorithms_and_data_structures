#include <iostream>

using namespace std;

long long long_mul(long long a, long long b, long long m) {
    // перемножение long long за O(1) без переполнения
    long long q = (long long) ((long double) a * (long double) b / (long double) m);
    long long r = a * b - q * m;
    return (r + 5 * m) % m;
}

long long pow_mod(long long a, long long b, long long m) {
    // быстрое возведение в степень + взятие остатка на каждом шаге
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        long long temp = pow_mod(a, b / 2, m);
        return long_mul(temp, temp, m) % m;
    }
    return (long_mul(a, pow_mod(a, b - 1, m), m)) % m;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool is_prime(long long x) {
    // на основе теста Ферма за O(log n): https://habr.com/ru/articles/205318/?ysclid=mgbuvdrayx488622639
    if (x == 1)
        return false;
    if (x == 2)
        return true;
    srand(time(nullptr));
    for (int i = 0; i < 100; i++) {
        long long test = (rand() % (x - 2)) + 2;
        if (gcd(test, x) != 1)
            return false;
        if (pow_mod(test, x - 1, x) != 1)
            return false;
    }
    return true;
}

int main() {
    long long n = 201405241; // 201405221 | 201405241 | 201405287 | 201405289 | 201405299 (5 integers)
    cout << is_prime(n);


    return 0;
}
