#include "fvCFD.H"
#include "SVD.H"

int main(int argc, char *argv[])
{
    scalarRectangularMatrix B(3, 3);
    B[0][0] = 1;
    B[0][1] = -1;
    B[0][2] = 2;

    B[1][0] = 1;
    B[1][1] = 2;
    B[1][2] = -3;

    B[2][0] = 1;
    B[2][1] = 3;
    B[2][2] = 1;
    
    SVD svd(B, SMALL);
    const scalarRectangularMatrix& Binv = svd.VSinvUt();
    
    scalar sum = 0;
    for (label i=0; i<B.n(); i++)
    {
        sum += Binv[0][i];
    }

    Info << sum-1 << endl;

    return 0;
}

