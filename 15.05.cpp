#include <iostream>
#include <bitset>
using namespace std;

int multiplyy(int num, int pow) {
    return num << pow;
}

int main() {
    // No 1
    int num1 = 15; 
    int mask = 0b00010100;
    num1 = num1 | mask;
    cout << "Number in decimal form: " << num1 << endl;
    cout << "Number in hexadecimal: " << hex << num1 << endl;
    cout << "Binary number: " << bitset<8>(num1) << endl;
    // No 2
    int num2 = 5;
    int pow = 3;
    int result = multiplyy(num2, pow);
    cout << num2 << " multiplied by 2^" << pow << " = " << result << endl;
    // No 3
    int num3 = 147;
    cout << "Before the change: " << num3 << endl;
    num3 &= ~(3);
    cout << "After the change: " << num3 << endl;
    cout << "Modified number in 10th form: " << num3 << endl;
    cout << "Modified number in 16th form: " << hex << num3 << endl;
    cout << "Modified number in 2nd form: " << bitset<8>(num3) << endl;
    return 0;
}