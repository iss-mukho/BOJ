#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v;
    int M, N;
    int sum = 0, min = 0;
    cin >> M;
    cin >> N;
    for (int i = M; i <= N; i++) {
        if (i == 1)
            continue;
        bool check = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                check = false;
                break;
            }
            else
                continue;
        }
        if (check)
            v.push_back(i);
    }
    if (v.size() == 0)
        cout << -1 << '\n';
    else {
        for (int i = 0; i < v.size(); i++)
            sum += v[i];
        if (v.size() > 0)
            min = *min_element(v.begin(), v.end());
        cout << sum << ' ' << min << '\n';
    }
    return 0;
}