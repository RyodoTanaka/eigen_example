#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main(void)
{
    // Try to know the solution of Null space
    MatrixXf A(3,4);
    VectorXf b = VectorXf::Zero(3);
    A <<
        1,-10,-24,-42,
        1,-8,-18,-32,
        -2,20,51,87;
    // b << 3, 3, 4;
    cout << "Here is the matrix A:\n" << A << endl;
    cout << "Here is the vector b:\n" << b << endl;
    VectorXf x = A.colPivHouseholderQr().solve(b);
    cout << "The solution is:\n" << x << endl;
}
