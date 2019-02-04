#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(void)
{
    // Make skew symmetric matrix
    Vector3d v;
    v << 8, 5, 6;

    cout << "== The vector ==" << endl;
    cout << v << endl;
    
    Matrix3d v_hat;
    v_hat <<
        0, -6, 5,
        6, 0, -8,
        -5, 8, 0;

    cout << "== The skew symmetric matrix ==" << endl;
    cout << v_hat << endl;

    // Example Vector
    Vector3d a;
    a << 2, 5, 7;

    cout << "== Example vector ==" << endl;
    cout << a << endl;
    
    // Make Cross
    cout << "== v_hat * a ==" << endl;
    cout << v_hat * a << endl;
    cout << "== v x a ==" << endl;
    cout << v.cross(a) << endl;
    cout << "== -v_hat * a ==" << endl;
    cout << -v_hat * a << endl;
    cout << "== a x v ==" << endl;
    cout << a.cross(v) << endl;
    
    return 0;
}
