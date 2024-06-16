#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include <string>
using namespace std;

void removeCharacters(string& str, size_t m, size_t n) {
    if (m <= n && n < str.size()) {
        str.erase(m, n - m + 1);
    }
    else {
        cerr << "Error: Invalid range." << endl;
    }
}

void findAllOccurrences(const string& str, char ch) {
    vector<int> positions;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ch) {
            positions.push_back(i + 1);
        }
    }

    cout << "Positions of character '" << ch << "': ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;
}

int findLastOccurrence(const string& str, char ch) {
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == ch) {
            return i + 1; 
        }
    }
    return -1; 
}

int myStrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

void fillArray(vector<vector<int>>& array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100;
        }
    }
}

void printArray(const vector<vector<int>>& array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //No 1
    string str1;
    size_t m, n;
    cout << "Enter the string: ";
    getline(cin, str1);
    cout << "Enter the start position (m): ";
    cin >> m;
    cout << "Enter the end position (n): ";
    cin >> n;

    removeCharacters(str1, m, n);
    cout << "Modified string: " << str1 << endl;

    //No 2
    string str2;
    char ch1;
    cout << "Enter the string: ";
    cin.ignore();
    getline(cin, str2);
    cout << "Enter the character to find: ";
    cin >> ch1;

    findAllOccurrences(str2, ch1);

    //No3
    string str3;
    char ch2;
    cout << "Enter the string: ";
    cin.ignore();
    getline(cin, str3);
    cout << "Enter the character to find: ";
    cin >> ch2;

    int position = findLastOccurrence(str3, ch2);
    if (position != -1) {
        cout << "Last occurrence of character '" << ch2 << "' is at position: " << position << endl;
    }
    else {
        cout << "Character '" << ch2 << "' not found in the string." << endl;
    }

    //No 4
    const char* str41 = "Hello";
    const char* str42 = "Hello";
    const char* str43 = "World";

    cout << "Comparing \"" << str41 << "\" and \"" << str42 << "\": " << myStrcmp(str41, str42) << endl;
    cout << "Comparing \"" << str41 << "\" and \"" << str43 << "\": " << myStrcmp(str41, str43) << endl;

    //No 5
    srand(time(0));
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> array1(rows, vector<int>(cols));
    vector<vector<int>> array2(rows, vector<int>(cols));
    vector<vector<int>> result(rows, vector<int>(cols));

    fillArray(array1, rows, cols);
    fillArray(array2, rows, cols);

    cout << "Array 1:" << endl;
    printArray(array1, rows, cols);

    cout << "Array 2:" << endl;
    printArray(array2, rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = array1[i][j] + array2[i][j];
        }
    }

    cout << "Result array:" << endl;
    printArray(result, rows, cols);
    return 0;
}