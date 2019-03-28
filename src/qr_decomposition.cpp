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
    MatrixXd A(6,4);
    A << 
        1, -2, 4, -8,
        2, -1, 1, -1,
        3, 2, 0, 3,
        4, 1, 1, 1,
        7, 2, 4, 8,
        10, -4, 9, -2;
    
    //////////////////////////////////////
    // Usual way to get null space of A //
    //////////////////////////////////////
    // Do QR decomposition
    // by Classical Gram Schmidt
    // we get reduced Q (Q_hat)

    // MatrixXd Q_g = CGS(B);
  
    // cout << "==== Classical Gram Schmidt Q (Q_g) ====" << endl;
    // cout << Q_g << endl;
    // cout << "==== Q ====" << endl;
    // cout << Q << endl;
    // cout << "=== B ===" << endl;
    // cout << B << endl;

    
    
    ////////////////////////////////////////////////
    // get null space using transpose matrix of A //
    ////////////////////////////////////////////////
    // B is transposed matrix of A
    MatrixXd B;
    B = A.transpose();

    FullPivHouseholderQR<MatrixXd> qr(B);
    MatrixXd R = qr.matrixQR().triangularView<Upper>();
    MatrixXd Q = qr.matrixQ();

    cout << "=== B ===" << endl;
    cout << B << endl;
    cout << "=== Q ===" << endl;
    cout << Q << endl;
    cout << "=== R ===" << endl;
    cout << R << endl;

    cout << "=== Q*R ===" << endl;
    cout << Q*R << endl;

    
    // One way to get null space
    MatrixXd R1 = R.block(0,0,R.rows(),R.rows());
    MatrixXd R2 = R.block(0,R.rows(),R.rows(),R.cols()-R.rows());
  
    cout << "== R1 ==" << endl;
    cout << R1 << endl;
    cout << "== R2 ==" << endl;
    cout << R2 << endl;
  
    // cout << "== N  ==" << endl;
    // MatrixXd N = MatrixXd::Zero(B.cols(),1);
    // N.block(0,0,R1.rows(),1) = -R1.inverse()*R2;
    // N.block(R1.rows(),0,N.rows()-R1.rows(),1) = MatrixXd::Identity(N.rows()-R1.rows(),1);
    // cout << N << endl;
  
    // cout << "== B*N ==" << endl;
    // cout << B*N << endl;
    
    // Other way to get null space //
    MatrixXd Q1 = Q.block(0,0,Q.rows(),Q.rows());
    MatrixXd Q2 = Q.block(0,Q.rows(),Q.rows(),Q.cols()-Q.rows());

    cout << "== Q1 ==" << endl;
    cout << Q1 << endl;
    cout << "== Q2 ==" << endl;
    cout << Q2 << endl;

    
    return 0;
}
