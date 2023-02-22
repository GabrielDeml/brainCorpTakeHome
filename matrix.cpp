#include "matrix.h"

#include <stdexcept>

template <typename T>
Matrix<T>::Matrix(int width, int height) {
    if (width < 0 || height < 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }
    this->width = width;
    this->height = height;
    this->data = new T[width * height];
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] this->data;
}

template <typename T>
T Matrix<T>::index(int x, int y) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        throw std::out_of_range("Matrix index out of range");
    }
    return this->data[x + y * this->width];
}

template <typename T>
void Matrix<T>::update(int x, int y, T value) {
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        throw std::out_of_range("Matrix index out of range");
    }
    this->data[x + y * this->width] = value;
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
