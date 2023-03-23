#include <iostream>
using namespace std;

int main() {
    int T, k, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k;
        cin >> n;

        int apt[15][14]; // ¾ÆÆÄÆ® 0Ãþ~14Ãþ, 14È£½Ç
        for (int i = 0; i < n; i++)
            apt[0][i] = i + 1;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                int temp = 0;
                for (int l = 0; l <= j; l++)
                    temp += apt[i][l];
                apt[i + 1][j] = temp;
            }
        }
        cout << apt[k][n - 1] << '\n';
    }
    return 0;
}