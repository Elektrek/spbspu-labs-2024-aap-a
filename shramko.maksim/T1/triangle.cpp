#include "triangle.hpp"
#include <algorithm>
#include <cmath>

shramko::Triangle::Triangle(point_t one, point_t two, point_t three)
{
  one_ = one;
  two_ = two;
  three_ = three;
}

double shramko::Triangle::getArea()
{
  return std::abs(((two_.x - one_.x) * (three_.y - one_.y) - (three_.x - one_.x) * (two_.y - one_.y))) / 2.0;
}

double shramko::Triangle::getRectangleFrame() const
{
  double xMax = std::max(one_.x, std::max(two_.x, three_.x));
  double yMax = std::max(one_.y, std::max(two_.y, three_.y));
  double xMin = std::min(one_.x, std::min(two_.x, three_.x));
  double yMin = std::min(one_.y, std::min(two_.y, three_.y));

  shramko::rectangle_t rectangleFrame;
  rectangleFrame.height = xMax - yMin;
  rectangleFrame.width = xMax - xMin;
  rectangleFrame.pos.x = xMin + (rectangleFrame / 2.0);
  rectangleFrame.pos.y = yMin + (rectangleFrame / 2.0);

  return rectangleFrame;
}

void shramko::Triangle::move(point_t s)
{
  shramko::point_t pos;
  pos.x = std::abs(one_.x + two_.x + three_.x) / 3.0;
  pos.y = std::abs(one_.y + two_.y + three_.y) / 3.0;

  double xMove = s.x - pos.x;
  double yMove = s.y - pos.y;

  one_.x += xMove;
  one_.y += yMove;
  two_.x += xMove;
  two_.y += yMove;
  three_.x += xMove;
  three_.y += yMove;
}

void shramko::Triangle::move(double x, double y)
{
  one_.x += xMove;
  one_.y += yMove;
  two_.x += xMove;
  two_.y += yMove;
  three_.x += xMove;
  three_.y += yMove;
}

void shramko::Triangle::scale(k)
{
  point_t pos;
  pos.x = std::abs(one_.x + two.x + three_.x) / 3.0;
  pos.y = std::abs(one_.y + two.y + three_.y) / 3.0;

  one_.x = (one_.x - pos.x) * k + pos.x;
  one_.y = (one_.y - pos.y) * k + pos.y;
  two_.x = (two_.x - pos.x) * k + pos.x;
  two_.y = (two_.y - pos.y) * k + pos.y;
  three_.x = (three_.x - pos.x) * k + pos.x;
  three_.y = (three_.y - pos.y) * k + pos.y;
}
