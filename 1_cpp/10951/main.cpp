#include <iostream>
using namespace std;

int main()
{
    int A, B;
    while (true) {
        cin >> A >> B;

        if (cin.eof())
            break;
        if ((A <= 0 || A >= 10) && (B <= 0 || B >= 10))
            return 0;
        cout << A + B << endl;
    }

    return 0;
}