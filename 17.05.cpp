#include <iostream>
using namespace std;

#define SUM(a, b, c) ((a) + (b) + (c))
#define SUMMM(n) ((n) * ((n) + 1) / 2)
#define ARR(arr) (sizeof(arr) / sizeof(arr[0]))
#define PRINT_VAR(a) cout << #a << " = " << a << " (" << typeid(a).name() << ")";

int main() {
    // No 1
    int aa = 1, bb = 2, cc = 3;
    int sum = SUM(aa, bb, cc);
    cout << "Sum: " << aa << " + " << bb << " + " << cc << " = " << sum << endl;
    // No 2
    int nn = 33;
    int summ = SUMMM(nn);
    cout << "Amount from 1 to " << nn << " = " << summ << endl;
    // No 3
    int arrr[] = { 13, 52, 47, 29, 83, 18, 33 };
    int size = ARR(arrr);
    cout << "Number of elements in the array: " << size << endl;
    // Extra
    char a = 'b';
    PRINT_VAR(a);
    return 0;
}