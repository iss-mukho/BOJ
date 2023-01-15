#include <iostream>
#include <algorithm>
using namespace std;
int N, numbers[100001], answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    sort(numbers, numbers + N);

    for (int k = 1; k <= N; k++)
        answer = max(answer, numbers[N - k] * k);

    cout << answer << '\n';

    return 0;
}