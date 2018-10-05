#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(void)
{
  double theta = M_PI/6;
  Matrix2d rot;
  rot <<
    cos(theta), -sin(theta),
    sin(theta), cos(theta);
  auto trans_rot = rot.transpose();
  auto inv_rot = rot.inverse();

  cout << "==================" << endl;
  cout << rot << endl;
  cout << "==================" << endl;
  cout << trans_rot << endl;
  cout << "==================" << endl;
  cout << inv_rot << endl;
  cout << "==================" << endl;
  cout << rot*trans_rot << endl;
  cout << "==================" << endl;

  Matrix2d test;
  test <<
    2,3,
    6,4;
  cout << "==================" << endl;
  cout << test << endl;
  cout << "==================" << endl;
  cout << test.inverse() << endl;
  cout << "==================" << endl;
  cout << test * test.inverse() << endl;
  cout << "==================" << endl;




  
  
  return 0;
}
