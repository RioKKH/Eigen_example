#include <iostream>
#include "/home/kakehi/include/Eigen/Dense"

using namespace Eigen;

int main()
{
	Vector3d a; // 3次元ベクトル。要素はdouble

	a << 1.0, 0.7, -0.52; // ベクトルの要素を設定
	std::cout << "vector a = \n" << a << std::endl;
	std::cout << "vector a.T = \n" << a.transpose() << std::endl;

	std::cout << "a(0) =" << a(0) << std::endl;
	std::cout << "a(1) =" << a(1) << std::endl;
	std::cout << "a(2) =" << a(2) << std::endl;
}


