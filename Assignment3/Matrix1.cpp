#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

template <class T>
class Matrix
{
    vector<vector<T>> matrix;

public:

    Matrix() {}
    Matrix(vector<vector<T>> m) : matrix(m) {}
    void display();
    Matrix<T> Addition(Matrix<T> m);
    Matrix<T> Multiplication(Matrix<T> m);
    bool TestEqualMatrices(Matrix<T> m);
};

template <class T>
void Matrix<T>::display()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <class T>
Matrix<T> Matrix<T>::Addition(Matrix<T> m)
{
    vector<vector<T>> result;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<T> temp;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            temp.push_back(matrix[i][j] + m.matrix[i][j]);
        }
        result.push_back(temp);
    }
    return Matrix<T>(result);
}

template <class T>
Matrix<T> Matrix<T>::Multiplication(Matrix<T> m)
{
    vector<vector<T>> result;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<T> temp;
        for (int j = 0; j < m.matrix[0].size(); j++)
        {
            T sum = 0;
            for (int k = 0; k < matrix[i].size(); k++)
            {
                sum += matrix[i][k] * m.matrix[k][j];
            }
            temp.push_back(sum);
        }
        result.push_back(temp);
    }
    return Matrix<T>(result);
}

template <class T>
bool Matrix<T>::TestEqualMatrices(Matrix<T> m)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] != m.matrix[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
  //Take user input for matrix 1
    vector<vector<int>> m1;
    int r, c;
    cout << "Enter the number of rows and columns for matrix 1: ";
    cin >> r >> c;
    cout << "Enter the elements of matrix 1:" << endl;
    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        for (int j = 0; j < c; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        m1.push_back(temp);
    }
    Matrix<int> matrix1(m1);
    //Take user input for matrix 2
    vector<vector<int>> m2;
    cout << "Enter the number of rows and columns for matrix 2: ";
    cin >> r >> c;
    cout << "Enter the elements of matrix 2:" << endl;
    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        for (int j = 0; j < c; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        m2.push_back(temp);
    }
    Matrix<int> matrix2(m2);
    
    cout << "Matrix 1:" << endl;
    matrix1.display();
    cout << "Matrix 2:" << endl;
    matrix2.display();
    cout << "Addition:" << endl;
    matrix1.Addition(matrix2).display();
    cout << "Multiplication:" << endl;
    matrix1.Multiplication(matrix2).display();
    cout << "Test Equal Matrices:" << endl;
    cout << boolalpha << matrix1.TestEqualMatrices(matrix2) << endl;
    return 0;
}
