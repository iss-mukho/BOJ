#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int x = 0;
    for (int i = 0;; i++) {
        x += i;
        if (N < 2 + 6 * x) {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}