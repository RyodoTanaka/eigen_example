#include<iostream>
#include<vector>
#include<algorithm>
#include<Eigen/Core>

#include "utils.hpp"

using namespace std;

int main(void) {

  Eigen::VectorXd a;
  Eigen::VectorXi b;

  Eigen::Vector::push_back<double>(a,1);
  Eigen::Vector::push_back<double>(a,2);
  Eigen::Vector::push_back<double>(a,3);

  Eigen::Vector::push_back<int>(b,4);
  Eigen::Vector::push_back<int>(b,5);
  Eigen::Vector::push_back<int>(b,6);
  
  cout << a.transpose() << endl;
  cout << b.transpose() << endl;

  Eigen::Vector3d c;
  Eigen::Matrix3d m;
  c.x() = 1;
  c.y() = 2;
  c.z() = 3;
  Eigen::Vector::wedge<double>(m,c);

  cout << c.transpose() << endl;
  cout << m << endl;
  
  return 0;
}
