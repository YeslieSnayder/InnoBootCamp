//
// Created by Andrey on 12.08.2020.
//

#include <iostream>
#include <vector>

int main() {
    int countPins;
    int countKnocks;
    std::vector<bool> pins; // if true - pin is there, if false - no pin

    std::cin >> countPins >> countKnocks;
    if (countPins < 0 || countKnocks < 0) return -1;

    pins.reserve(countPins);
    for (int i = 0; i < countPins; ++i) {
        pins.push_back(true);
    }

    int l, r;
    for (int i = 0; i < countKnocks; ++i) {
        std::cin >> l >> r;
        if (l < 0 || l > countPins || r < 0 || r > countPins) return -1;

        for (int j = l-1; j < r; ++j) {
            pins[j] = false;
        }
    }

    for (bool b : pins) {
        std::cout << ((b) ? "I" : ".");
    }
}