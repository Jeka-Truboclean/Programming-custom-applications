#include <iostream>
#include <vector>

using namespace std;

void addRow(vector<vector<int>>& matrix, const vector<int>& row, size_t position) {
    if (position <= matrix.size()) {
        matrix.insert(matrix.begin() + position, row);
    }
    else {
        cerr << "Error: Position out of range." << endl;
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

void removeRow(vector<vector<int>>& matrix, size_t index) {
    if (index < matrix.size()) {
        matrix.erase(matrix.begin() + index);
    }
    else {
        cerr << "Error: Index out of range." << endl;
    }
}

int main() {
    //No1
    vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    vector<int> newRow = { 10, 11, 12 };
    size_t position = 1;

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    addRow(matrix, newRow, position);

    cout << "Matrix after adding new row:" << endl;
    printMatrix(matrix);

    //No2
    matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    size_t index = 1;

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    removeRow(matrix, index);

    cout << "Matrix after removing row:" << endl;
    printMatrix(matrix);
    return 0;
}
