//
// Created by Andrey on 10.08.2020.
//

#include <iostream>

int main() {
    int a, b, gcd;
    gcd = 1;
    std::cin >> a >> b;

    for (int i = (a < b ? a : b); i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }

    std::cout << "Greatest common divisor of " << a << " and " << b << " = " << gcd;
    return 0;
}