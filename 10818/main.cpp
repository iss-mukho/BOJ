#include <iostream>

using namespace std;

int main() {
    int N;
    int ary[1000000];

    cin >> N;
    if (N < -1000000 || N>1000000)
        return 0;

    for (int i = 0; i < N; i++) {
        cin >> ary[i];
        if (ary[i] < -1000000 || ary[i]>1000000)
            return 0;
    }

    int min = ary[0], max = ary[0];

    for (int i = 0; i < N; i++) {
        if (min > ary[i])
            min = ary[i];
        if (max < ary[i])
            max = ary[i];
    }

    cout << min << ' ' << max << endl;

    return 0;
}