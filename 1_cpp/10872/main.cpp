#include <iostream>
using namespace std;
int Factorial(int n);
int main() {
    int N;
    cin >> N;
    cout << Factorial(N) << '\n';
    return 0;
}
int Factorial(int n) {
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;
    else
        return n * Factorial(n - 1);
}