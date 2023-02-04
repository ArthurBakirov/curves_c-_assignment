#define _USE_MATH_DEFINES

#include "curves.h"

point_3D circle::coordinate(double t) {
  return {get_centre_coordinate().x + get_radius() * std::cos(t) , get_centre_coordinate().y + get_radius() * std::sin(t) , 0};
}

point_3D circle::derivative(double t) {
  return {-get_radius() * std::sin(t) , get_radius() * std::cos(t) , 0};
}


point_3D ellipse::coordinate(double t) {
  return {get_centre_coordinate().x + get_radius() * std::cos(t) , get_centre_coordinate().y + get_radius_y() * std::sin(t) , 0};
}

point_3D ellipse::derivative(double t) {
  return {-get_radius() * std::sin(t) , radius_y * std::cos(t) , 0};
}

double ellipse::get_radius_y() const {
  return radius_y;
}

helix::helix(double x_0, double y_0, double z_0, double radius_x, double step) : curve(x_0, y_0, radius_x), step(step)
{
  centre_coordinate.z = z_0;
}

point_3D helix::coordinate(double t) {
  return {get_centre_coordinate().x + get_radius() * std::cos(t) , get_centre_coordinate().y + get_radius() * std::sin(t) ,
          get_centre_coordinate().z + step * t / (2 * M_PI)};
}

point_3D helix::derivative(double t) {
  return {-get_radius() * std::sin(t) , get_radius() * std::cos(t) , step / (2 * M_PI)};
}

double helix::get_step() const {
  return step;
}

curve::curve(double x_0, double y_0, double radius) : radius(radius), centre_coordinate({x_0, y_0 , 0})
{
  if(radius < 0)
  {
    throw std::out_of_range("radius must be positive");
  }
}


double curve::get_radius() const {
  return radius;
}

point_3D curve::get_centre_coordinate() const {
  return centre_coordinate;
}
