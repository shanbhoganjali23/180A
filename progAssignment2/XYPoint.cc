#include "XYPoint.h"
#include <cmath>

XYPoint::XYPoint(int xc, int yc) : x(xc), y(yc) {}

float distance(const XYPoint& p1, const XYPoint& p2) {
    int x1 = p1.x;
    int x2 = p2.x;

    int y1 = p1.y;
    int y2 = p2.y;

    float dist = std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    return dist;
}

float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3) {
    return distance(p1, p2) + distance(p2, p3);
}

float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4) {
    return distance(p1, p2) + distance(p2, p3) + distance(p3, p4);
}

float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4, const XYPoint& p5) {
    return distance(p1, p2) + distance(p2, p3) + distance(p3, p4) + distance(p4, p5);
}