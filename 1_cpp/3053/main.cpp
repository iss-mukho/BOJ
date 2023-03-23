#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int R;
    cin >> R;
    cout << fixed;
    cout.precision(6);
    cout << pow(R, 2) * M_PI << '\n';
    cout << pow(R, 2) * 2 << '\n';
    return 0;
}