#include "main.h"
#include "linalg.h"
#include "matrix.h"
#include <iostream>

int main() {

    bool allPassed = true;
    std::cout << "=== Matrix Tests ===" << std::endl;

    // 
    Matrix<int> zeroMatrix = fillMatrix(3, 3, 0);
    
    std::cout << "=== Zero Matrix ===" << std::endl;
    zeroMatrix.print();
    bool ZeroMatrixPassed = true;
    // Check that all values are zero
    for (int i = 0; i < zeroMatrix.height; i++) {
        for (int j = 0; j < zeroMatrix.width; j++) {
            if (zeroMatrix.index(j, i) != 0) {
                ZeroMatrixPassed = false;
                allPassed = false;
            }
        }
    }
    if (ZeroMatrixPassed) {
        std::cout << "Passed Zero Matrix Test" << std::endl;
    } else {
        std::cout << "Failed Zero Matrix Test" << std::endl;
    }

    Matrix<int> identityMatrix = identity<int>(3);

    std::cout << "=== Identity Matrix ===" << std::endl;

    identityMatrix.print();

    bool identityMatrixPassed = true;

    // Check that all values match the identity 
    for (int i = 0; i < identityMatrix.height; i++) {
        for (int j = 0; j < identityMatrix.width; j++) {
            if (i == j) {
                if (identityMatrix.index(j, i) != 1) {
                    identityMatrixPassed = false;
                }
            } else {
                if (identityMatrix.index(j, i) != 0) {
                    identityMatrixPassed = false;
                }
            }
        }
    }

    if (identityMatrixPassed) {
        std::cout << "Passed Identity Matrix Test" << std::endl;
    } else {
        std::cout << "Failed Identity Matrix Test" << std::endl;
    }

    if(allPassed) {
        std::cout << "All tests passed" << std::endl;
    } else {
        std::cout << "Some tests failed" << std::endl;
    }

}