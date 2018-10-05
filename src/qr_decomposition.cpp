#include <iostream>
#include <Eigen/Core>
#include <Eigen/QR>

using namespace std;
using namespace Eigen;

int main(void)
{
  MatrixXd A(5,4);
  A << 
    1, -2, 4, -8,
    1, -1, 1, -1,
    1, 0, 0, 0,
    1, 1, 1, 1,
    1, 2, 4, 8;


  return 0;
}
