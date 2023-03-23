// 백준 1339: 단어 수학(골드 IV), https://www.acmicpc.net/problem/1339
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<char, ll> pcl;
const int MAX = 10;

int N, len, p = 9, answer = 0;
string word, temp;
vector<string> words;
map<char, ll> point;
map<char, int> custom;

bool cmp(const pcl& a, const pcl& b) {
	if (a.second > b.second)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> word;
		words.push_back(word);

		len = word.length();
		// 처리 1: 알파벳 별로 점수 계산
		for (int j = 0; j < len; ++j) {
			if (point.find(word[j]) == point.end()) point.insert({word[j], 0});
			point[word[j]] += (ll)pow(10, len - j - 1);
		}
	}

	// 처리 2: 점수 순서로 알파벳에 숫자 배정
	vector<pcl> v(point.begin(), point.end()); // map -> vector
	sort(v.begin(), v.end(), cmp);
	for (auto& data : v) custom.insert({ data.first, p-- });

	// 처리 3: 계산
	for (auto& word : words) {
		temp = "";
		for (auto& w : word)
			temp += to_string(custom[w]);
		answer += stoi(temp);
	}

	// 출력
	cout << answer << '\n';

	return 0;
}