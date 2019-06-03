#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    while (!s1.isEmpty()) {
        cout << s1.pop() << "\t";
    }
    cout << endl;
    Stack<double> s2;
    s2.push(5.0);
    s2.push(4.0);
    s2.push(3.0);
    s2.push(2.0);
    s2.push(1.0);
    while (!s2.isEmpty()) {
        cout << s2.pop() << "\t";
    }
    cout << endl;
    Stack<char> s3;
    s3.push('1');
    s3.push('2');
    s3.push('3');
    s3.push('4');
    s3.push('5');
    while (!s3.isEmpty()) {
        cout << s3.pop() << "\t";
    }
}