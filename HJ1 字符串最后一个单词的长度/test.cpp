#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    string word;
    while (getline(cin, word)) { // ע�� while ������ case
        size_t pos = word.rfind(' ');
        cout << word.size() - 1 - pos << endl;
    }
}