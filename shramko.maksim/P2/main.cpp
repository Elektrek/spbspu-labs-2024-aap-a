#include <iostream>
#include "string.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  const double error = 0.0029;
  const double step = 0.1;

  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Input error\n";
    return 1;
  }
  if (left <= -1.0 || right >= 1.0 )
  {
    std::cerr << "Area error\n";
    return 1;
  }
  if (left > right || k <= 0)
  {
    std::cerr << "Interval error\n";
    return 1;
  }

  for (auto i = left; i < right; i += step)
  {
    shramko::string(i, k, error);
  }
  shramko::string(right, k, error);
}
