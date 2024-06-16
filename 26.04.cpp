#include <iostream>
using namespace std;

int binaryy(int binary[], int n) {
    int deccc = 0;
    int poww = n - 1;
    for (int i = 0; i < n; i++) {
        deccc += binary[i] * pow(2, poww);
        poww--;
    }
    return deccc;
}

int hexx(char hex[], int a) {
    int deccc = 0;
    int poo = a - 1;
    for (int i = 0; i < a; i++) {
        int degg = 0;
        if (hex[i] >= '0' && hex[i] <= '9') {
            degg = hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            degg = hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            degg = hex[i] - 'a' + 10;
        }
        deccc += degg * pow(16, poo);
        poo--;
    }
    return deccc;
}

int main() {
    // No 1
    int binary[] = { 0, 1, 1, 0 };
    int n = sizeof(binary) / sizeof(binary[0]);
    int decccc = binaryy(binary, n);
    cout << decccc << endl;
    // No 2
    char hex[] = { '4', 'C', 'E', 'D' };
    int a = sizeof(hex) / sizeof(hex[0]);
    int decc = hexx(hex, a);
    cout << decc << endl;
    return 0;
}