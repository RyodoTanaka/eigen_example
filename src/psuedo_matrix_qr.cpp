#include <Eigen/Core>
#include <Eigen/QR>
#include <iostream>
using namespace Eigen;

void func1(void) {
  MatrixXd A = MatrixXd::Random(5, 8);
  VectorXd b = VectorXd::Random(5);
  VectorXd b0 = b; //save b because we are going to write over during computations  // You should have already done something like this.
  ColPivHouseholderQR<MatrixXd> qr(A.transpose());
  MatrixXd Q = qr.matrixQ();  // This computes A^+ * b
  auto R = qr.matrixQR().topRows(5).transpose().template triangularView<Lower>();
  b = qr.colsPermutation().transpose()* b;
  R.solveInPlace(b);
  VectorXd x = Q.leftCols(5) * b;  // just checking the result
  std::cout << "x = " << x.transpose() << std::endl;
  std::cout << "||A*x-b0|| = " << (A * x - b0).norm() << std::endl;  // for comparison, the solve of CompleteOrthogonalDecomposition does a pseudo-inverse
  MatrixXd pinvA = A.completeOrthogonalDecomposition().pseudoInverse();
  VectorXd x0 = pinvA * b0;  std::cout << "x0 = " << x0.transpose() << std::endl;
  std::cout << "||A*x0-b0|| = " << (A * x0 - b0).norm() << std::endl;
  std::cout << "||x - x0|| = " << (x0 - x).norm() << std::endl;
}

void func2(void) {
  using namespace std;
  MatrixXd A = MatrixXd::Random(5, 8);
  VectorXd b = VectorXd::Random(5);
  VectorXd b0 = b; //save b because we are going to write over during computations  // You should have already done something like this.
  ColPivHouseholderQR<MatrixXd> qr(A.transpose());
  MatrixXd Q = qr.matrixQ();  // This computes A^+ * b
  MatrixXd R = qr.matrixR();
  MatrixXd P = qr.colsPermutation();
  double rank = qr.rank();

  MatrixXd R_upper = R.topRows(rank);
  auto RT = R_upper.transpose().template triangularView<Lower>();
  MatrixXd PT = P.transpose();
  RT.solveInPlace(PT);
  cout << "A * (Q*R^(-T)*P^T)" << endl;
  cout << A*(Q.leftCols(rank)*PT) << endl;

  MatrixXd pinvA = A.completeOrthogonalDecomposition().pseudoInverse();
  VectorXd x0 = pinvA * b0;
  cout << "Psuedo Inverse A : " << endl;
  cout << pinvA << endl;
  cout << "(Q*R^(-T)*P^T) : " << endl;
  cout << Q.leftCols(rank)*PT << endl;
}

int main()
{
  func1();
  func2();
}
