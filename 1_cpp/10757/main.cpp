#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    string A, B;
    cin >> A >> B;
    stack<int> a;
    stack<int> b;
    stack<int> result;
    for (int i = 0; i < A.size(); i++)
        a.push(A[i] - '0');
    for (int i = 0; i < B.size(); i++)
        b.push(B[i] - '0');
    int up = 0;
    while (a.size() > 0 || b.size() > 0) {
        int x, y;
        if (a.size() > 0) {
            x = a.top();
            a.pop();
        }
        else
            x = 0;
        if (b.size() > 0) {
            y = b.top();
            b.pop();
        }
        else
            y = 0;
        int sum = x + y + up;
        if (sum >= 10) {
            up = 1;
            sum -= 10;
        }
        else
            up = 0;
        result.push(sum);
    }
    if (up == 1)
        result.push(1);
    while (!result.empty()) {
        int temp = result.top();
        cout << temp;
        result.pop();
    }
    cout << '\n';
    return 0;
}