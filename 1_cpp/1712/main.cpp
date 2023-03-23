#include <iostream>
using namespace std;

int BEP(int a, int b, int c);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;
    cout << BEP(A, B, C) << '\n';

    return 0;
}

int BEP(int a, int b, int c) {
    if (b >= c)
        return -1;

    return (int)(a / (c - b)) + 1;
}