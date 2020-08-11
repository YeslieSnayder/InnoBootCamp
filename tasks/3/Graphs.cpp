//
// Created by Andrey on 11.08.2020.
// *Updated by Andrey on 12.08.2020.
//

#include <iostream>
#include <vector>

int size;
int currentMinSize;

bool isFind = false;

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

/**
 * Method for printing a vector.
 * In this case: Printed a graph's currentRoad.
 */
void printRoad(const std::vector<int>& arr) {
    std::cout << "Path: ";
    for (int i : arr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

void func(std::vector<int> arr, int sum, int lengthOfWay, int indexPrevElement) {
    if (isFind && sum >= currentMinSize) return;
    currentRoad[lengthOfWay] = indexPrevElement;

    lengthOfWay++;

    if (lengthOfWay > size - 1) return;
    if (lengthOfWay == size - 1) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == 0) continue;
            if (i == indexPrevElement) continue;
            currentRoad[lengthOfWay] = i;
            currentRoad[lengthOfWay+1] = 0;

            sum += distances[indexPrevElement][i] +
                    distances[0][i];
            if (!isFind || sum < currentMinSize) {
                isFind = true;
                currentMinSize = sum;
                road = currentRoad;
            }

            currentRoad[lengthOfWay] = 0;
            return;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == 0) continue;

            std::vector<int> temp(0);
            for (int j = 0; j < size; ++j) {
                if (arr[j] == 0) {
                    temp.push_back(0);
                    continue;
                }
                temp.push_back((lengthOfWay % 2 == 1) ? distances[j][i]
                                                      : distances[i][j]);
            }
            func(temp, sum + arr[i], lengthOfWay, i);
        }
    }
}

int main() {
    initialize();
    func(distances[0], 0, 0, 0);

    std::cout << currentMinSize << std::endl;
    printRoad(road);
}