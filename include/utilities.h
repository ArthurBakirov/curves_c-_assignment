#ifndef CAD_C___ASSIGNMENT_UTILITIES_H
#define CAD_C___ASSIGNMENT_UTILITIES_H

#include <functional>
#include <random>
#include <iostream>

struct __declspec(dllexport) point_3D
{
  double x;
  double y;
  double z;

  friend std::ostream& operator<< (std::ostream& ostream,const point_3D& point_3D)
  {
    ostream << point_3D.x << " " << point_3D.y << " " << point_3D.z;
    return ostream;
  }
};

class __declspec(dllexport) Random_double
{
public:
  Random_double(double low, double high)
      :r(std::bind(std::uniform_real_distribution<>(low,high),std::default_random_engine(rd()))){}

  double operator()()
  {
    return r();
  }

private:
  std::function<double()> r;
  std::random_device rd;
};


#endif //CAD_C___ASSIGNMENT_UTILITIES_H
