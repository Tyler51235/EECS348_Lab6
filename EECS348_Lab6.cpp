#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 10;

// Function to read matrix data from file
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size, std::ifstream& file) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
}

// Function to print matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to update an element of a matrix
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int value, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = value;
    } else {
        std::cerr << "Error: Invalid row or column." << std::endl;
    }
}

// Function to find max value of a matrix
int maxValue(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose a matrix
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
}

int main() {
    int size;
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];


    std::ifstream file("matrix_input.txt");
    if (file.is_open()) {
        file >> size; // Read the size of the matrices
        readMatrix(matrix1, size, file); // Read the first matrix
        readMatrix(matrix2, size, file); // Read the second matrix
        file.close();

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(matrix2, size);

    std::cout << "\nAddition Result:" << std::endl;
    addMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    std::cout << "\nMultiplication Result:" << std::endl;
    multiplyMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    std::cout << "\nSubtraction Result:" << std::endl;
    subtractMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    std::cout << "\nUpdating Element (1, 1) of Matrix 1 to 99:" << std::endl;
    updateElement(matrix1, 1, 1, 99, size);
    printMatrix(matrix1, size);

    std::cout << "\nMax Value of Matrix 1: " << maxValue(matrix1, size) << std::endl;

    std::cout << "\nTranspose of Matrix 1:" << std::endl;
    transposeMatrix(matrix1, result, size);
    printMatrix(result, size);

    return 0;
}
}