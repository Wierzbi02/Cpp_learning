#include <iostream>

#include "Vector.h"
#include "Matrix.h"

int main() {

    std::cout << "\n\n*************** PART 1 ***************\n\n";

    Vector v0{-5};
    Vector v1{3};
    int v2_values[3] = {1, 2, 3};
    Vector v2{3, v2_values};

    std::cout << v0 << std::endl;
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl << std::endl;

    v1(0) = 3;
    v1(1) = 2;
    v1(2) = 1;

    for (int i = 0; i < 3; ++i) {
        v2(i) = v2(i) * 2;
    }

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl << std::endl;

    std::cout << "*************** PART 2 ***************\n\n";

    Vector v3{v1};
    std::cout << v3 << std::endl << std::endl;

    v3 = v2;
    std::cout << v3 << std::endl << std::endl;

    std::cout << "*************** PART 3 ***************\n\n";

    ++++v3;
    std::cout << v3 << std::endl << std::endl;

    std::cout << v3-- << std::endl;
    std::cout << v3 << std::endl << std::endl;

    std::cout << "*************** PART 4 ***************\n\n";

    Matrix m0{-3, -4};
    Matrix m1{2, 3};
    Matrix m2{3, 2};

    m1(0, 0) = 1;
    m1(0, 1) = -1;
    m1(0, 2) = 2;
    m1(1, 1) = 1;

    m2(0, 0) = 1;
    m2(1, 1) = 2;
    m2(2, 0) = 4;
    m2(2, 1) = 2;

    std::cout << m0 << std::endl;
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl << std::endl;

    std::cout << "*************** PART 5 ***************\n\n";

    Matrix m3{m1};
    std::cout << m3 << std::endl;

    m3 = m2;
    std::cout << m3 << std::endl;

    std::cout << "*************** PART 6 ***************\n\n";

    ----m3;
    std::cout << m3 << std::endl << std::endl;

    std::cout << "*************** PART 7 ***************\n\n";

    Matrix* m4 = m1 * m2;
    std::cout << *m4 << std::endl << std::endl;
    delete m4;

    return 0;
}
