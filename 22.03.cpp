#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int countWords(const string& sentence) {
    istringstream stream(sentence);
    string word;
    int count = 0;

    while (stream >> word) {
        ++count;
    }

    return count;
}

void insertChar(string& str, size_t pos, char ch) {
    if (pos <= str.length()) {
        str.insert(pos, 1, ch);
    }
    else {
        cerr << "Error: out of string." << endl;
    }
}

char* myStrcat(char* dest, const char* src) {
    char* destPtr = dest;
    while (*destPtr != '\0') {
        ++destPtr;
    }
    while (*src != '\0') {
        *destPtr = *src;
        ++destPtr;
        ++src;
    }
    *destPtr = '\0';

    return dest;
}

int main() {
    //No 1
    string sentence = "   It's  example  of the  string  with   some  spaces.  ";
    int wordCount = countWords(sentence);
    cout << "Count: " << wordCount << endl;

    //No 2
    string str = "Temp string";
    size_t pos = 6;
    char ch = 'X';

    insertChar(str, pos, ch);
    cout << "New string: " << str << endl;

    //No3
    char dest[50] = "Hello, ";
    const char* src = "world!";

    myStrcat(dest, src);
    cout << "Result strcat: " << dest << endl;
    return 0;
}
