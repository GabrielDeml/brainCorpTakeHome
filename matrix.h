#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

template <typename T>
class Matrix {
public:
    Matrix(int width, int height);
    ~Matrix();
    T index(int x, int y);
    void update(int x, int y, T value);
private:
    int width;
    int height;
    T* data;
};

#endif // MATRIX_H
