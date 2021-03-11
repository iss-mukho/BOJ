#include <iostream>
using namespace std;
int main() {
    int check[1000001];
    fill_n(check, 1000001, 1);
    check[0] = 0;
    check[1] = 0;

    int M, N;
    cin >> M >> N;

    for (int i = 2; i <= N; i++) {
        if (check[i] == 0)
            continue;
        for (int j = 1; i * j <= N; j++)
            if (i != i * j)
                check[i * j] = 0;
    }
    for (int i = M; i <= N; i++)
        if (check[i] == 1)
            cout << i << '\n';

    return 0;
}