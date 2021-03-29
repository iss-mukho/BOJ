#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> input;
void push(int x);
int pop();
int size();
int empty();
int top();
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
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
		else
			cout << top() << '\n';
	}
	return 0;
}
void push(int x) {
	input.push_back(x);
}
int pop() {
	if (input.size() == 0)
		return -1;
	int a = input.back();
	input.pop_back();
	return a;
}
int size() {
	return input.size();
}
int empty() {
	return input.empty();
}
int top() {
	if (input.empty())
		return -1;
	return input[input.size() - 1];
}