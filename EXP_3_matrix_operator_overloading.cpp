#include <iostream>
#include <cassert>
using namespace std;
class Matrix
{
private:
    int data[2][2];
public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }
    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }
    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
        return result;
    }
    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";

            out << endl;
        }
        return out;
    }
};
int main()
{
    int x[4], y[4];
    cout << "Enter the 4 elements of Matrix A (row by row): ";
    for (int i = 0; i < 4; i++)
        cin >> x[i];
    cout << "Enter the 4 elements of Matrix B (row by row): ";
    for (int i = 0; i < 4; i++)
        cin >> y[i];
    Matrix A(x[0], x[1], x[2], x[3]);
    Matrix B(y[0], y[1], y[2], y[3]);
    Matrix sum = A + B;
    Matrix product = A * B;
    // Unit Tests
    assert(sum[0][0] == x[0] + y[0]);
    assert(sum[1][1] == x[3] + y[3]);
    assert(product[0][0] == x[0] * y[0] + x[1] * y[2]);
    assert(product[0][1] == x[0] * y[1] + x[1] * y[3]);
    assert(product[1][0] == x[2] * y[0] + x[3] * y[2]);
    assert(product[1][1] == x[2] * y[1] + x[3] * y[3]);
    cout << "Matrix A:" << endl;
    cout << A;
    cout << "Matrix B:" << endl;
    cout << B;

    cout << "Addition of Matrices:" << endl;
    cout << sum;
    cout << "Multiplication of Matrices:" << endl;
    cout << product;
    cout << "All unit tests passed successfully." << endl;
    return 0;
}