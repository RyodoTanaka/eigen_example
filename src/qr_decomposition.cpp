#include <iostream>
#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/Dense>

#include "gramschmidt.hpp"

using namespace std;
using namespace Eigen;

void test1(const MatrixXd& A)
{
    cout << "======================================" << endl;
    cout << "== Usual way to get null space of A ==" << endl;
    cout << "== A is m x n matrix (m >= n)       ==" << endl;
    cout << "======================================" << endl;
    
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
    
    MatrixXd Q1 = Q.block(0,0,A.rows(),A.cols());
    MatrixXd Q2 = Q.block(0,A.cols(),A.rows(),Q.cols()-A.cols());

    cout << "== Q1 ==" << endl;
    cout << Q1 << endl;
    cout << "== Q2 ==" << endl;
    cout << Q2 << endl;

    cout << "============================================" << endl;
    cout << "== Q2 is the basis of the Null Space of A ==" << endl;
    cout << "============================================" << endl;
    cout << "== A^T*Q2 ==" << endl;
    cout << A.transpose()*Q2 << endl;
}


void test2(const MatrixXd& A)
{
    cout << "======================================" << endl;
    cout << "== Usual way to get null space of B ==" << endl;
    cout << "== B is m x n matrix (m <= n)       ==" << endl;
    cout << "======================================" << endl;

    MatrixXd B;
    B = A.transpose();

    HouseholderQR<MatrixXd> qr(B);
    MatrixXd R = qr.matrixQR().triangularView<Upper>();
    MatrixXd Q = qr.householderQ();

    cout << "=== B ===" << endl;
    cout << B << endl;
    cout << "=== Q ===" << endl;
    cout << Q << endl;
    cout << "=== R ===" << endl;
    cout << R << endl;

    cout << "=== Q*R ===" << endl;
    cout << Q*R << endl;

    MatrixXd R1 = R.block(0,0,R.rows(),R.rows());
    MatrixXd R2 = R.block(0,R.rows(),R.rows(),R.cols()-R.rows());
  
    cout << "== R1 ==" << endl;
    cout << R1 << endl;
    cout << "== R2 ==" << endl;
    cout << R2 << endl;


    cout << "== N is following matrix ==" << endl;
    cout << "=====================" << endl;
    cout << "== | -R1^(-1)*R2 | ==" << endl;
    cout << "== |      I      | ==" << endl;
    cout << "=====================" << endl;
    MatrixXd N = MatrixXd::Zero(B.cols(),B.cols()-B.rows());
    N.block(0,0,B.rows(),B.cols()-B.rows()) = -R1.inverse()*R2;
    N.block(B.rows(),0,B.cols()-B.rows(),B.cols()-B.rows()) = MatrixXd::Identity(B.cols()-B.rows(),B.cols()-B.rows());
    cout << N << endl;
    cout << "==============================" << endl;
    cout << "== N is the Null space of B ==" << endl;
    cout << "==============================" << endl;
    cout << "== B*N ==" << endl;
    cout << B*N << endl;
}

int main(void)
{
    // Set Matrix 
    MatrixXd A(6,4);
    A << 
        1, -2, 4, -8,
        2, -1, 1, -1,
        3, 2, 0, 3,
        4, 1, 1, 1,
        7, 2, 4, 8,
        10, -4, 9, -2;
    
    test1(A);
    test2(A);

    return 0;
}
