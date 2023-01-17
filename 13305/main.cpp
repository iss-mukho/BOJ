#include <iostream>
using namespace std;

typedef long long ll;
const int MAX = 1000;
int N;
ll oil, answer = 0, dist[MAX], city[MAX + 1]; // dist->거리, city->주유소 가격

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> N;
    for (int i = 0; i < N - 1; i++)
        cin >> dist[i];

    for (int i = 0; i < N; i++)
        cin >> city[i];

    // 처리
    oil = city[0];
    for (int i = 0; i < N - 1; i++) {
        if (oil > city[i])
            oil = city[i];
        answer += dist[i] * oil;
    }

    // 출력
    cout << answer << '\n';

    return 0;
}