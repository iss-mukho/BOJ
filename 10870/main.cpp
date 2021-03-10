#include <iostream>
using namespace std;
int Fibo(int n);
int main() {
    int x;
    cin >> x;
    cout << Fibo(x) << '\n';
    return 0;
}
int Fibo(int n) {
    if (n <= 1)
        return n;
    else
        return Fibo(n - 2) + Fibo(n - 1);
}