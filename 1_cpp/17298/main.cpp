#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> input;
stack<int> index;
int main() {
	int N, i, temp;
	cin >> N;
	for (i = 0;i < N;++i) {
		cin >> temp;
		input.push_back(temp);
	}
	vector<int> answer(N, -1);
	for (i = 0;i < N;i++) {
		while (!index.empty() && input[index.top()] < input[i]) {
			answer[index.top()] = input[i];
			index.pop();
		}
		index.push(i);
	}
	for (i = 0;i < N;++i)
		cout << answer[i] << ' ';
	cout << '\n';
	return 0;
}