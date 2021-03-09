#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x, y, result;
        cin >> x >> y;
        int k = y - x;

        int before = 1;
        if (k <= 2)
            result = k;
        else {
            for (int i = 2;; i++) {
                if (k <= pow(i, 2) + i) {
                    if (k <= pow(i, 2)) {
                        result = i * 2 - 1;
                        break;
                    }
                    else {
                        result = i * 2;
                        break;
                    }
                }
            }
        }
        cout << result << '\n';
    }
    return 0;
}
