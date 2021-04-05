#include <iostream>
#include <string>
#include <vector>
using namespace std;
void push_front(int x);
void push_back(int x);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();
vector<int> v;
int main() {
	int N, i;
	string temp;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> temp;
		if (temp == "push_front") {
			cin >> temp;
			push_front(stoi(temp));
		}
		else if (temp == "push_back") {
			cin >> temp;
			push_back(stoi(temp));
		}
		else if (temp == "pop_front")
			cout << pop_front() << '\n';
		else if (temp == "pop_back")
			cout << pop_back() << '\n';
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
void push_front(int x) {
	v.insert(v.begin(), x);
}
void push_back(int x){
	v.push_back(x);
}
int pop_front() {
	if (v.size() == 0)
		return -1;
	int temp = v[0];
	v.erase(v.begin());
	return temp;
}
int pop_back() {
	if (v.size() == 0)
		return -1;
	int temp = v[size() - 1];
	v.pop_back();
	return temp;
}
int size() {
	return v.size();
}
int empty() {
	if (v.size() == 0)
		return 1;
	else
		return 0;
}
int front() {
	if (v.size() == 0)
		return -1;
	return v[0];
}
int back() {
	if (v.size() == 0)
		return -1;
	return v[size()-1];
}