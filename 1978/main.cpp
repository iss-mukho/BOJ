#include <iostream>
using namespace std;
int main() {
    int check[1001];
    fill_n(check, 1001, 1);
    check[0] = 0;
    check[1] = 0;

    for (int i = 2; i <= 1000; i++) {
        if (check[i] == 0)
            continue;
        for (int j = 1; i * j <= 1000; j++)
            if (i != i * j)
                check[i * j] = 0;
    }

    int T, x, cnt = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x;
        if (check[x] == 1)
            cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
/*
#include <iostream>
using namespace std;
int main() {
    int T, x, cnt = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x;
        if (x < 2)
            continue;
        bool check = true;
        for (int j = 2; j < x; j++) {
            if (x % j == 0) {
                check = false;
                break;
            }
            else
                continue;
        }
        if (check)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
*/