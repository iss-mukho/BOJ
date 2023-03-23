#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;

        if ((0 < A && A < 10) && (0 < B && B < 10)) {
            cout << "Case #" << i + 1 << ": " << A + B << endl;
        }
    }

    return 0;
}