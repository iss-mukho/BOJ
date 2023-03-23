#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    if (N != 1) {
        int i = 2;
        while (N > 1) {
            if (N % i == 0) {
                cout << i << '\n';
                N /= i;
            }
            else
                i++;
        }
    }
    return 0;
}