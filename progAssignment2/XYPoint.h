#define XYPOINT_H

class XYPoint {
public:
    int x;
    int y;

    XYPoint(int xc, int yc);
};

float distance(const XYPoint& p1, const XYPoint& p2);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4, const XYPoint& p5);