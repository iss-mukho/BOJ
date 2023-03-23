#include <iostream>
using namespace std;
int N;
int num[12];
int oper[4];
int max_ = -1000000000, min_ = 1000000000;
void calc(int result, int idx);
int main() {
	int i;
	cin >> N;
	for (i = 0;i < N;++i)
		cin >> num[i];
	for (i = 0;i < 4;i++) // +, -, *, /
		cin >> oper[i];
	calc(num[0], 1);
	cout << max_ << '\n' << min_ << '\n';
	return 0;
}
void calc(int result, int idx) {
	int i;
	if (idx == N) {
		if (result > max_)
			max_ = result;
		if (result < min_)
			min_ = result;
		return;
	}
	for (i = 0;i < 4;++i) {
		if (oper[i] > 0) {
			--oper[i];
			if (i == 0)
				calc(result + num[idx], idx + 1);
			else if (i == 1)
				calc(result - num[idx], idx + 1);
			else if (i == 2)
				calc(result * num[idx], idx + 1);
			else
				calc(result / num[idx], idx + 1);
			++oper[i];
		}
	}
	return;
}