#include <iostream>
using namespace std;

void decc(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

void binnar(char binaryNum[], char hexNum[]) {
    int i = 0;
    int num = 0;
    int len = 0;
    while (binaryNum[len] != '\0') {
        len++;
    }
    int j = 0;
    while (i < len) {
        num = 0;
        for (int k = 0; k < 4 && i < len; k++) {
            num = num * 2 + (binaryNum[i] - '0');
            i++;
        }
        if (num <= 9) {
            hexNum[j] = char(num + 48);
        }
        else {
            hexNum[j] = char(num + 55);
        }
        j++;
    }
    hexNum[j] = '\0';
}

int main() {
    // No 1
    int decNumm;
    cout << "Enter a decimal number: ";
    cin >> decNumm;
    cout << "Binary form: ";
    decc(decNumm);
    cout << endl;
    // No 2
    char binaryNumber[100];
    char hexNumber[100];
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    binnar(binaryNumber, hexNumber);
    cout << "16-character form: " << hexNumber << endl;
    return 0;
}