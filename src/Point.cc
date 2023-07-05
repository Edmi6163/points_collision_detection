#include "Point.hpp"

double ehuristicDifference(const Point& p1, const Point& p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

bool checkCollision(const Point& p1, const Point& p2)
{
    double distance = ehuristicDifference(p1, p2);
    return distance <= RADIUS;
}

void movePoint(Point& point, double width, double height)
{
    // Update the position based on velocity
    point.x += point.dx;
    point.y += point.dy;

    // Handle wall collisions
    if (point.x < 0 || point.x > width)
        point.dx *= -1; // Reverse the x-axis velocity

    if (point.y < 0 || point.y > height)
        point.dy *= -1; // Reverse the y-axis velocity
}

bool bouncePoint(Point& p1, Point& p2)
{
    double distance = ehuristicDifference(p1, p2);
    if (checkCollision(p1, p2)) {
        p1.dx *= -1;
        p1.dy *= -1;
        p2.dx *= -1;
        p2.dy *= -1;
        return true;
    }
    return false;
}
