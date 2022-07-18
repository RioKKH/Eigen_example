#include <iostream>
#include "/home/kakehi/include/Eigen/Core"
// #include <Eigen/core>

using namespace Eigen;

int main()
{
	Vector3d a(0.5, 1.0, -2.4);
	Vector3d v1, v2, v3, v4, v5, v6, v7, v8;

	v1 << 1.0, 0.7, -0.52; // カンマ演算子とシフト演算子による初期化
	v2(0) = 3.0; v2(1) = 1.0; v2(2) = -2.0; // 要素を直接に指定する代入

	std::cout << "a = " << a.transpose() << std::endl;
	std::cout << "v1 = " << v1.transpose() << std::endl;
	std::cout << "v2 = " << v2.transpose() << std::endl;

	v1 = Vector3d::Identity(); // 単位ベクトル(1, 0, 0)
	v1 = Vector3d::Zero(); // 零ベクトル (0, 0, 0)
	v3 = Vector3d::Ones(); // (1, 1, 1)
	v4 = Vector3d::UnitX(); // (1, 0, 0)
	v5 = Vector3d::UnitY(); // (0, 1, 0)
	v6 = Vector3d::UnitZ(); // (0, 0, 1)
	v7 = Vector3d::Random(); // ランダムな値のベクトル
	v8 = Vector3d::Constant(0.1); // すべて同じ値のベクトル

	return 0;
}


