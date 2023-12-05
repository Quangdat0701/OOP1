#include <iostream>


class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    
    ~Matrix() {
        
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    
    Matrix operator+(const Matrix& other) const {
        
        log("Performing matrix addition");

        
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    
    Matrix operator-(const Matrix& other) const {
        
        log("Performing matrix subtraction");

        
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    
    Matrix operator*(const Matrix& other) const {
        log("Performing matrix multiplication");

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator/(const Matrix& other) const {
        log("Performing matrix division");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return result;
    }

    void log(const std::string& message) const {
        std::cout << "[LOG] " << message << std::endl;
    }

    void inputMatrix() {
        std::cout << "Enter matrix values:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Matrix[" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    
    void print() const {
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    
    Matrix matrix1(2, 2);
    matrix1.inputMatrix();

    Matrix matrix2(2, 2);
    matrix2.inputMatrix();

    (matrix1 + matrix2).print();
    (matrix1 - matrix2).print();
    (matrix1 * matrix2).print();
    (matrix1 / matrix2).print();

    return 0;
}
