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

int main(int argv, char** argc)
{
  
  Example1();
  Example2();
  Example3();
  
  return 0;
}
