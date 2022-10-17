#include <iostream>
#include </home/kakehi/include/eigen/Eigen/Dense>
// #include <Eigen/Dense>
#include <random>
#include <cassert>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> dis(0, 10);
    // Generate random numbers using lambda equation.
    // Put these numbers into the matrix as elements of it.
    Eigen::MatrixXf A = Eigen::MatrixXf::NullaryExpr(3, 3, [&](){return dis(gen);});

    std::cout << "A:" << std::endl;
    std::cout << A    << std::endl;

    Eigen::JacobiSVD<Eigen::MatrixXf> svd(A, Eigen::ComputeFullU | Eigen::ComputeFullV);

    std::cout << std::endl;
    std::cout << "U:" << std::endl;
    std::cout << svd.matrixU() << std::endl;
                                
    std::cout << std::endl;
    std::cout << "S:" << std::endl;
    std::cout << svd.singularValues() << std::endl;

    std::cout << std::endl;
    std::cout << "V:" << std::endl;
    std::cout << svd.matrixV() << std::endl;

    //- Decomposed matrix A using svd() to U * S * V.T.
    //- Therefore, generalized inverse matrix A will be V * S.T * U.T.

    Eigen::VectorXf s = svd.singularValues();
    s = s.array().inverse();

    // Variable name of generalized inverse matrix is Ainv
    Eigen::MatrixXf Ainv = svd.matrixV() * s.asDiagonal() * svd.matrixU().transpose();

    // Multiply A and A* then it makes unit matrix.
    Eigen::MatrixXf m = A * Ainv;
    std::cout << std::endl;
    std::cout << "m = A * Ainv = " << std::endl;
    std::cout << m << std::endl;

    assert(Eigen::MatrixXf::Identity(3, 3).isApprox(m));

    return 0;
}
