#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

#define PRINT_MAT(X) cout << #X << ":\n" << X << endl

void Example1(void)
{ /*
  This Function I almost copied from following link.
  https://gist.github.com/AtsushiSakai/5175898#file-geometrysample-cpp-L23
  And here is the copy right of this function.
  FileName: GeometrySample.cpp Line 23 to Line 37 
  Discription: EigenのGeometry関連の関数のサンプル 
  Author: Atsushi Sakai
  Update: 2013/03/16
  */

    cout<<"====1. 2次元空間における回転行列を使用した点の回転====="<<endl;
  //変換したい点を作成
  VectorXf point_in(2), point_out(2);
  point_in<<1,1;
  PRINT_MAT(point_in);

  //回転行列の作成
  Matrix2f rot;
  rot=Rotation2Df(M_PI);  //90度反時計回りに回転
  PRINT_MAT(rot);

  //回転行列をかけて回転
  point_out=rot*point_in;
  PRINT_MAT(point_out);
}

void Example2(void)
{
  cout << "====2. 2次元空間における同時変換行列の作成===== "<< endl;
  // 同時変換行列
  Affine2f homogeneous;
  // 回転行列と並進ベクトル
  Rotation2Df rot = Rotation2Df(M_PI/6.);
  Translation2f trans(0.5, 4);

  // 同時変換行列を生成
  homogeneous = trans * rot;

  cout << "homogeneous.rotation():" << endl;
  cout << homogeneous.rotation() << endl;
  cout << "homogeneous.translation():" << endl;
  cout << homogeneous.translation() << endl;
}

void Example3(void)
{
  cout << "====3. 2次元ベクトルにおける内積と外積=====" << endl;
  Vector2d vec1(2,3);
  Vector2d vec2(4,5);
  Matrix2d m;
  m << vec1, vec2;
  auto dot = vec1.dot(vec2);
  auto cross = m.determinant();

  cout << "vec1" << endl;
  cout << vec1.transpose() << endl;
  cout << "vec2" << endl;
  cout << vec2.transpose() << endl;
  cout << "dot product" << endl;
  cout << dot << endl;
  cout << "cross product" << endl;
  cout << cross << endl;
}

void Example4(void)
{
  Matrix<double,4,4> m;// = MatrixXd::Ones(4,4);

  m <<
    1,2,3,4,
    5,6,7,8,
    9,10,11,12,
    13,14,15,16;
  
  cout << m << endl;

  Vector2d v1 = m.block(0,3,2,1);
  Vector2d v2 = m.block(2,0,2,1);

  cout << typeid(v1).name() << endl;
  
  cout << v1.transpose() << endl;
  cout << v2.transpose() << endl;
  cout << (v1 + v2).transpose() << endl;
  cout << v1.lpNorm<2>() << endl;

  cout << ((v1+v2)/2.).transpose() << endl;
  cout << ((v1+v2)/2.).lpNorm<1>() << endl;
}

class cltst{
public:
  void b(const double& a)
  { b_ = a; };

  void c(const vector<double>& c)
  { c_ = c; };
  
  double b(void) const
  { return b_; };

  vector<double> c(void) const
  { return c_; };

  vector<double>& c(void)
  { return c_; };
  
private:
  double b_;
  vector<double> c_;
};

void test(void)
{
  cltst t;
  double a = 3;
  vector<double> b{4,5,6};

  t.b(a);
  t.c(b);
  cout << t.b() << endl;
  for(size_t i=0; i<t.c().size(); i++)
    cout << t.c()[i] << ", ";
  cout << endl;
  
  a = 4;
  b = {7,8,9};
  cout << t.b() << endl;
  for(size_t i=0; i<t.c().size(); i++)
    cout << t.c()[i] << ", ";
  cout << endl;

  vector<double>& u = t.c();
  for(size_t i=0; i<u.size(); i++)
    cout << u[i] << ", ";
  cout << endl;
  u = {7,8,9};
  for(size_t i=0; i<t.c().size(); i++)
    cout << t.c()[i] << ", ";
  cout << endl;
}

void func(const vector<double>& a)
{
  for(auto i=a.begin(); i!=a.end(); i++)
    cout << *i << ", ";
  cout << endl;
}

void test2(void)
{
  func(vector<double>{2,3,4});
}

int main(int argv, char** argc)
{
  
  // Example1();
  // Example2();
  // Example3();
  Example4();
  // test();
  test2();
  
  return 0;
}
