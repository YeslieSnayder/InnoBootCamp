//
// Created by Andrey on 10.08.2020.
//

#include <iostream>

double s1, s2, s3;

bool isExist(double x1, double y1, double x2, double y2, double x3, double y3) {
    if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3) ||
        (x1 == x2) && (y1 == y2) || (x1 == x3) && (y1 == y3) || (x3 == x2) && (y3 == y2)) {
        return false;
    }

    s1 = sqrt((abs(x1) - abs(x2)) * (abs(x1) - abs(x2)) + (abs(y1) - abs(y2)) * (abs(y1) - abs(y2)));
    s2 = sqrt((abs(x1) - abs(x3)) * (abs(x1) - abs(x3)) + (abs(y1) - abs(y3)) * (abs(y1) - abs(y3)));
    s3 = sqrt((abs(x3) - abs(x2)) * (abs(x3) - abs(x2)) + (abs(y3) - abs(y2)) * (abs(y3) - abs(y2)));

    if ((s1 + s2) > s3 || (s1 + s3) > s2 || (s2 + s3) > s1) {
        return true;
    }

    return false;
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (!isExist(x1, y1, x2, y2, x3, y3)) {
        std::cout << "This triangle doesn't exist";
        return 0;
    }

    double p = (s1 + s2 + s3) / 2;
    double area = sqrt(p*(p-s1)*(p-s2)*(p-s3));
    std::cout << "Area of the triangle = " << area;
    return 0;
}