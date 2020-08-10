//
// Created by Andrey on 10.08.2020.
//

#include <iostream>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) return -1;

    if (a == 0) {
        std::cout << "x = " << -c/b;
        return 0;
    }

    double D = b*b - 4*a*c;

    if (D < 0) return 0;
    else if (D == 0) {
        std::cout << "x = " << -b / (2*a);
        return 0;
    }
    double d = sqrt(D);
    std::cout << "x1 = " << (-b + d) / (2*a) << "\n";
    std::cout << "x2 = " << (-b - d) / (2*a);
    return 0;
}