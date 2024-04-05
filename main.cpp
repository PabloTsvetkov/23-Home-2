#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;
// Очистка консоли
void clearConsole() {
    system("cls");
}
// Основной класс матрицы
template<typename T> class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;

// Ввод матрицы с заданными размерами
    void inputDataWithSizes() {
        cout << "Enter all elements of matrix ( " << rows * cols << " elements ):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }
// Ввод матрицы без заданных размеров
     void inputDataNoSizes() {
        cout << "Enter number of rows:\n";
        cin >> rows;
        cout << "Enter number of columns:\n";
        cin >> cols;
        data = vector<vector<T>>(rows, vector<T>(cols));
        inputDataWithSizes();
    }
public:
// Конструктор для считывания матрицы без размеров
    Matrix() : rows(0), cols(0) {
    }
// Конструктор для считывания матрицы с размерами
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data = vector<vector<T>>(rows, vector<T>(cols));
    }
// Конструктор для считывания матрицы из файла
    Matrix(string fileName) {
        ifstream fileInput(fileName);
        fileInput >> rows >> cols;
        if (!fileInput.is_open()) {
            cout << "There is no such a file in that directory" << endl;
            throw invalid_argument(":/");
        }
        else {
            data = vector<vector<T>>(rows, vector<T>(cols));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    fileInput >> data[i][j];
                }
            }
        }
        fileInput.close();
    }
// Метод для считвания матрицы
    void inputMatrix() {
        if (rows == cols && rows == 0) {
            inputDataNoSizes();
        }
        else {
            inputDataWithSizes();
        }
        return ;
    }

// Вывод матрицы в файл
    void printMatrixToFile(string fileOutName) {
        ofstream fileOut(fileOutName);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                fileOut << data[i][j] << " ";
            }
            fileOut << "\n";
        }
        fileOut.close();
    }

// Вывод матрицы в консоль
    void printMatrixToConsole() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }

// Перегрузка <<>> для консоли
    friend ostream& operator<<(ostream& os, const Matrix &matrix) {
        for (auto row : matrix.data) {
            for (auto elem : row) {
                os << elem << " ";
            }
            os << "\n";
        }
        return os;
    }
    friend istream& operator>>(istream& is, Matrix &matrix) {
        if (matrix.rows == matrix.cols && matrix.rows == 0) {
            cout << "Enter number of rows:\n";
            is >> matrix.rows;
            cout << "Enter number of columns:\n";
            is >> matrix.cols;
            matrix.data = vector<vector<T>>(matrix.rows, vector<T>(matrix.cols));
        }
        cout << "Enter all elements of matrix ( " << matrix.rows * matrix.cols << " elements ):\n";
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }
// Перегрузка <<>> для файла
    friend ofstream& operator<<(ofstream& ofs, Matrix &matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                ofs << matrix.data[i][j] << " ";
            }
            ofs << "\n";
        }
    }
    friend ifstream& operator>>(ifstream& ifs, Matrix &matrix) {
        ifs >> matrix.rows >> matrix.cols;
        matrix.data = vector<vector<T>>(matrix.rows, vector<T>(matrix.cols));
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                ifs >> matrix.data[i][j];
            }
        }
    }




    ~Matrix() {
    }
};

int main() {
    //clearConsole();
/*
// Матрица с указанными размерами
    Matrix<int> A(2,2);
    A.printMatrixToConsole();
// Матрица без указанных размеров
    Matrix<int> B;
    B.printMatrixToConsole();
// Матрица для считывания из файла
    Matrix<int> C("matrixInput.txt");
    C.printMatrixToConsole();
    C.printMatrixToFile("matrixOutput.txt");
// Матрица считываемая из консоли с помощью >>
    Matrix<int> D;
    cin >> D;
    cout << D;

// Матрица и файлы и <<>>
    Matrix<int> E(2, 2);
    ofstream fileOut("matrixOutput.txt");
    ifstream fileIn("matrixInput.txt");
    if (fileIn.is_open() == false) {
        throw invalid_argument("File not found");
    }
    fileIn >> E;
    fileOut << E;

*/


    return 0;
}