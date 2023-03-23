#include <iostream>
using namespace std;
int main() {
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, i, j;
    cin >> N;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < i; ++j)
            cout << ' ';
        for (j = 0; j < N * 2 - i * 2 - 1; ++j)
            cout << '*';
        cout << '\n';
    }
    for (i = 1; i < N; ++i) {
        for (j = N - 1; j > i; --j)
            cout << ' ';
        for (j = 0; j < i * 2 + 1; ++j)
            cout << '*';
        cout << '\n';
    }
    return 0;
}