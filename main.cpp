#include "main.h"
#include "linalg.h"
#include "matrix.h"
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;

    Matrix<int> m(3, 3);

    m.update(0, 0, 1);

    std::cout << m.index(0, 0) << std::endl;

    m.print();

    Matrix<int> a(3, 3);

    // Create an idenity matrix
    for (int i = 0; i < 3; i++) {
        a.update(i, i, 1);
    }

    Matrix<int> b(3, 3);

    // Create a matrix with all 1s

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            b.update(i, j, 1);
        }
    }

    Matrix<int> c = add(a, b);

    c.print();
    
    return 0;
}