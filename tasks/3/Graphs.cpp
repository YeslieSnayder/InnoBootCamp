//
// Created by Andrey on 11.08.2020.
//

#include <iostream>
#include <vector>

//4
//0 10 8 6
//10 0 3 7
//8 3 0 1
//6 7 1 0

int size;
int currentMinSize;

std::vector<int> road;
std::vector<int> currentRoad;
std::vector<std::vector<int>> distances;

/**
 * Method for initializing global variables.
 * According to this method, we need to write numbers in console.
 * First digit (@var size) - count of graph vertexes;
 * Next (@var size) digits - distance between graph vertexes,
 * which are represented in vector (two-dimensional array)
 */
void initialize() {
    std::cin >> size;
    currentMinSize = 200000;
    road.resize(size + 1);
    currentRoad.resize(size + 1);

    for (int i = 0; i < size; ++i) {
        std::vector <int> row (0);

        for (int j = 0; j < size; ++j) {
            int a;
            std::cin >> a;
            row.push_back(a);
        }
        distances.push_back(row);
    }
}

int func(std::vector<int> arr, int sum, int lengthOfWay, int indexPrevElement) {
    if (sum >= currentMinSize) return -1;

    currentRoad[lengthOfWay] = indexPrevElement;

    if (++lengthOfWay > size - 2) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == 0) continue;
            if (i == indexPrevElement) continue;
            currentRoad[lengthOfWay] = i;
            currentRoad[++lengthOfWay] = 0;

            sum += distances[indexPrevElement][i] +
                    distances[0][i];
            if (sum < currentMinSize) {
                currentMinSize = sum;
                road = currentRoad;
            }
            return currentMinSize;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == 0) continue;

            std::vector <int> temp(0);
            for (int j = 0; j < size; ++j) {
                temp.push_back((lengthOfWay % 2 == 1) ? distances[j][i]
                                                 : distances[i][j]);
            }
            for (int j : currentRoad) {
                temp[currentRoad[j]] = 0;
            }

            func(temp, sum+arr[i], lengthOfWay, i);
        }
    }
    return currentMinSize;
}

/**
 * Method for printing an array.
 * In this case: Printed a graph's currentRoad.
 */
void printRoad(int* arr) {
    for (int i = 0; i <= sizeof(arr); i++) {
        std::cout << arr[i] << ' ';
    }
}

int main() {
    initialize();
    func(distances[0], 0, 0, 0);

    std::cout << currentMinSize << std::endl;
    printRoad(road.data());
}