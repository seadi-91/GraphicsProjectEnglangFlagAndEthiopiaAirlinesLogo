#include <GL/freeglut.h>
#include <vector>
#include <cmath>

#ifndef CALLBACK
#define CALLBACK
#endif

struct Point { double x, y; };


std::vector<std::vector<Point>> contour1, contour2, contour3;

float scaleFactor = 1.0f, translateX = 0.0f, translateY = 0.0f, rotationAngle = 0.0f;
float locX = 0.0f, locY = 0.0f;

void appendCubicBezier(std::vector<Point>& contour, Point p0, Point p1, Point p2, Point p3, int segments = 40) {
    for (int i = 0; i <= segments; ++i) {
        double t = (double)i / (double)segments;
        double u = 1.0 - t;
        double x = u*u*u * p0.x + 3.0 * u*u * t * p1.x + 3.0 * u * t*t * p2.x + t*t*t * p3.x;
        double y = u*u*u * p0.y + 3.0 * u*u * t * p1.y + 3.0 * u * t*t * p2.y + t*t*t * p3.y;
        contour.push_back({x, y});
    }
}

void buildLogoGeometry() {
    contour1.clear(); contour2.clear(); contour3.clear();
    std::vector<Point> c1;
    Point s1 = {18.308, 11.603};
    appendCubicBezier(c1, s1, {20.698, 10.147}, {22.547, 9.073}, {23.274, 7.248});
    appendCubicBezier(c1, {23.274, 7.248}, {24.818, 3.078}, {23.637, 1.383}, {22.17, 2.684});
    appendCubicBezier(c1, {22.17, 2.684}, {20.293, 4.506}, {11.478, 13.754}, {0.195, 20.257});
    appendCubicBezier(c1, {0.195, 20.257}, {0.023, 20.355}, {-0.005, 20.579}, {0.753, 20.348});
    appendCubicBezier(c1, {0.753, 20.348}, {5.233, 18.776}, {14.983, 13.643}, {18.308, 11.603});
    contour1.push_back(c1);
}