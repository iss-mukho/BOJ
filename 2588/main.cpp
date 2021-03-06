#include <iostream>

using namespace std;

int main() {
    int A, B;
    int B1, B2, B3;
    int num3, num4, num5, num6;
    cin >> A >> B;

    B1 = B % 10;
    B2 = B % 100 / 10;
    B3 = B % 1000 / 100;

    num3 = A * B1;
    num4 = A * B2;
    num5 = A * B3;
    num6 = A * B;

    cout << num3 << endl << num4 << endl << num5 << endl << num6 << endl;

    return 0;
}