#define _USE_MATH_DEFINES

#include <iostream>
#include "curves.h"
#include <memory>
#include <vector>
#include <typeinfo>
#include <omp.h>



int main()
{
  //Populate a container (e.g. vector or list) of objects of these types created in random manner with random parameters
  std::vector<std::shared_ptr<curve>> random_curves;
  Random_double random_number {0, 30};
  for(int i = 0; i < 30; i++)
  {
    random_curves.push_back(std::make_shared<circle>(random_number(), random_number(), random_number()));
    random_curves.push_back(std::make_shared<ellipse>(random_number(), random_number(), random_number(), random_number()));
    random_curves.push_back(std::make_shared<helix>(random_number(), random_number(), random_number(), random_number(), random_number()));
  }

  //Print coordinates of points and derivatives of all curves in the container at t=PI/4.
  std::cout << "coordinates of points and derivatives:\n";
  for(const auto& curve : random_curves)
  {
    std::cout << curve->coordinate(M_PI/4) << std::endl;
    std::cout << curve->derivative(M_PI/4) << std::endl;
    std::cout << "\n";
  }


  //Populate a second container that would contain only circles from the first container. Make sure the
  //second container shares (i.e. not clones) circles of the first one, e.g. via pointers
  std::vector<std::shared_ptr<curve>> random_circles;
  std::cout << "number of shared pointers for each circle:\n";
  for(const auto& curve_ : random_curves)
  {
    if(typeid(*curve_).name() == typeid(circle).name())
    {
      random_circles.push_back(std::shared_ptr<curve>(curve_));
      std::cout << curve_.use_count() << std::endl;
    }
  }


  //Sort the second container in the ascending order of circles’ radii. That is, the first element has the
  //smallest radius, the last - the greatest.
  std::sort(random_circles.begin(), random_circles.end(), [](const std::shared_ptr<curve>& circle_a, const std::shared_ptr<curve>& circle_b)
  {
    return circle_a->get_radius() < circle_b->get_radius();
  });

  std::cout << "\ncircles sorted by their radii:\n";
  for(const auto& curve_ : random_circles)
  {
    std::cout << curve_->get_radius() << std::endl;
  }

  //Compute the total sum of radii of all curves in the second container.

  double sum_of_radii = 0;
#pragma omp parallel shared(sum_of_radii, random_circles)
  {
#pragma omp for
    for (const auto &curve_ : random_circles)
    {
      sum_of_radii += curve_->get_radius();
    }
  }
  std::cout << "\nsum of radii:\n";
  std::cout << sum_of_radii << std::endl;


  return 0;
}
