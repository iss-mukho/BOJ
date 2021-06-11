#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
// 정렬함수 선언
bool cmp(pair<string, int> a, pair<string, int> b);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	pair<string, int> input[100];
	string S;
	int M, i, score = 0;
	
	// 입력
	cin >> S;
	cin >> M;
	for (i = 0; i < M; ++i)
		cin >> input[i].first >> input[i].second;
	sort(input, input + M, cmp);
	
	// 알고리즘
	for (i = 0; i < M; ++i) {
		if (input[i].second <= input[i].first.length())
			continue;
		while (true) {
			if (S.find(input[i].first) != -1) {
				S.erase(S.find(input[i].first), input[i].first.length());
				score += input[i].second;
			}
			else
				break;
		}
	}
	score += S.length();

	// 출력
	cout << score << '\n';
	return 0;
}
// 정렬함수 정의
bool cmp(pair<string, int> a, pair<string, int> b) {
	double as = a.second / a.first.length();
	double bs = b.second / b.first.length();
	if (as > bs)
		return true;
	else if (as == bs) {
		if (a.second >= b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}