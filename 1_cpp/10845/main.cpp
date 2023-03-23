#include <iostream>
#include <string>
#include <list>
using namespace std;
list<int> q;
void push(int X);
int pop();
int size();
int empty();
int front();
int back();
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i, x;
	string input;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> input;
		if (input == "push") {
			cin >> x;
			push(x);
		}
		else if (input == "pop")
			cout << pop() << '\n';
		else if (input == "size")
			cout << size() << '\n';
		else if (input == "empty")
			cout << empty() << '\n';
		else if (input == "front")
			cout << front() << '\n';
		else if (input == "back")
			cout << back() << '\n';
	}
	return 0;
}
void push(int X) {
	q.push_back(X);
}
int pop() {
	if (q.size() == 0)
		return -1;
	else {
		int temp = q.front();
		q.pop_front();
		return temp;
	}
}
int size() {
	return q.size();
}
int empty() {
	if (q.size() == 0)
		return 1;
	else
		return 0;
}
int front() {
	if (q.size() == 0)
		return -1;
	else
		return q.front();
}
int back() {
	if (q.size() == 0)
		return -1;
	else
		return q.back();
}