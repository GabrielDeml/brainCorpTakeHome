#include "main.h"
#include "linalg.h"
#include "matrix.h"
#include <iostream>

int main() {
    std::cout << "=== Matrix Tests ===" << std::endl;

    // 
    Matrix<int> zeroMatrix = fillMatrix(3, 3, 0);
    
    std::cout << "=== Zero Matrix ===" << std::endl;
    zeroMatrix.print();
    bool ZeroMatrixFailed = false;
    // Check that all values are zero
    for (int i = 0; i < zeroMatrix.height; i++) {
        for (int j = 0; j < zeroMatrix.width; j++) {
            if (zeroMatrix.index(j, i) != 0) {
                ZeroMatrixFailed = true;
            }
        }
    }
    if (ZeroMatrixFailed) {
        std::cout << "Failed Zero Matrix Test" << std::endl;
    } else {
        std::cout << "Passed Zero Matrix Test" << std::endl;
    }

    Matrix<int> identityMatrix = identity<int>(3);

    std::cout << "=== Identity Matrix ===" << std::endl;

    identityMatrix.print();

    bool IdentityMatrixFailed = false;

    // Check that all values match the identity 
    for (int i = 0; i < identityMatrix.height; i++) {
        for (int j = 0; j < identityMatrix.width; j++) {
            if (i == j) {
                if (identityMatrix.index(j, i) != 1) {
                    IdentityMatrixFailed = true;
                }
            } else {
                if (identityMatrix.index(j, i) != 0) {
                    IdentityMatrixFailed = true;
                }
            }
        }
    }

    if (IdentityMatrixFailed) {
        std::cout << "Failed Identity Matrix Test" << std::endl;
    } else {
        std::cout << "Passed Identity Matrix Test" << std::endl;
    }

    Matrix<int> a = fillMatrix(3, 3, 1);

    std::cout << "=== Matrix A ===" << std::endl;
    a.print();

    Matrix<int> b = fillMatrix(3, 3, 2);

    std::cout << "=== Matrix B ===" << std::endl;
    b.print();

    Matrix<int> c = fillMatrix(3, 3, 3);

    std::cout << "=== Matrix C ===" << std::endl;
    c.print();


    Matrix<int> ab = multiply(a, b);

    std::cout << "=== Matrix AB ===" << std::endl;

    ab.print();

    bool ABFailed = false;

    // Check that all values match the identity
    for (int i = 0; i < ab.height; i++) {
        for (int j = 0; j < ab.width; j++) {
            if (ab.index(j, i) != 6) {
                ABFailed = true;
            }
        }
    }

    if (ABFailed) {
        std::cout << "Failed Matrix AB Test" << std::endl;
    } else {
        std::cout << "Passed Matrix AB Test" << std::endl;
    }

    Matrix<int> abc = multiply(ab, c);

    std::cout << "=== Matrix ABC ===" << std::endl;

    abc.print();

    bool ABCFailed = false;
    // Check that all values match the identity
    for (int i = 0; i < abc.height; i++) {
        for (int j = 0; j < abc.width; j++) {
            if (abc.index(j, i) != 18) {
                ABCFailed = true;
            }
        }
    }

}