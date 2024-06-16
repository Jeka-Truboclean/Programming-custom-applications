#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    int numbers[10];
    FILE* outputFile = fopen("numbers.txt", "w");
    if (!outputFile) {
        cout << "Error opening a file for writing";
        return 1;
    }
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; ++i) {
        cin >> numbers[i];
        fprintf(outputFile, "%d", numbers[i]);
    }
    fclose(outputFile);
    FILE* inputFile = fopen("numbers.txt", "r");
    if (!inputFile) {
        cout << "Error opening a file for reading";
        return 1;
    }
    int sum1 = 0;
    for (int i = 0; i < 5; ++i) {
        fscanf(inputFile, "%d", &numbers[i]);
        sum1 += numbers[i];
    }
    int sum2 = 0;
    for (int i = 5; i < 10; ++i) {
        fscanf(inputFile, "%d", &numbers[i]);
        sum2 += numbers[i];
    }
    fclose(inputFile);
    FILE* sumFile = fopen("sums.txt", "w");
    if (!sumFile) {
        cout << "Error opening a file for writing amounts";
        return 1;
    }
    fprintf(sumFile, "The sum of the first 5 numbers: %d", sum1);
    fprintf(sumFile, "The sum of the second 5 numbers: %d", sum2);
    fclose(sumFile);
    cout << "The sums of the numbers were successfully written to the sums.txt file";
    return 0;
}