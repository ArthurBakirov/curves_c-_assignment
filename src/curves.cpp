#include "curves.h"

point_3D circle::coordinate(double t) {
  return {centre_coordinate.x + radius * std::cos(t) , centre_coordinate.y + radius * std::sin(t) , 0};
}

point_3D circle::derivative(double t) {
  return {-radius * std::sin(t) , radius * std::cos(t) , 0};
}

point_3D ellipse::coordinate(double t) {
  return {centre_coordinate.x + radius * std::cos(t) , centre_coordinate.y + radius_y * std::sin(t) , 0};
}

point_3D ellipse::derivative(double t) {
  return {-radius * std::sin(t) , radius_y * std::cos(t) , 0};
}

helix::helix(double x_0, double y_0, double z_0, double radius_x, double step) : curve(x_0, y_0, radius_x), step(step)
{
  centre_coordinate.z = z_0;
}

point_3D helix::coordinate(double t) {
  return {centre_coordinate.x + radius * std::cos(t) , centre_coordinate.y + radius * std::sin(t) ,
          centre_coordinate.z + step * t};
}

point_3D helix::derivative(double t) {
  return {-radius * std::sin(t) , radius * std::cos(t) , step};
}

curve::curve(double x_0, double y_0, double radius) : radius(radius), centre_coordinate({x_0, y_0 , 0})
{
  if(radius < 0)
  {
    throw std::out_of_range("radius must be positive");
  }
}
