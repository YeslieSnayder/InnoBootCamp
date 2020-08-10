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
        return 0;
    }

    if (x >= 50) {
        s[index++] = sym[3];
        x = x - 50;
    }

    while (x >= 10) {
        s[index++] = sym[2];
        x = x - 10;
    }

    while (x >= 5) {
        s[index++] = sym[1];
        x = x - 5;
    }

    while (x >= 1) {
        s[index++] = sym[0];
        x = x - 1;
    }

    int count = 0;
    int curS = 4;
    char symbol = sym[curS];
    for (int i = 0; i < index; ++i) {
        if (s[i] != symbol) {
            symbol = sym[--curS];
            count = 0;
        } else {
            count++;
        }
    }
}