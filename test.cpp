#include "test.h"
#include <iostream>


/**
 * @brief test matrix multiplication
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testZeroMatrix() {
    std::cout << "\n=== Zero Matrix (3, 3) ===" << std::endl;
    Matrix<int> zeroMatrix = fillMatrix(3, 3, 0);
    zeroMatrix.print();
    bool testPassed = true;
    // Check that all values are zero
    for (int i = 0; i < zeroMatrix.height; i++) {
        for (int j = 0; j < zeroMatrix.width; j++) {
            if (zeroMatrix.index(j, i) != 0) {
                testPassed = false;
            }
        }
    }
    if (testPassed) {
        std::cout << "Passed Zero Matrix Test" << std::endl;
    } else {
        std::cout << "Failed Zero Matrix Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test zero matrix with float
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testZeroMatrixFloat() {
    std::cout << "\n=== Zero Matrix (3, 3) float ===" << std::endl;
    Matrix<float> zeroMatrixFloat = fillMatrix(3, 3, 0.0f);
    zeroMatrixFloat.print();
    bool testPassed = true;
    // Check that all values are zero
    for (int i = 0; i < zeroMatrixFloat.height; i++) {
        for (int j = 0; j < zeroMatrixFloat.width; j++) {
            if (zeroMatrixFloat.index(j, i) != 0.0) {
                testPassed = false;
            }
        }
    }
    if (testPassed) {
        std::cout << "Passed Zero Matrix Float Test" << std::endl;
    } else {
        std::cout << "Failed Zero Matrix Float Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test zero matrix with double
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testZeroMatrixDouble() {
    std::cout << "\n=== Zero Matrix (3, 3) double ===" << std::endl;
    Matrix<double> zeroMatrixDouble = fillMatrix(3, 3, 0.0);
    zeroMatrixDouble.print();
    bool testPassed = true;
    // Check that all values are zero
    for (int i = 0; i < zeroMatrixDouble.height; i++) {
        for (int j = 0; j < zeroMatrixDouble.width; j++) {
            if (zeroMatrixDouble.index(j, i) != 0.0) {
                testPassed = false;
            }
        }
    }

    if (testPassed) {
        std::cout << "Passed Zero Matrix Double Test" << std::endl;
    } else {
        std::cout << "Failed Zero Matrix Double Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test ones matrix with int
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testOnesMatrix(){
    std::cout << "\n=== Ones Matrix (3, 3) ===" << std::endl;
    Matrix<int> onesMatrix = fillMatrix(3, 3, 1);
    onesMatrix.print();
    bool testPassed = true;
    // Check that all values are ones
    for (int i = 0; i < onesMatrix.height; i++) {
        for (int j = 0; j < onesMatrix.width; j++) {
            if (onesMatrix.index(j, i) != 1) {
                testPassed = false;
            }
        }
    }
    if (testPassed) {
        std::cout << "Passed Ones Matrix Test" << std::endl;
    } else {
        std::cout << "Failed Ones Matrix Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test matrix with size 5, 3 filled with threes
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testThreesMatrix() {
    std::cout << "\n=== Threes Matrix (5, 3) ===" << std::endl;
    Matrix<int> threeMatrix = fillMatrix(5, 3, 3);
    threeMatrix.print();
    bool testPassed = true;
    // Check that all values are three
    for (int i = 0; i < threeMatrix.height; i++) {
        for (int j = 0; j < threeMatrix.width; j++) {
            if (threeMatrix.index(j, i) != 3) {
                testPassed = false;
            }
        }
    }
    if (testPassed) {
        std::cout << "Passed 3 Matrix Test" << std::endl;
    } else {
        std::cout << "Failed 3 Matrix Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test the ones matrix with size zero
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testOnesMatrixSizeZero() {
    std::cout << "\n=== Ones Matrix (0, 0) ===" << std::endl;
    bool testPassed = false;
    // Catch the error
    try {
        Matrix<int> zeroMatrix = fillMatrix(0, 0, 0);
    } catch (std::invalid_argument& e) {
        std::cout << "Caught out of range exception" << std::endl;
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Passed Zero Matrix Test" << std::endl;
    } else {
        std::cout << "Failed Zero Matrix Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test the identity matrix with int
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testIdentityMatrix() {
    std::cout << "\n=== Identity Matrix ===" << std::endl;
    Matrix<int> identityMatrix = identity<int>(3);

    identityMatrix.print();

    bool testPassed = true;

    // Check that all values match the identity 
    for (int i = 0; i < identityMatrix.height; i++) {
        for (int j = 0; j < identityMatrix.width; j++) {
            if (i == j) {
                if (identityMatrix.index(j, i) != 1) {
                    testPassed = false;
                }
            } else {
                if (identityMatrix.index(j, i) != 0) {
                    testPassed = false;
                }
            }
        }
    }

    if (testPassed) {
        std::cout << "Passed Identity Matrix Test" << std::endl;
    } else {
        std::cout << "Failed Identity Matrix Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test the identity matrix with a size of zero
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testIdentityMatrixSizeZero() {
    std::cout << "\n=== Identity Matrix (0, 0) ===" << std::endl;
    bool testPassed = false;
    // Catch the error
    try {
        Matrix<int> zeroMatrix = identity<int>(0);
    } catch (std::invalid_argument& e) {
        std::cout << "Caught out of range exception" << std::endl;
        testPassed = true;
    }

    if (testPassed) {
        std::cout << "Passed Zero Identity Matrix Test" << std::endl;
    } else {
        std::cout << "Failed Zero Identity Matrix Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test the matrix multiplication with ints
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testMultiplication() {
    std::cout << "\n=== Multiplication ===" << std::endl;

    Matrix<int> matrixA = fillMatrix(3, 3, 1);
    std::cout << "Matrix A" << std::endl;
    matrixA.print();
    Matrix<int> matrixB = fillMatrix(3, 3, 2);
    std::cout << "Matrix B" << std::endl;
    matrixB.print();

    Matrix<int> matrixC = multiply(matrixA, matrixB);

    std::cout << "Matrix C" << std::endl;
    matrixC.print();

    bool testPassed = true;

    // Check that all values match the identity
    for (int i = 0; i < matrixC.height; i++) {
        for (int j = 0; j < matrixC.width; j++) {
            if (matrixC.index(j, i) != 6) {
                testPassed = false;
            }
        }
    }

    if (testPassed) {
        std::cout << "Passed Multiplication Test" << std::endl;
    } else {
        std::cout << "Failed Multiplication Test" << std::endl;
    }
    return testPassed;
}


/**
 * @brief test the multiplication of two matrices of type float
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testMultiplicationFloat() {
    std::cout << "\n=== Multiplication float ===" << std::endl;
    Matrix<float> matrixA = fillMatrix(3, 3, 1.0f);
    std::cout << "Matrix A" << std::endl;
    matrixA.print();
    Matrix<float> matrixB = fillMatrix(3, 3, 2.0f);
    std::cout << "Matrix B" << std::endl;
    matrixB.print();

    Matrix<float> matrixC = multiply(matrixA, matrixB);

    std::cout << "Matrix C" << std::endl;
    matrixC.print();
    bool testPassed = true;

    // Check that all values match the identity
    for (int i = 0; i < matrixC.height; i++) {
        for (int j = 0; j < matrixC.width; j++) {
            if (matrixC.index(j, i) != 6.0f) {
                testPassed = false;
            }
        }
    }

    if (testPassed) {
        std::cout << "Passed Multiplication Float Test" << std::endl;
    } else {
        std::cout << "Failed Multiplication Float Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test the multiplication of two double matrices
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testMultiplicationDouble() {
    std::cout << "\n=== Multiplication double ===" << std::endl;
    Matrix<double> matrixA = fillMatrix(3, 3, 1.0);
    std::cout << "Matrix A" << std::endl;
    matrixA.print();
    Matrix<double> matrixB = fillMatrix(3, 3, 2.0);
    std::cout << "Matrix B" << std::endl;
    matrixB.print();

    Matrix<double> matrixC = multiply(matrixA, matrixB);
    std::cout << "Matrix C" << std::endl;
    matrixC.print();
    bool testPassed = true;

    // Check that all values match the identity
    for (int i = 0; i < matrixC.height; i++) {
        for (int j = 0; j < matrixC.width; j++) {
            if (matrixC.index(j, i) != 6.0) {
                testPassed = false;
            }
        }
    }
    if (testPassed) {
        std::cout << "Passed Multiplication Double Test" << std::endl;
    } else {
        std::cout << "Failed Multiplication Double Test" << std::endl;
    }
    return testPassed;
}

/**
 * @brief test multiplication with identity matrix
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testMultiplicationWithIdentity() {
    std::cout << "\n=== Multiplication with Identity ===" << std::endl;

    Matrix<int> matrixA = fillMatrix(3, 3, 1);
    std::cout << "Matrix A" << std::endl;
    matrixA.print();

    Matrix<int> matrixB = identity<int>(3);
    std::cout << "Matrix B" << std::endl;
    matrixB.print();

    Matrix<int> matrixC = multiply(matrixA, matrixB);

    std::cout << "Matrix C" << std::endl;
    matrixC.print();

    bool testPassed = true;

    // Create a list of lists that is the correct values
    std::vector<std::vector<int>> correctValues = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    for (int i = 0; i < matrixC.width; i++) {
        for (int j = 0; j < matrixC.height; j++) {
            if (matrixC.index(i,j) != correctValues[i][j]) {
                testPassed = false;
            }
        }
    }
    return testPassed;
}

/**
 * @brief test multiplication with different sizes
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testMultiplicationWithDifferentSizes() {
    std::cout << "\n=== Multiplication with different sizes ===" << std::endl;

    Matrix<int> matrixA = fillMatrix(2, 3, 1);
    std::cout << "Matrix A" << std::endl;
    matrixA.print();

    Matrix<int> matrixB = fillMatrix(3, 2, 2);
    std::cout << "Matrix B" << std::endl;
    matrixB.print();

    bool testPassed = true;

    // Create a list of lists that is the correct values
    std::vector<std::vector<int>> correctValues = {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    };

    Matrix<int> matrixC = multiply(matrixA, matrixB);
    std::cout << "Matrix C" << std::endl;
    matrixC.print();

    for (int i = 0; i < matrixC.width; i++) {
        for (int j = 0; j < matrixC.height; j++) {
            if (matrixC.index(i,j) != correctValues[i][j]) {
                testPassed = false;
            }
        }
    }
    return testPassed;
}

/**
 * @brief test multiplication with incompatible sizes
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testMultiplicationWithIncompatibleSizes() {
    std::cout << "\n=== Multiplication with different sizes ===" << std::endl;

    Matrix<int> matrixA = fillMatrix(3, 3, 1);
    std::cout << "Matrix A" << std::endl;
    matrixA.print();

    Matrix<int> matrixB = fillMatrix(3, 2, 2);
    std::cout << "Matrix B" << std::endl;
    matrixB.print();

    bool testPassed = false;
    // Catch error 
    try {
        Matrix<int> matrixI = multiply(matrixA, matrixB);
    } catch (std::invalid_argument& e) {
        std::cout << "Caught error: " << e.what() << std::endl;
        testPassed = true;
    }
    return testPassed;
}

/**
 * @brief Test transpose with int
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testTranspose() {
    std::cout << "\n=== Transpose ===" << std::endl;

    Matrix<int> matrixA = fillMatrix(3, 3, 0);
    // build
    // 1 2 3
    // 4 5 6
    // 7 8 9
    for (int i = 0; i < matrixA.width; i++) {
        for (int j = 0; j < matrixA.height; j++) {
            matrixA.update(i, j, (i * 3) + j + 1);
        }
    }

    std::cout << "Matrix A" << std::endl;
    matrixA.print();

    Matrix<int> matrixAT = transpose(matrixA);

    std::cout << "Matrix AT" << std::endl;
    matrixAT.print();

    bool testPassed = true;

    // Create a list of lists that is the correct values
    std::vector<std::vector<int>> correctValues = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    for (int i = 0; i < matrixAT.width; i++) {
        for (int j = 0; j < matrixAT.height; j++) {
            if (matrixAT.index(i,j) != correctValues[i][j]) {
                testPassed = false;
            }
        }
    }
    return testPassed;
}

/**
 * @brief Test transpose with float
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testTransposeFloat() {
    std::cout << "\n=== Transpose float ===" << std::endl;

    Matrix<float> matrixA = fillMatrix(3, 3, 0.0f);
    // build
    // 1 2 3
    // 4 5 6
    // 7 8 9
    for (int i = 0; i < matrixA.width; i++) {
        for (int j = 0; j < matrixA.height; j++) {
            matrixA.update(i, j, (i * 3) + j + 1);
        }
    }

    std::cout << "Matrix A" << std::endl;
    matrixA.print();

    Matrix<float> matrixAT = transpose(matrixA);

    std::cout << "Matrix AT" << std::endl;
    matrixAT.print();

    bool testPassed = true;

    // Create a list of lists that is the correct values
    std::vector<std::vector<float>> correctValues = {
        {1.0f, 4.0f, 7.0f},
        {2.0f, 5.0f, 8.0f},
        {3.0f, 6.0f, 9.0f}
    };

    for (int i = 0; i < matrixAT.width; i++) {
        for (int j = 0; j < matrixAT.height; j++) {
            if (matrixAT.index(i,j) != correctValues[i][j]) {
                testPassed = false;
            }
        }
    }
    return testPassed;
}


/**
 * @brief Test transpose with double
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool testTransposeDouble() {
    std::cout << "\n=== Transpose double ===" << std::endl;

    Matrix<double> matrixA = fillMatrix(3, 3, 0.0);
    // build
    // 1 2 3
    // 4 5 6
    // 7 8 9
    for (int i = 0; i < matrixA.width; i++) {
        for (int j = 0; j < matrixA.height; j++) {
            matrixA.update(i, j, (i * 3) + j + 1);
        }
    }

    std::cout << "Matrix A" << std::endl;
    matrixA.print();

    Matrix<double> matrixAT = transpose(matrixA);

    std::cout << "Matrix AT" << std::endl;
    matrixAT.print();

    bool testPassed = true;

    // Create a list of lists that is the correct values
    std::vector<std::vector<double>> correctValues = {
        {1.0, 4.0, 7.0},
        {2.0, 5.0, 8.0},
        {3.0, 6.0, 9.0}
    };

    for (int i = 0; i < matrixAT.width; i++) {
        for (int j = 0; j < matrixAT.height; j++) {
            if (matrixAT.index(i,j) != correctValues[i][j]) {
                testPassed = false;
            }
        }
    }
    return testPassed;
}

/**
 * @brief Run all test
 * 
 * @return true Test Passed
 * @return false Test Failed
 */
bool runAllTests() {
    bool testPassed = true;
    testPassed &= testZeroMatrix();
    testPassed &= testZeroMatrixFloat();
    testPassed &= testZeroMatrixDouble();
    testPassed &= testOnesMatrix();
    testPassed &= testThreesMatrix();
    testPassed &= testOnesMatrixSizeZero();
    testPassed &= testIdentityMatrix();
    testPassed &= testIdentityMatrixSizeZero();
    testPassed &= testMultiplication();
    testPassed &= testMultiplicationFloat();
    testPassed &= testMultiplicationDouble();
    testPassed &= testMultiplicationWithIdentity();
    testPassed &= testMultiplicationWithDifferentSizes();
    testPassed &= testMultiplicationWithIncompatibleSizes();
    testPassed &= testTranspose();
    testPassed &= testTransposeFloat();
    testPassed &= testTransposeDouble();

    if (testPassed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed!" << std::endl;
    }
    return testPassed;
}