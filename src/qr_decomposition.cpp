#include <iostream>
#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/Dense>

#include "gramschmidt.hpp"

using namespace std;
using namespace Eigen;

int main(void)
{
  // Set Matrix 
  // m = 5
  // n = 4
  MatrixXd A(5,4);
  A << 
    1, -2, 4, -8,
    2, -1, 1, -1,
    3, 2, 0, 3,
    4, 1, 1, 1,
    7, 2, 4, 8;

  HouseholderQR<MatrixXd> qr(A);
  MatrixXd R = qr.matrixQR().triangularView<Upper>();
  MatrixXd Q = qr.householderQ();

  cout << "=== A ===" << endl;
  cout << A << endl;
  cout << "=== Q ===" << endl;
  cout << Q << endl;
  cout << "=== R ===" << endl;
  cout << R << endl;

  cout << "=== Q*R ===" << endl;
  cout << Q*R << endl;

  for(int i=0; i<Q.cols(); i++){
    cout << "=== Q.col(" << i << ") ===" << endl;
    cout << Q.col(i) << endl;
    cout << "=== Q.col(" << i << ") norm ===" << endl;
    cout << Q.col(i).norm() << endl;
  }

  auto Q_hat = Q.block(0,0,5,4);
  auto R_hat = R.block(0,0,4,4);

  cout << "=== R_hat === " << endl;
  cout << R_hat << endl;
  cout << "=== det(R_hat) ===" << endl;
  cout << R_hat.determinant() << endl;
  cout << "=== R_hat inverse ==" << endl;
  cout << R_hat.inverse() << endl;

  // Do QR decomposition
  // by Classical Gram Schmidt
  // we get reduced Q (Q_hat)
  MatrixXd Q_g = CGS(A);
  
  cout << "==== Classical Gram Schmidt Q (Q_g) ====" << endl;
  cout << Q_g << endl;
  cout << "==== Q ====" << endl;
  cout << Q << endl;
  cout << "==== Q_hat ====" << endl;
  cout << Q_hat << endl;
  cout << "==== Q_g * R_hat ====" << endl;
  cout << Q_g * R_hat << endl;
  cout << "=== A ===" << endl;
  cout << A << endl;
    
  return 0;
}
