#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

template <typename T>
class Matrix {
public:
    Matrix(int width, int height);
    ~Matrix();
    T index(int x, int y);
    void update(int x, int y, T value);
    void print();
    int width;
    int height;
private:
    T* data;
};


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

template <typename T>
void Matrix<T>::print(){
    for (int i = 0; i < this->height; i++){
        for (int j = 0; j < this->width; j++){
            std::cout << this->index(j, i) << " ";
        }
        std::cout << std::endl;
    }
}

#endif // MATRIX_H
