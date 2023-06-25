#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>


struct Point {
  double x;
  double y;
  double dx;  // Velocity in the x-axis,used to define speed and direction
  double dy;
};

bool checkCollision(const Point& p1, const Point& p2, double radius);
void movePoint(Point& point, double width, double height);