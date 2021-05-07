#include <iostream>
using namespace std;
int main() {
    cout.tie(NULL);
    int N, i, j, r, a;
    cin >> N;
    r = N * 2;
    for (i = 0; i < r; ++i) {
        if (i % 2 == 0) {
            if (N % 2 == 1)
                a = N / 2 + 1;
            else
                a = N / 2;
            for (j = 0; j < a; ++j)
                cout << "* ";
            cout << '\n';
        }
        else {
            if (N % 2 == 1)
                a -= 1;
            for (j = 0; j < a; ++j)
                cout << " *";
            cout << '\n';
        }
    }
    return 0;
}