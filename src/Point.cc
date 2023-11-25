#include "Point.hpp"
double ehuristicDifference(const Point &p1, const Point &p2) {
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}


bool checkCollision(const Point &p1, const Point &p2) {
  double distance = ehuristicDifference(p1, p2);
  return distance <= RADIUS;
}


/*
  Update the position based on speed
  Handle wall collisions, using width and height of the window
*/
void movePoint(Point &point, double width, double height) {
  point.x += point.dx;
  point.y += point.dy;

  if (point.x < 0 || point.x > width)
    point.dx *= -1;

  if (point.y < 0 || point.y > height)
    point.dy *= -1;
}

/*
 * @brief: When two points collide, they bounce off each other, inverting their speed.
 */
bool bouncePoint(Point &p1, Point &p2) {
  double distance = ehuristicDifference(p1, p2);
  double collision = checkCollision(p1, p2);

  if(collision){
    p1.dx = 0 - p1.dx;
    p1.dy = 0 - p1.dy;
    p2.dx = 0 - p2.dx;
    p2.dy = 0 - p2.dy;
  }
  return collision;
}
