#include <iostream>
#include "matrix.hpp"

using std::cout;
using std::endl;
using skrbcr::linvector;

int main() {
    linvector<int, 3> a = {0, 2, 0};
    linvector<int, 3> c = a;
    c[2] = 1;
    a = a + c;
    cout << c[0] << "," << c[1] << "," << c[2] << endl;
    cout << a[0] << "," << a[1] << "," << a[2] << endl;
    return 0;
}