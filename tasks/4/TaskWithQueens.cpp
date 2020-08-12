//
// Created by Andrey on 12.08.2020.
//

#include <iostream>

int main() {
    int queens[8][8] = {{0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0}};

    bool hasTouch = false;
    int x;
    int y;
    for (int i = 0; i < 8; ++i) {
        std::cin >> x >> y;
        if (hasTouch) continue;

        if (queens[--y][--x] == 0)
            queens[y][x] = 1;
        else {
            hasTouch = true;
            continue;
        }

        for (int j = 1; j < 8; ++j) {
            if ((x+j) < 8 && (y+j) < 8 && queens[y+j][x+j] != 0 ||
                    (x+j) < 8 && (y-j) >= 0 && queens[y-j][x+j] != 0 ||
                    (x-j) >= 0 && (y+j) < 8 && queens[y+j][x-j] != 0 ||
                    (x-j) >= 0 && (y-j) >= 0 && queens[y-j][x-j] != 0) {

                hasTouch = true;
                break;
            }
        }
    }

    std::cout << ((hasTouch) ? "YES" : "NO");
}