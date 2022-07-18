#include <iostream>
#include <Eigen/Core>
#include <Eigen/SVD>

typedef Eigen::Matrix<double, 6, 1> Vector6d;

int main()
{
    Eigen::MatrixXd A(2, 2);
    Eigen::Vector2d b;
    Eigen::Vector2d x;

    // 係数行列のセット
    A << 3.0, 4.0, 4.0, 14;
    std::cout << "matrix A = \n" << A << std::endl;
    
    // ベクトルbのセット
    b << 7.0, 13.0;
    std::cout << "vector b = " << b.transpose() << std::endl;

    // JacobiSVDを使った特異値分解
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeThinV);

    // 最小二乗解
    x = svd.solve(b);

    std::cout << "A Least-square solution = " << x.transpose() << std::endl;
}
