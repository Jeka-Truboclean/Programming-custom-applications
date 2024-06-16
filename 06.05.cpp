#include <iostream>
#include <string>
using namespace std;

string hexxx(string hex) {
    string bin = "";
    for (int i = 0; i < hex.length(); i++) {
        int dec = 0;
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec = hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec = hex[i] - 'A' + 10;
        }
        string temp = "";
        while (dec > 0) {
            temp += to_string(dec % 2);
            dec /= 2;
        }
        while (temp.length() < 4) {
            temp += '0';
        }
        for (int j = temp.length() - 1; j >= 0; j--) {
            bin += temp[j];
        }
    }
    return bin;
}

int main() {
    // No 1
    string hex;
    cout << "Enter a hexadecimal number: ";
    cin >> hex;
    string bin = hexxx(hex);
    cout << "Hexadecimal: " << hex << endl;
    cout << "Binary: " << bin << endl;
    // No 2
    int num = 45;
    int bit2 = (num >> 1) & 1;
    int bit4 = (num >> 3) & 1;
    cout << "2nd bit from the right: " << bit2 << endl;
    cout << "4th bit from the right: " << bit4 << endl;
    return 0;
}