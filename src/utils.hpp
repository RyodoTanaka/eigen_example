#include <Eigen/Core>

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
