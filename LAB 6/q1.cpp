#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char* arr;
    int top;
    int cap;

public:
    Stack(int n) {
        arr = new char[n];
        cap = n;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(char c) {
        if (top >= cap - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = c;
    }
    char pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }
    bool isEmpty() {
        return top < 0;
    }
};
bool isPalindrome(string str) {
    int len = str.length();
    Stack s(len);
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != s.pop()) {
            return false;
        }
    }

    return true;
}
int main() {
    string word = "BORROWROB";
    for (int i = 0; i < word.length(); i++) {
        cout << word[i];
    }
    cout << endl;
    if (isPalindrome(word)) {
        cout  << " it is a palindrome" << endl;
    } else {
        cout  << " not a palindrome." << endl;
    }

    return 0;
}
