#include <iostream>
#include <Eigen/Core>
#include <Eigen/SVD>

typedef Eigen::Matrix<double, 6, 1> Vector6d;

int main()
{
    Eigen::MatrixXd A(6, 4); // 動的サイズ行列。あとで初期化する
    Vector6d b;
    Eigen::Vector4d x;

    // 係数行列のセット
    A = Eigen::MatrixXd::Random(6, 4);
    std::cout << "matrix A = \n" << A << std::endl;
    
    // ベクトルbのセット
    b = Vector6d::Random();
    std::cout << "vector b = " << b.transpose() << std::endl;

    // JacobiSVDを使った特異値分解
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeThinV);

    // 最小二乗解
    x = svd.solve(b);

    std::cout << "A Least-square solution = " << x.transpose() << std::endl;
}
