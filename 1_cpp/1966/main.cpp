// Made By Mukho
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
vector<pair<int, int>> input; // <중요도, 문서번호>
priority_queue<pair<int, int>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int TC, N, M, i, j, temp, cnt;
	// 입력
	cin >> TC;
	for (i = 0; i < TC; ++i) {
		cin >> N >> M;
		for (j = 0; j < N; ++j) {
			cin >> temp;
			input.push_back({ temp, j }); // <중요도, 문서번호>
			pq.push(input[j]);
		}
		cnt = 1;
		// 알고리즘
		while (true) {
			// 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면,
			if (input[0].first < pq.top().first) {
				pair<int, int> tp = input[0];
				// 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다.
				input.erase(input.begin());
				input.push_back(tp);
			}
			//  그렇지 않다면 바로 인쇄를 한다.
			else {
				// 출력
				if (input[0].second == M) {
					cout << cnt << '\n';
					cnt = 1; // 새 테스트케이스를 위한 초기화
					break;
				}
				// 실제로는 출력 순서가 필요하기 때문에 처리하는 부분
				else {
					input.erase(input.begin());
					pq.pop();
					++cnt;
				}
			}
		}
		// 새 테스트케이스를 위한 초기화
		input.clear();
		pq = priority_queue<pair<int, int>>();
	}
	return 0;
}