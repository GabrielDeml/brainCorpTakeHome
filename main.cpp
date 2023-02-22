#include "main.h"
#include "linalg.h"
#include "matrix.h"
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;

    Matrix<int> m(3, 3);

    m.update(0, 0, 1);

    std::cout << m.index(0, 0) << std::endl;
    
    return 0;
}