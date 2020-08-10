//
// Created by Andrey on 10.08.2020.
//

#include <iostream>

int isInPar(double x1, double y1, double x2, double y2, double x, double y) {
    double s = (x2 - x1)*(y - y1) - (y2 - y1)*(x - x1);
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;

    double l1, l2, r2, r1;
    double t1, t2, t3, t4;

    if (x1 <= x2 && x1 <= x3 && x1 <= x4) {
        l1 = x1;
        t1 = y1;
        if (x2 >= x3 && x2 >= x4) {
            r1 = x2;
            t4 = y2;
            if (x3 >= x4) { r2 = x3; l2 = x4; t2 = y4; t3 = y3;}
            else {          r2 = x4; l2 = x3; t2 = y3; t3 = y4;}
        } else if (x3 >= x2 && x3 >= x4) {
            r1 = x3;
            t4 = y3;
            if (x2 >= x4) { r2 = x2; l2 = x4; t2 = y4; t3 = y2;}
            else {          r2 = x4; l2 = x2; t2 = y2; t3 = y4;}
        } else {
            r1 = x4;
            t4 = y4;
            if (x2 >= x3) { r2 = x2; l2 = x3; t2 = y3; t3 = y2;}
            else {          r2 = x3; l2 = x2; t2 = y2; t3 = y3;}
        }
    } else if (x2 <= x1 && x2 <= x3 && x2 <= x4) {
        l1 = x2;
        t1 = y2;
        if (x1 >= x3 && x1 >= x4) {
            r1 = x1;
            t4 = y1;
            if (x3 >= x4) { r2 = x3; l2 = x4; t2 = y4; t3 = y3;}
            else {          r2 = x4; l2 = x3; t2 = y3; t3 = y4;}
        } else if (x3 >= x1 && x3 >= x4) {
            r1 = x3;
            t4 = y3;
            if (x1 >= x4) { r2 = x1; l2 = x4; t2 = y4; t3 = y1;}
            else {          r2 = x4; l2 = x1; t2 = y1; t3 = y4;}
        } else {
            r1 = x4;
            t4 = y4;
            if (x2 >= x3) { r2 = x1; l2 = x3; t2 = y3; t3 = y1;}
            else {          r2 = x3; l2 = x1; t2 = y1; t3 = y3;}
        }
    } else if (x3 <= x2 && x3 <= x1 && x3 <= x4) {
        l1 = x3;
        t1 = y3;
        if (x2 >= x1 && x2 >= x4) {
            r1 = x2;
            t4 = y2;
            if (x1 >= x4) { r2 = x1; l2 = x4; t2 = y4; t3 = y1;}
            else {          r2 = x4; l2 = x1; t2 = y1; t3 = y4;}
        } else if (x1 >= x2 && x1 >= x4) {
            r1 = x1;
            t4 = y1;
            if (x2 >= x4) { r2 = x2; l2 = x4; t2 = y4; t3 = y2;}
            else {          r2 = x4; l2 = x2; t2 = y2; t3 = y4;}
        } else {
            r1 = x4;
            t4 = y4;
            if (x2 >= x1) { r2 = x2; l2 = x1; t2 = y1; t3 = y2;}
            else {          r2 = x1;l2 = x2; t2 = y2; t3 = y1;}
        }
    } else {
        l1 = x4;
        t1 = y4;
        if (x2 >= x3 && x2 >= x1) {
            r1 = x2;
            t4 = y2;
            if (x3 >= x1) { r2 = x3; l2 = x1; t2 = y1; t3 = y3;}
            else {          r2 = x1; l2 = x3; t2 = y3; t3 = y1;}
        } else if (x3 >= x2 && x3 >= x1) {
            r1 = x3;
            t4 = y3;
            if (x2 >= x1) { r2 = x2; l2 = x1; t2 = y1; t3 = y2;}
            else {          r2 = x1; l2 = x2; t2 = y2; t3 = y1;}
        } else {
            r1 = x1;
            t4 = y1;
            if (x2 >= x3) { r2 = x2; l2 = x3; t2 = y3; t3 = y2;}
            else {          r2 = x3; l2 = x2; t2 = y2; t3 = y3;}
        }
    }

    int count = 0;
    count += isInPar(r1, t4, r2, t3, x5, y5);
    count += isInPar(r1, t4, l2, t2, x5, y5);
    count += isInPar(l1, t1, r2, t3, x5, y5);
    count += isInPar(l1, t1, l2, t2, x5, y5);

    if (count == 0)
        std::cout << "Point lies in parallelogram";
    else
        std::cout << "Point doesn't lie in parallelogram";
}