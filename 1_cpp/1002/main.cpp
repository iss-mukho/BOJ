#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double length = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        double max = r1 > r2 ? r1 : r2;
        double min = r1 < r2 ? r1 : r2;
        if (length == 0) // 좌표가 같음
            if (r1 != r2) // 길이가 다르면(서로 접하지 않음)
                cout << 0 << '\n';
            else // 좌표도 같고 길이도 같으면
                cout << -1 << '\n';
        else { // 좌표가 다름
            if (r1 + r2 > length) {
                if (max > length + min) // 한 원이 다른 원 밖에 있고, 서로 접하지 않음
                    cout << 0 << '\n';
                else if (max == length + min) // 한 원이 다른 원 안에 있고, 내접
                    cout << 1 << '\n';
                else // 두 점에서 접함
                    cout << 2 << '\n';
            }
            else if (r1 + r2 == length) // 한 원이 다른 원 밖에 있으며, 외접
                cout << 1 << '\n';
            else // 한 원이 다른 원 밖에 있으며, 두 원이 접하지 않음
                cout << 0 << '\n';
        }
    }
    return 0;
}