#include <iostream>
#include "matrix.hpp"

using std::cout;
using std::endl;
using skrbcr::linvec;

int main() {
    linvec<int, 3> a = {0, 2, 0};
    linvec<double, 3> b = {1., 1., 1.};
    linvec<double, 3> c = {1., 6, 5};
    double d = 2.3;
    // c[2] = 1;
    c = 2. * c * d - b;
    // c /= 2.;
    cout << c[0] << "," << c[1] << "," << c[2] << endl;
    // cout << a[0] << "," << a[1] << "," << a[2] << endl;
    return 0;
}