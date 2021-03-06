#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int A, B;
        cin >> A >> B;
        if ((A > 0 && A < 10) || (B > 0 && B < 10))
            cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << endl;
    }

    return 0;
}