#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    string word;
    while (getline(cin, word)) { // 注意 while 处理多个 case
        size_t pos = word.rfind(' ');
        cout << word.size() - 1 - pos << endl;
    }
}