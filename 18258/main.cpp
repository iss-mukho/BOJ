#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> dq;
void push(int x);
int pop();
int size();
int empty();
int front();
int back();
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, i;
	string temp;
	cin >> N;
	for (i = 1; i <= N; ++i) {
		cin >> temp; // cin은 공백으로 구분해서 입력받음
		if (temp == "push") {
			cin >> temp;
			push(stoi(temp));
		}
		else if (temp == "pop")
			cout << pop() << '\n';
		else if (temp == "size")
			cout << size() << '\n';
		else if (temp == "empty")
			cout << empty() << '\n';
		else if (temp == "front")
			cout << front() << '\n';
		else
			cout << back() << '\n';
	}
	return 0;
}
void push(int x) {
	dq.push_back(x);
}
int pop() {
	if (dq.size() == 0)
		return -1;
	int temp = dq[0];
	dq.pop_front();
	return temp;
}
int size() {
	return dq.size();
}
int empty() {
	if (dq.size() == 0)
		return 1;
	return 0;
}
int front() {
	if (dq.size() == 0)
		return -1;
	return dq[0];
}
int back() {
	if (dq.size() == 0)
		return -1;
	return dq[size()-1];
}