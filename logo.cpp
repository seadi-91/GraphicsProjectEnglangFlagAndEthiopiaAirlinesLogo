#include <GL/freeglut.h>
#include <vector>
#include <cmath>

#ifndef CALLBACK
#define CALLBACK
#endif

struct Point
{
    double x, y;
};

std::vector<std::vector<Point>> contour1, contour2, contour3;

float scaleFactor = 1.0f, translateX = 0.0f, translateY = 0.0f, rotationAngle = 0.0f;
float locX = 0.0f, locY = 0.0f;

void appendCubicBezier(std::vector<Point> &contour, Point p0, Point p1, Point p2, Point p3, int segments = 40)
{
    for (int i = 0; i <= segments; ++i)
    {
        double t = (double)i / (double)segments;
        double u = 1.0 - t;
        double x = u * u * u * p0.x + 3.0 * u * u * t * p1.x + 3.0 * u * t * t * p2.x + t * t * t * p3.x;
        double y = u * u * u * p0.y + 3.0 * u * u * t * p1.y + 3.0 * u * t * t * p2.y + t * t * t * p3.y;
        contour.push_back({x, y});
    }
}

void buildLogoGeometry()
{
    contour1.clear();
    contour2.clear();
    contour3.clear();
    std::vector<Point> c1;
    Point s1 = {18.308, 11.603};
    appendCubicBezier(c1, s1, {20.698, 10.147}, {22.547, 9.073}, {23.274, 7.248});
    appendCubicBezier(c1, {23.274, 7.248}, {24.818, 3.078}, {23.637, 1.383}, {22.17, 2.684});
    appendCubicBezier(c1, {22.17, 2.684}, {20.293, 4.506}, {11.478, 13.754}, {0.195, 20.257});
    appendCubicBezier(c1, {0.195, 20.257}, {0.023, 20.355}, {-0.005, 20.579}, {0.753, 20.348});
    appendCubicBezier(c1, {0.753, 20.348}, {5.233, 18.776}, {14.983, 13.643}, {18.308, 11.603});
    contour1.push_back(c1);
}
void buildRemainingGeometry()
{

    std::vector<Point> c2;
    Point s2 = {20.131, 11.27};
    appendCubicBezier(c2, s2, {21.073, 10.684}, {22.107, 11.033}, {20.447, 13.736});
    appendCubicBezier(c2, {20.447, 13.736}, {19.321, 15.398}, {18.542, 16.366}, {15.527, 17.28});
    appendCubicBezier(c2, {15.527, 17.28}, {13.452, 18.065}, {5.759, 20.304}, {0.37, 20.955});
    appendCubicBezier(c2, {0.37, 20.955}, {-0.031, 20.988}, {-0.154, 20.841}, {0.242, 20.709});
    appendCubicBezier(c2, {0.242, 20.709}, {5.377, 19.403}, {18.226, 12.499}, {20.131, 11.27});
    contour2.push_back(c2);

    std::vector<Point> c3;
    Point s3 = {11.154, 21.74};
    appendCubicBezier(c3, s3, {13.358, 21.668}, {15.016, 21.982}, {16.879, 20.01});
    appendCubicBezier(c3, {16.879, 20.01}, {18.829, 17.99}, {18.599, 16.94}, {17.423, 17.267});
    appendCubicBezier(c3, {17.423, 17.267}, {15.678, 17.791}, {9.312, 19.957}, {1.801, 21.002});
    appendCubicBezier(c3, {1.801, 21.002}, {1.463, 21.048}, {1.545, 21.228}, {1.941, 21.252});
    appendCubicBezier(c3, {1.941, 21.252}, {6.959, 21.726}, {8.852, 21.762}, {11.154, 21.74});
    contour3.push_back(c3);
}

void CALLBACK tessBeginCB(GLenum type) { glBegin(type); }
void CALLBACK tessEndCB() { glEnd(); }
void CALLBACK tessVertexCB(void *data) { glVertex3dv((GLdouble *)data); }

void drawTessellatedShape(GLUtesselator *tobj, const std::vector<std::vector<Point>> &contours)
{
    gluTessBeginPolygon(tobj, NULL);
    for (const auto &contour : contours)
    {
        gluTessBeginContour(tobj);
        for (const auto &pt : contour)
        {
            GLdouble *v = new GLdouble[3]{pt.x, pt.y, 0.0};
            gluTessVertex(tobj, v, v);
        }
        gluTessEndContour(tobj);
    }
    gluTessEndPolygon(tobj);
}