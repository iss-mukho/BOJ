// 백준 4344: 평균은 넘겠지(브론즈 I), https://www.acmicpc.net/problem/4344
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAX = 1001;

int C, N;
double student[MAX];

double customRound(double number) {
	int n = to_string(number).length() + 1;
	double result = number + pow(10, -n);
	return round(result * 1000) / 1000.0;
}

void output(int overCount) {
	cout << fixed;
	cout.precision(3);

	double answer = overCount / (double)N * 100;
	cout << customRound(answer) << "%\n";
}

void solve(double totalScore) {
	int overCount = 0;

	double avgScore = totalScore / (double)N;
	for (int n = 0; n < N; ++n)
		if (student[n] > avgScore) ++overCount;

	output(overCount);
}

void input() {
	cin >> C;

	for (int c = 0; c < C; ++c) {
		double totalScore = 0;

		cin >> N;
		for (int n = 0; n < N; ++n) {
			cin >> student[n];
			totalScore += student[n];
		}

		solve(totalScore);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	return 0;
}