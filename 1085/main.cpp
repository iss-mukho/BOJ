#include <iostream>
using namespace std;
int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int minX = w - x > x - 0 ? x - 0 : w - x;
    int minY = h - y > y - 0 ? y - 0 : h - y;
    if (minX > minY)
        cout << minY << '\n';
    else
        cout << minX << '\n';
    return 0;
}