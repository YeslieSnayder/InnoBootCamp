//
// Created by Andrey on 10.08.2020.
//

#include <iostream>

int main() {
    int x;
    std::cin >> x;
    char sym[5] = {'I', 'V', 'X', 'L', 'C'};

    char s[15];
    int index = 0;

    if (x == 100) {
        s[index++] = sym[4];
        x = x - 100;
    }

    if (x >= 90) {
        s[index++] = sym[2];
        s[index++] = sym[4];
        x = x - 90;
    }
    if (x >= 50) {
        s[index++] = sym[3];
        x = x - 50;
    }

    if (x >= 40) {
        s[index++] = sym[2];
        s[index++] = sym[3];
        x = x - 40;
    }
    while (x >= 10) {
        s[index++] = sym[2];
        x = x - 10;
    }

    if (x == 9) {
        s[index++] = sym[0];
        s[index++] = sym[2];
        x = x - 9;
    }
    while (x >= 5) {
        s[index++] = sym[1];
        x = x - 5;
    }

    if (x == 4) {
        s[index++] = sym[0];
        s[index++] = sym[1];
        x = x - 4;
    }
    while (x >= 1) {
        s[index++] = sym[0];
        x = x - 1;
    }

    for (int i = 0; i < index; ++i) {
        std::cout << s[i];
    }
}