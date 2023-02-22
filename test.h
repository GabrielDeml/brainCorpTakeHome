#ifndef TEST_H
#define TEST_H

#include "linalg.h"
#include "matrix.h"
#include <iostream>
#include <vector>

bool testZeroMatrix();
bool testZeroMatrixFloat();
bool testZeroMatrixDouble();
bool testOnesMatrix();
bool testThreesMatrix();
bool testOnesMatrixSizeZero();
bool testIdentityMatrix();
bool testIdentityMatrixSizeZero();
bool testMultiplication();
bool testMultiplicationFloat();
bool testMultiplicationDouble();
bool testMultiplicationWithIdentity();
bool testMultiplicationWithDifferentSizes();
bool testMultiplicationWithIncompatibleSizes();
bool testTranspose();
bool testTransposeFloat();
bool testTransposeDouble();
bool runAllTests();
#endif // TEST_H