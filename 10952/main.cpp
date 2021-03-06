#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int A, B;
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        if ((0 < A && A < 10) && (0 < B && B < 10)) {
            cout << A + B << endl;
        }
    }

    return 0;
}