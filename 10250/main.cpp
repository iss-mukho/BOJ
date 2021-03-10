#include <iostream>
using namespace std;
int main()
{
    int T, H, W, N;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> H >> W >> N;
        int cnt = 1;
        for (int j = 0; j < W; j++) {
            for (int i = 0; i < H; i++) {
                if (cnt == N) {
                    cout << (i + 1) * 100 + (j + 1) << '\n';
                    cnt = -1;
                    break;
                }
                else
                    cnt++;
            }
            if (cnt == -1)
                break;
        }
    }
    return 0;
}