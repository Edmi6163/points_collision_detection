#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#define NUM_POINTS 50
#define RADIUS 15.0

struct Point {
    double x;
    double y;
    double dx; // Velocity in the x-axis,used to define speed and direction
    double dy;
};

bool checkCollision(const Point& p1, const Point& p2, double radius);
bool bouncePoint(Point& p1, Point& p2);
void movePoint(Point& point, double width, double height);
