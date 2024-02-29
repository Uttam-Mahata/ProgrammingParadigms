#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

template <class T>
class Matrix {
private:
    vector<vector<T>> matrix;

public:
    // Constructors
    Matrix() {}
    Matrix(vector<vector<T>> m) : matrix(m) {}

    // Method to calculate the determinant of the matrix
    T Determinant() const;

    // Method to calculate the adjoint of the matrix
    Matrix<T> Adjoint() const;

    // Method to calculate the inverse of the matrix
    Matrix<T> Inverse() const;

    // Method to calculate the transpose of the matrix
    Matrix<T> Transpose() const;

    // Method to create a submatrix based on user's choice
    Matrix<T> CreateSubMatrix(size_t row, size_t col) const;

    // Method to display the matrix
    void display() const;
};

template <class T>
T Matrix<T>::Determinant() const {
    if (matrix.size() != matrix[0].size())
        throw invalid_argument("Matrix must be square.");

    size_t size = matrix.size();
    if (size == 1)
        return matrix[0][0];

    T det = 0;
    int sign = 1;
    for (size_t i = 0; i < size; ++i) {
        Matrix<T> minor = CreateSubMatrix(0, i);
        T minorDeterminant = minor.Determinant();
        det += sign * matrix[0][i] * minorDeterminant;
        sign = -sign;
    }
    return det;
}

template <class T>
Matrix<T> Matrix<T>::Adjoint() const {
    if (matrix.size() != matrix[0].size())
        throw invalid_argument("Matrix must be square.");

    size_t size = matrix.size();
    vector<vector<T>> adjoint(size, vector<T>(size));

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            Matrix<T> minor = CreateSubMatrix(i, j);
            T minorDeterminant = minor.Determinant();
            adjoint[j][i] = pow(-1, i + j) * minorDeterminant;
        }
    }

    return Matrix<T>(adjoint);
}

template <class T>
Matrix<T> Matrix<T>::Inverse() const {
    T det = Determinant();
    if (det == 0)
        throw invalid_argument("Matrix is not invertible.");

    Matrix<T> adjointMatrix = Adjoint();

    // Divide each element of adjoint matrix by determinant to get inverse
    size_t size = matrix.size();
    vector<vector<T>> inverse(size, vector<T>(size));
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            inverse[i][j] = adjointMatrix.matrix[i][j] / det;
        }
    }

    return Matrix<T>(inverse);
}

template <class T>
Matrix<T> Matrix<T>::Transpose() const {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    vector<vector<T>> transposed(cols, vector<T>(rows));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return Matrix<T>(transposed);
}

template <class T>
Matrix<T> Matrix<T>::CreateSubMatrix(size_t row, size_t col) const {
    if (row >= matrix.size() || col >= matrix[0].size())
        throw out_of_range("Invalid row or column index.");

    size_t size = matrix.size();
    vector<vector<T>> submatrix(size - 1, vector<T>(size - 1));

    for (size_t i = 0, r = 0; i < size; ++i) {
        if (i == row) continue;
        for (size_t j = 0, c = 0; j < size; ++j) {
            if (j == col) continue;
            submatrix[r][c] = matrix[i][j];
            ++c;
        }
        ++r;
    }

    return Matrix<T>(submatrix);
}

template <class T>
void Matrix<T>::display() const {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    vector<vector<double>> m1(rows, vector<double>(cols));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> m1[i][j];
        }
    }

    Matrix<double> m(m1);
    try {
        Matrix<double> inverse = m.Inverse();
        cout << "Inverse of the matrix:" << endl;
        inverse.display();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Transpose of the matrix:" << endl;
    m.Transpose().display();

    cout << "Enter row and column indices for submatrix:" << endl;
    size_t row, col;
    cin >> row >> col;
    try {
        Matrix<double> submatrix = m.CreateSubMatrix(row, col);
        cout << "Submatrix at (" << row << ", " << col << "):" << endl;
        submatrix.display();
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
