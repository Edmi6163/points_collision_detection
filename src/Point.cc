#include "Point.hpp"
bool checkCollision(const Point& p1, const Point& p2, double radius) {
    double distance = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    return distance <= radius;
}

void movePoint(Point& point, double width, double height) {
    // Update the position based on velocity
    point.x += point.dx;
    point.y += point.dy;

    // Handle wall collisions
    if (point.x < 0 || point.x > width)
        point.dx *= -1; // Reverse the x-axis velocity

    if (point.y < 0 || point.y > height)
        point.dy *= -1; // Reverse the y-axis velocity
}

