#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;
    int y = 1;
    for (int i = 1;; i++) {
        int x = y;
        y += i; // +1, +2, +3, +4, ...
        if (x <= X && X < y) { // x <= N < y
            int a = i - X % x;
            int b = i + 1 - a;
            /*
                odd : / 1,2,3,...
                even : 1,2,3,... /
            */
            if (i % 2 == 1)
                cout << a << "/" << b << '\n';
            else
                cout << b << "/" << a << '\n';
            break;
        }
    }
    return 0;
}