#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

template <typename T>
class Matrix {
public:
    // Constructor that initializes the matrix with the given dimensions
    Matrix(int width, int height);

    // Destructor to free the memory allocated for the matrix
    ~Matrix();

    // Returns the value of the element at the specified indices
    T index(int x, int y) const;

    // Updates the value of the element at the specified indices
    void update(int x, int y, T value);

    // Prints the contents of the matrix to the console
    void print();

    // Public member variables for the width and height of the matrix
    int width;
    int height;

private:
    // Pointer to the dynamically allocated array of matrix elements
    T* data;
};

/**
 * @brief Construct a new Matrix< T>:: Matrix object
 * 
 * @tparam T Matrix type
 * @param width Width of the matrix 
 * @param height Height of the matrix
 */
template <typename T>
Matrix<T>::Matrix(int width, int height) {
    // Check that the dimensions are positive
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive and non zero");
    }

    // Store the dimensions
    this->width = width;
    this->height = height;

    // Allocate memory for the matrix elements
    this->data = new T[width * height]();
}

/**
 * @brief Destroy the Matrix< T>:: Matrix object
 * 
 * @tparam T Matrix type
 */
template <typename T>
Matrix<T>::~Matrix() {
    // Free the memory allocated for the matrix elements
    delete[] this->data;
}

/**
 * @brief 
 * 
 * @tparam T Matrix type
 * @param x X location of the point
 * @param y Y location of the point
 * @return T Value a the specified point 
 */
template <typename T>
T Matrix<T>::index(int x, int y) const {
    // Check that the indices are within the bounds of the matrix
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        throw std::out_of_range("Matrix index out of range");
    }

    // Calculate the index into the matrix elements array and return the value
    return this->data[x + y * this->width];
}

/**
 * @brief 
 * 
 * @tparam T Matrix Type
 * @param x X location of the point
 * @param y Y location of the point
 * @param value Value to update to
 */
template <typename T>
void Matrix<T>::update(int x, int y, T value) {
    // Check that the indices are within the bounds of the matrix
    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        throw std::out_of_range("Matrix index out of range");
    }

    // Calculate the index into the matrix elements array and update the value
    this->data[x + y * this->width] = value;
}

/**
 * @brief 
 * 
 * @tparam T Matrix Type
 */
template <typename T>
void Matrix<T>::print() {
    // Loop through the rows of the matrix
    for (int i = 0; i < this->height; i++){
        // Loop through the columns of the matrix
        for (int j = 0; j < this->width; j++){
            // Print the value of the current element
            std::cout << this->index(j, i) << " ";
        }

        // Start a new line after each row
        std::cout << std::endl;
    }
}

#endif // MATRIX_H