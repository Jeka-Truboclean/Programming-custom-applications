#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
using namespace std;

int countWordOccurrences(const string& text, const string& word) {
    int count = 0;
    size_t pos = text.find(word);
    while (pos != string::npos) {
        ++count;
        pos = text.find(word, pos + word.length());
    }
    return count;
}

int countSentences(const string& text) {
    int count = 0;
    for (char c : text) {
        if (c == '.' || c == '!' || c == '?') {
            ++count;
        }
    }
    return count;
}

pair<int, int> countDotsAndCommas(const string& text) {
    int dotCount = 0;
    int commaCount = 0;
    for (char c : text) {
        if (c == '.') {
            ++dotCount;
        }
        else if (c == ',') {
            ++commaCount;
        }
    }
    return make_pair(dotCount, commaCount);
}

string reverseText(const string& text) {
    string reversedText = text;
    reverse(reversedText.begin(), reversedText.end());
    return reversedText;
}

int main() {
    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    string word;
    cout << "Enter the word to count occurrences: ";
    cin >> word;

    int wordCount = countWordOccurrences(text, word);
    int sentenceCount = countSentences(text);
    pair<int, int> dotAndCommaCount = countDotsAndCommas(text);
    int dotCount = dotAndCommaCount.first;
    int commaCount = dotAndCommaCount.second;
    string reversedText = reverseText(text);

    cout << "Occurrences of the word \"" << word << "\": " << wordCount << endl;
    cout << "Number of sentences: " << sentenceCount << endl;
    cout << "Number of dots: " << dotCount << endl;
    cout << "Number of commas: " << commaCount << endl;
    cout << "Reversed text: " << reversedText << endl;

    return 0;
}
