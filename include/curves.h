#ifndef CAD_C___ASSIGNMENT_CURVES_H
#define CAD_C___ASSIGNMENT_CURVES_H

#include <cmath>
#include "utilities.h"



class __declspec(dllexport) curve
{
public:
  curve(double x_0, double y_0, double radius);

  virtual point_3D coordinate(double t) = 0;

  virtual point_3D derivative(double t) = 0;

  double radius = 0;
  point_3D centre_coordinate = {0, 0, 0};

};


class __declspec(dllexport) circle : public curve
{
public:
  circle(double x_0, double y_0, double radius) : curve(x_0, y_0, radius)
  {}
  point_3D coordinate(double t) override;

  point_3D derivative(double t) override;
};


class __declspec(dllexport) ellipse : public curve
{
public:
  ellipse(double x_0, double y_0, double radius_x, double radius_y) : curve(x_0, y_0, radius_x), radius_y(radius_y)
  {}

  double radius_y = 0;

  point_3D coordinate(double t) override;

  point_3D derivative(double t) override;
};


class __declspec(dllexport) helix : public curve
{
public:
  helix(double x_0, double y_0, double z_0, double radius_x, double step);

  double step = 0;

  point_3D coordinate(double t) override;

  point_3D derivative(double t) override;
};


#endif //CAD_C___ASSIGNMENT_CURVES_H
