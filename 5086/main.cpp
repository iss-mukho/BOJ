#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> q;
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
	q.push_back(x);
}
int pop() {
	if (q.size() == 0)
		return -1;
	int temp = q.back();
	q.pop_back();
	return temp;
}
int size() {
	return q.size();
}
int empty() {
	if (q.size() == 0)
		return 1;
	return 0;
}
int front() {
	if (q.size() == 0)
		return -1;
	return q[0];
}
int back() {
	if (q.size() == 0)
		return -1;
	return q.back();
}