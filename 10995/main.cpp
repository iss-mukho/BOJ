#include <iostream>
using namespace std;
int main() {
    cout.tie(NULL);
    int N, i, j;
    cin >> N;
    for (i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (j = 0; j < N; ++j)
                cout << "* ";
            cout << '\n';
        }
        else {
            for (j = 0; j < N; ++j)
                cout << " *";
            cout << '\n';
        }
    }
    return 0;
}