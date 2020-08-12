//
// Created by Andrey on 12.08.2020.
//

#include <iostream>

long long fact(long long number) {
    if (number < 0) return 0;
    if (number == 0 || number == 1) return 1;

    long long res = 1;
    while (number > 1) res *= number--;

    return res;
}

long long f1(long long n, int m) {
    if (m > n) return 1;
    if (m == n) return 2;

    long long k = n / m;
    long long ans = 1;

    // It's a sum of combinations (n+i*(1-m) choose i)
    for (long long i = 1; i <= k; ++i) {
        ans += (fact(n + i * (1 - m)) / (fact(i) * fact(n - i * m)));
    }

    return ans;
}

int main() {
    long long ans;
    long long n;
    int m;

    std::cin >> n >> m;
    ans = f1(n,m);
    std::cout << (ans % 1000000007);
}