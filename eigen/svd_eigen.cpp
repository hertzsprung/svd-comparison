#include <iostream>
#include <Eigen/SVD>

using Eigen::MatrixXd;
using Eigen::JacobiSVD;

// from http://eigen.tuxfamily.org/bz/show_bug.cgi?id=257#c14
template<typename _Matrix_Type_>
_Matrix_Type_ pseudoInverse(const _Matrix_Type_ &a, double epsilon = std::numeric_limits<double>::epsilon())
{
    Eigen::JacobiSVD< _Matrix_Type_ > svd(a ,Eigen::ComputeThinU | Eigen::ComputeThinV);
    double tolerance = epsilon * std::max(a.cols(), a.rows()) *svd.singularValues().array().abs()(0);
    return svd.matrixV() *  (svd.singularValues().array().abs() > tolerance).select(svd.singularValues().array().inverse(), 0).matrix().asDiagonal() * svd.matrixU().adjoint();
}

int main()
{
	MatrixXd m(3,3);
    m(0,0) = 1;
    m(0,1) = -1;
    m(0,2) = 2;

    m(1,0) = 1;
    m(1,1) = 2;
    m(1,2) = -3;

    m(2,0) = 1;
    m(2,1) = 3;
    m(2,2) = 1;

    MatrixXd mInv = pseudoInverse(m);

    double sum = 0;

    for (int i=0; i<m.rows(); i++)
    {
        sum += mInv(0,i);
    }

	std::cout << sum-1 << std::endl;
    }
