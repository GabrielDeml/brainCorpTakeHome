#ifndef LINALG_H
#define LINALG_H

#include "matrix.h"

template <typename T>
Matrix<T> add(const Matrix<T>& a, const Matrix<T>& b) {
    if (a.width != b.width || a.height != b.height) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    Matrix<T> result(a.width, a.height);
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            result.update(j, i, a.index(j, i) + b.index(j, i));
        }
    }
    return result;
}

template <typename T>
Matrix<T> subtract(const Matrix<T>& a, const Matrix<T>& b) {
    if (a.width != b.width || a.height != b.height) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    Matrix<T> result(a.width, a.height);
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            result.update(j, i, a.index(j, i) - b.index(j, i));
        }
    }
    return result;
}

template <typename T>
Matrix<T> multiply(const Matrix<T>& a, const Matrix<T>& b) {
    if (a.width != b.height) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    Matrix<T> result(b.width, a.height);
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < b.width; j++) {
            T sum = 0;
            for (int k = 0; k < a.width; k++) {
                sum += a.index(k, i) * b.index(j, k);
            }
            result.update(j, i, sum);
        }
    }
    return result;
}

template <typename T>
Matrix<T> transpose(const Matrix<T>& a) {
    Matrix<T> result(a.height, a.width);
    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            result.update(i, j, a.index(j, i));
        }
    }
    return result;
}

template <typename T>
bool isEqual(const Matrix<T>& a, const Matrix<T>& b) {
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


template <typename T>
Matrix<T> identity(int size) {
    Matrix<T> result(size, size);
    for (int i = 0; i < size; i++) {
        result.update(i, i, 1);
    }
    return result;
}

template <typename T>
Matrix<T> fillMatrix(int x, int y, T value) {
    Matrix<T> result(x, y);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            result.update(j, i, value);
        }
    }
    return result;
}
#endif // LINALG_H