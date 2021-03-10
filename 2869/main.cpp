#include <iostream>
using namespace std;
int main()
{
    int A, B, V;
    cin >> A >> B >> V;
    if (double(V) / (double)A <= 1.0)
        cout << 1 << '\n';
    else
        if ((double(V - B) / double(A - B)) != (V - B) / (A - B))
            cout << (V - B) / (A - B) + 1 << '\n';
        else
            cout << (V - B) / (A - B) << '\n';
    return 0;
}