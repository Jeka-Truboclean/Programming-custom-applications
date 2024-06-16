#include <iostream>
#include <vector>

using namespace std;

void removeColumn(vector<vector<int>>& matrix, size_t index) {
    if (!matrix.empty() && index < matrix[0].size()) {
        for (auto& row : matrix) {
            row.erase(row.begin() + index);
        }
    }
    else {
        cerr << "Error: Index out of range." << endl;
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void shiftRows(vector<vector<int>>& matrix, int shifts) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();
    shifts = shifts % rows;
    if (shifts < 0) shifts += rows;

    vector<vector<int>> temp(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        temp[(i + shifts) % rows] = matrix[i];
    }
    matrix = temp;
}

void shiftColumns(vector<vector<int>>& matrix, int shifts) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();
    shifts = shifts % cols;
    if (shifts < 0) shifts += cols;

    vector<vector<int>> temp(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[i][(j + shifts) % cols] = matrix[i][j];
        }
    }
    matrix = temp;
}

int main() {
    //No 1
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    size_t index = 2;

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    removeColumn(matrix, index);

    cout << "Matrix after removing column:" << endl;
    printMatrix(matrix);

    //No2
    int M, N;
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;

    vector<vector<int>> matrix1(M, vector<int>(N));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix1[i][j];
        }
    }

    int rowShifts, colShifts;
    cout << "Enter the number of row shifts: ";
    cin >> rowShifts;
    cout << "Enter the number of column shifts: ";
    cin >> colShifts;

    shiftRows(matrix1, rowShifts);
    shiftColumns(matrix1, colShifts);

    cout << "Matrix after shifts:" << endl;
    printMatrix(matrix1);

    return 0;
}
