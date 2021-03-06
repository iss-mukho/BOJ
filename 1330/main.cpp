#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A >= -10000 and A <= 10000 and B >= -10000 and B <= 10000) {
        if (A > B)
            cout << ">" << endl;
        else if (A < B)
            cout << "<" << endl;
        else
            cout << "==" << endl;
    }

    return 0;
}