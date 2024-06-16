#include <iostream>
using namespace std;

union UNN {
    int num;
    char arr[4];
};

union UNNN {
    int myInt;
    bool myBool[4];
};

int countZeroBytes(int number) {
    int count = 0;
    unsigned char* p = (unsigned char*)&number;
    for (int i = 0; i < sizeof(number); i++) {
        if (*p++ == 0) {
            count++;
        }
    }
    return count;
}

void printByteInfo(int number) {
    unsigned char* p = (unsigned char*)&number;
    cout << "Byte information for an integer: " << number << endl;
    for (int i = 0; i < sizeof(number); i++) {
        if (*p++ == 0) {
            cout << "Byte " << i << " = zero " << endl;
        }
        else {
            cout << "Byte " << i << " != zero " << endl;
        }
    }
}

int main() {
    //No 1
    UNN u;
    cout << "Enter an integer: ";
    cin >> u.num;

    cout << "Number bytes in decimal form: ";
    for (int i = 0; i < 4; i++) {
        cout << static_cast<int>(u.arr[i]) << " ";
    }
    cout << endl;

    cout << "Bytes of a number in hexadecimal: ";
    for (int i = 0; i < 4; i++) {
        cout << hex << static_cast<int>(u.arr[i]) << " ";
    }
    cout << endl;

    //No 2
    UNNN UNNN;
    cout << "Enter an integer: ";
    cin >> UNNN.myInt;
    cout << "Entering " << UNNN.myInt << endl;
    int zeroBytes = countZeroBytes(UNNN.myInt);
    cout << "Zero bytes: " << zeroBytes << endl;
    printByteInfo(UNNN.myInt);
    return 0;
}
