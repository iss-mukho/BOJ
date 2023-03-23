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
        if (length == 0) // ��ǥ�� ����
            if (r1 != r2) // ���̰� �ٸ���(���� ������ ����)
                cout << 0 << '\n';
            else // ��ǥ�� ���� ���̵� ������
                cout << -1 << '\n';
        else { // ��ǥ�� �ٸ�
            if (r1 + r2 > length) {
                if (max > length + min) // �� ���� �ٸ� �� �ۿ� �ְ�, ���� ������ ����
                    cout << 0 << '\n';
                else if (max == length + min) // �� ���� �ٸ� �� �ȿ� �ְ�, ����
                    cout << 1 << '\n';
                else // �� ������ ����
                    cout << 2 << '\n';
            }
            else if (r1 + r2 == length) // �� ���� �ٸ� �� �ۿ� ������, ����
                cout << 1 << '\n';
            else // �� ���� �ٸ� �� �ۿ� ������, �� ���� ������ ����
                cout << 0 << '\n';
        }
    }
    return 0;
}