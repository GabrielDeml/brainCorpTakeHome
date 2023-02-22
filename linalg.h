#ifndef LINALG_H
#define LINALG_H

#include "matrix.h"

/**

    @brief Adds two matrices and returns the result as a new matrix
    @tparam T The type of elements in the matrices
    @param a The first matrix to add
    @param b The second matrix to add
    @return Matrix<T> The result of adding the two matrices
*/
template <typename T>
Matrix<T> add(const Matrix<T> &a, const Matrix<T> &b) {
    // Check if matrix dimensions match
    if (a.width != b.width || a.height != b.height) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    // Create a new matrix to store the result
    Matrix<T> result(a.width, a.height);
    // Iterate over each element in the matrices and add them together
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            result.update(j, i, a.index(j, i) + b.index(j, i));
        }
    }
    // Return the resulting matrix
    return result;
}

/**
 * @brief Subtracts two matrices and returns the result as a new matrix
 *
 * @tparam T The type of elements in the matrices
 * @param a The matrix to subtract from
 * @param b The matrix to subtract
 * @return Matrix<T> The result of subtracting the two matrices
 */
template <typename T>
Matrix<T> subtract(const Matrix<T> &a, const Matrix<T> &b) {
    // Check if matrix dimensions match
    if (a.width != b.width || a.height != b.height) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    // Create a new matrix to store the result
    Matrix<T> result(a.width, a.height);
    // Iterate over each element in the matrices and subtract them
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            result.update(j, i, a.index(j, i) - b.index(j, i));
        }
    }
    // Return the resulting matrix
    return result;
}

/**
 * @brief Multiplies two matrices and returns the result as a new matrix
 *
 * @tparam T The type of elements in the matrices
 * @param a The first matrix to multiply
 * @param b The second matrix to multiply
 * @return Matrix<T> The resulting matrix
 */
template <typename T>
Matrix<T> multiply(const Matrix<T> &a, const Matrix<T> &b) {
    // Check if matrix dimensions match for multiplication
    if (a.width != b.height) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    // Create a new matrix to store the result with dimensions of (b.width, a.height)
    Matrix<T> result(b.width, a.height);
    // Iterate over each element in the resulting matrix
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < b.width; j++) {
            T sum = 0;
            // Iterate over each element in the row of matrix A and column of matrix B to compute dot product
            for (int k = 0; k < a.width; k++) {
                sum += a.index(k, i) * b.index(j, k);
            }
            // Update the result matrix with the computed dot product
            result.update(j, i, sum);
        }
    }
    // Return the resulting matrix
    return result;
}

/**
 * @brief Transposes a matrix and returns the result as a new matrix
 *
 * @tparam T The type of elements in the matrix
 * @param a The matrix to transpose
 * @return Matrix<T> The transposed matrix
 */
template <typename T>
Matrix<T> transpose(const Matrix<T> &a) {
    // Create a new matrix with dimensions swapped
    Matrix<T> result(a.height, a.width);
    // Iterate over each element in the original matrix and copy it to the transposed matrix
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            result.update(i, j, a.index(j, i));
        }
    }
    // Return the transposed matrix
    return result;
}

/**
 * @brief
 *
 * @tparam T
 * @param a
 * @param b
 * @return true
 * @return false
 */
template <typename T>
bool isEqual(const Matrix<T> &a, const Matrix<T> &b) {
    if (a.width != b.width || a.height != b.height) {
        return false;
    }
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            if (a.index(j, i) != b.index(j, i)) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Creates an identity matrix of given size and returns it as a new matrix
 *
 * @tparam T The type of elements in the matrix
 * @param size The size of the identity matrix to create
 * @return Matrix<T> The identity matrix of given size
 */
template <typename T>
Matrix<T> identity(int size) {
    // Create a new matrix with given size
    Matrix<T> result(size, size);
    // Iterate over the diagonal elements of the matrix and set them to 1
    for (int i = 0; i < size; i++) {
        result.update(i, i, 1);
    }
    // Return the identity matrix
    return result;
}

/**
 * @brief Creates a new matrix of given size and fills it with given value
 *
 * @tparam T The type of elements in the matrix
 * @param x The width of the matrix
 * @param y The height of the matrix
 * @param value The value to fill the matrix with
 * @return Matrix<T> The filled matrix of given size
 */
template <typename T>
Matrix<T> fillMatrix(int x, int y, T value) {
    // Create a new matrix with given size
    Matrix<T> result(x, y);
    // Iterate over all elements of the matrix and set them to given value
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            result.update(j, i, value);
        }
    }
    // Return the filled matrix
    return result;
}

#endif // LINALG_H