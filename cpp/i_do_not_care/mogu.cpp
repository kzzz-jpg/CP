#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

const int MAX_SIZE = 20;
const double EPSILON = 1e-9;

typedef vector<vector<double>> Matrix;

// Function declarations
Matrix inputMatrix(int size);
Matrix addMatrix(const Matrix& A, const Matrix& B, int size);
Matrix subtractMatrix(const Matrix& A, const Matrix& B, int size);
Matrix multiplyMatrix(const Matrix& A, const Matrix& B, int size);
void printMatrix(const Matrix& mat, int size);
void printMatrix2(const Matrix& mat, int size);
bool inverseMatrix(Matrix& mat, int size, Matrix& inv);


int main(int argc, char* argv[]) {
    
   // string str1, str2;
   // str1 = argv[1]; str2 = argv[2];
   // ifstream cin(str1); ofstream cout(str2);
    
    int size;
    cin >> size;

    // Input matrices A and B
    Matrix A = inputMatrix(size);
    Matrix B = inputMatrix(size);

    // Matrix operations
    cout << "A + B:" << endl;
    printMatrix(addMatrix(A, B, size), size);
    cout << endl;

    cout << "A - B:" << endl;
    printMatrix(subtractMatrix(A, B, size), size);
    cout << endl;

    cout << "A * B:" << endl;
    printMatrix(multiplyMatrix(A, B, size), size);
    cout << endl;

    // Inverse of B
    Matrix B_inv(size, vector<double>(size, 0));
    bool invertible = inverseMatrix(B, size, B_inv);

    if (invertible) {
        cout << "A / B:" << endl;
        printMatrix2(multiplyMatrix(A, B_inv, size), size);
    } else {
        cout << "Matrix B can't be Inversed!!!!!" << endl;
    }

    return 0;
}

// Function definitions
Matrix inputMatrix(int size) {
    Matrix mat(size, vector<double>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> mat[i][j];
        }
    }
    return mat;
}

Matrix addMatrix(const Matrix& A, const Matrix& B, int size) {
    Matrix result(size, vector<double>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

Matrix subtractMatrix(const Matrix& A, const Matrix& B, int size) {
    Matrix result(size, vector<double>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrix(const Matrix& A, const Matrix& B, int size) {
    Matrix result(size, vector<double>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Matrix inverseMatrix(const Matrix& B, int size, bool& invertible);
bool inverseMatrix(Matrix& mat, int size, Matrix& inv) {
    // 初始化反矩陣為單位矩陣
    for (long i = 0; i < size; i++) {
        for (long j = 0; j < size; j++) {
            inv[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Gauss-Jordan 消去法
    for (long i = 0; i < size; i++) {
        long double maxElement = fabs(mat[i][i]);
        long maxRow = i;
        for (long k = i + 1; k < size; k++) {
            if (fabs(mat[k][i]) > maxElement) {
                maxElement = fabs(mat[k][i]);
                maxRow = k;
            }
        }
        if (maxElement < EPSILON) {
            return false; // 無法反轉矩陣（奇異矩陣）
        }

        // 交換行
        for (long k = 0; k < size; k++) {
            swap(mat[maxRow][k], mat[i][k]);
            swap(inv[maxRow][k], inv[i][k]);
        }

        // 將主對角線歸一化
        long double diagElement = mat[i][i];
        for (long k = 0; k < size; k++) {
            mat[i][k] /= diagElement;
            inv[i][k] /= diagElement;
        }

        // 消去其他行
        for (long k = 0; k < size; k++) {
            if (k != i) {
                long double factor = mat[k][i];
                for (long j = 0; j < size; j++) {
                    mat[k][j] -= factor * mat[i][j];
                    inv[k][j] -= factor * inv[i][j];
                }
            }
        }
    }

    return true;
}


void printMatrix(const Matrix& mat, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(20) << mat[i][j] << " ";
           //cout<<mat[i][j]<<' ';
        }
        cout << endl;
    }
}
void printMatrix2(const Matrix& mat, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(20) << fixed << setprecision(3) << mat[i][j] << " ";
        }
        cout << endl;
    }
}
