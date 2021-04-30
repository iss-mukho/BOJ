#include <iostream>
using namespace std;
int main() {
    int N, i, j;
    cin >> N;
    for (i = 0; i < N; ++i) {
        for (j = N - 1 - i; j > 0; --j)
            cout << ' ';
        for (j = 0; j < i * 2 + 1; ++j)
            cout << '*';
        cout << '\n';
    }
    for (i = N - 2; i >= 0; --i) {
        for (j = N - 1; j > i; --j)
            cout << ' ';
        for (j = 0; j < i * 2 + 1; ++j)
            cout << '*';
        cout << '\n';
    }
    return 0;
}