#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    // No 1
    const char* innFileN1 = "INN.txt";
    const char* outFileN1 = "OUT.txt";
    FILE* innFile1 = fopen(innFileN1, "r");
    FILE* outFile1 = fopen(outFileN1, "w");
    if (innFile1 != nullptr && outFile1 != nullptr) {
        char word[256];
        while (fscanf(innFile1, "%s", word) != EOF) {
            if (strlen(word) >= 7) {
                fprintf(outFile1, "%s", word);
            }
        }
        fclose(outFile1);
        fclose(innFile1);
    }
    else 
    {
        cout << "ERROR!!!";
    }
    // No 2
    const char* innFileN2 = "in.txt";
    const char* outFileN2 = "out.txt";
    FILE* innFile2 = fopen(innFileN2, "r");
    FILE* outFile2 = fopen(outFileN2, "w");
    if (innFile2 != nullptr && outFile2 != nullptr) {
        char line[256];
        while (fgets(line, sizeof(line), innFile2)) {
            fputs(line, outFile2);
        }
        fclose(outFile2);
        fclose(innFile2);
    }
    else {
        cout << "ERROR!!!";
    }
    // Extra
    const char* innFileN3 = "in.txt";
    const char* outFileN3 = "out.txt";
    FILE* innFile3 = fopen(innFileN3, "r");
    FILE* outFile3 = fopen(outFileN3, "w");
    if (innFile3 != nullptr && outFile3 != nullptr) {
        const int maxLineSize = 256;
        char lines[maxLineSize][maxLineSize];
        int lineCount = 0;
        while (fgets(lines[lineCount], maxLineSize, innFile3)) {
            lineCount++;
        }
        for (int i = lineCount - 1; i >= 0; i--) {
            fputs(lines[i], outFile3);
        }
        fclose(outFile3);
        fclose(innFile3);
    }
    else {
        cout << "ERROR!!!";
    }
    return 0;
}