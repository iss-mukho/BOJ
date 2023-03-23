#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int x, y, z;
    while (true) {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0)
            break;
        int a, b, c;
        if (x > y) {
            if (x > z) {
                a = pow(x, 2);
                b = pow(y, 2);
                c = pow(z, 2);
            }
            else {
                a = pow(z, 2);
                b = pow(x, 2);
                c = pow(y, 2);
            }
        }
        else {
            if (y > z) {
                a = pow(y, 2);
                b = pow(x, 2);
                c = pow(z, 2);
            }
            else {
                a = pow(z, 2);
                b = pow(x, 2);
                c = pow(y, 2);
            }
        }
        if (a == b + c)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }
    return 0;
}