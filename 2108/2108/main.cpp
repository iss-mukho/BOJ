#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
int counting[8001] = {};
using namespace std;
int main() {
	int N, max_ = -4001, min_ = 4001, sum = 0, a;
	cin >> N;
	vector<int> number;
	for (int i = 0;i < N;i++) {
		cin >> a;
		number.push_back(a);
		++counting[number[i] + 4000]; // 0Àº counting[4000]
		sum += number[i];
	}
	int mode_cnt = 0;
	for (int i = 0;i < 8001;i++)
		if (counting[i] > mode_cnt)
			mode_cnt = counting[i];
	vector<int> mode_;
	for (int i = 0;i < 8001;i++)
		if (counting[i] == mode_cnt)
			mode_.push_back(i);
	int result;
	if (mode_.size() < 2)
		result = mode_[0]-4000;
	else
		result = mode_[1]-4000;
	for (int i = 0;i < N;i++) {
		max_ = max(max_, number[i]);
		min_ = min(min_, number[i]);
	}
	double avg = round((double)sum / (double)N);
	int mid = N / 2;
	sort(number.begin(), number.end());
	cout << avg << '\n';
	cout << number[mid] << '\n';
	cout << result << '\n';
	cout << max_ - min_ << '\n';
	return 0;
}