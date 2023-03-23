#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	int i, len;
	char temp;
	while (1) {
		bool check = true, check_ = true;
		stack<int> front;
		stack<int> rear;
		stack<int> front_;
		stack<int> rear_;
		stack<int> allFront;
		string PS;
		while ((temp = getchar()) != '.')
			PS += temp;
		if (PS == "\n")
			break;
		len = PS.size();
		for (i = 0; i < len; ++i) {
			if (PS[i] == '(') {
				front.push(PS[i]);
				allFront.push(PS[i]);
			}
			else if (PS[i] == ')') {
				if (front.size() == 0 || allFront.top() == '[') {
					check = false;
					break;
				}
				rear.push(PS[i]);
			}
			else if (PS[i] == '[') {
				front_.push(PS[i]);
				allFront.push(PS[i]);
			}
			else if (PS[i] == ']') {
				if (front_.size() == 0 || allFront.top() == '(') {
					check_ = false;
					break;
				}
				rear_.push(PS[i]);
			}
			if (front.size() > 0 && rear.size() > 0) {
				front.pop();
				rear.pop();
				allFront.pop();
			}
			if (front_.size() > 0 && rear_.size() > 0) {
				front_.pop();
				rear_.pop();
				allFront.pop();
			}
		}
		if (check && check_ && front.size() == 0 && rear.size() == 0 && front_.size() == 0 && rear_.size() == 0 && allFront.size() == 0)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return 0;
}