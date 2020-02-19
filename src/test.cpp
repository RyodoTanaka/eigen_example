#include<iostream>
#include<vector>
#include<algorithm>
#include<Eigen/Core>

using namespace std;

struct ForceInfo {
  // force
  Eigen::Vector3d f;
  // distance
  double d;
  // position on the Robot
  // in absolute coordinate
  Eigen::Vector3d p_rbt;
  // position on the Environment
  // in absolute coordinate
  Eigen::Vector3d p_env;
};
struct LinkInfo {
  // link name
  string link_name;
  // is contact
  bool is_contact;
  // force info
  vector<ForceInfo> force_info;
};

namespace Eigen {
namespace Vector {
template <class T>
inline void push_back(Eigen::Matrix<T,Eigen::Dynamic,1>& v, const T d) {
  Eigen::Matrix<T,Eigen::Dynamic,1> tmp = v;
  v.resize(tmp.size() + 1);
  v.head(tmp.size()) = tmp;
  v[v.size()-1] = d;
}
template <class T>
inline void wedge(Eigen::Matrix<T,3,3>& mat, const Eigen::Matrix<T,3,1>&v) {
  mat(0,0) = 0.0;
  mat(0,1) = -v[2];
  mat(0,2) = v[1];
  mat(1,0) = v[2];
  mat(1,1) = 0.0;
  mat(1,2) = -v[0];
  mat(2,0) = -v[1];
  mat(2,1) = v[0];
  mat(2,2) = 0.0;
}
}
}

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
