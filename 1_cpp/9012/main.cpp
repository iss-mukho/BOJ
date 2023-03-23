#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	int T, i, j, len;
	string PS;
	cin >> T;
	for (i = 0; i < T; ++i) {
		stack<int> front;
		stack<int> rear;
		bool check = true;
		cin >> PS;
		len = PS.size();
		for (j = 0; j < len; ++j) {
			if (PS[j] == '(')
				front.push(PS[j]);
			else {
				if (front.size() == 0) {
					check = false;
					break;
				}
				rear.push(PS[j]);
			}	
			if (front.size() > 0 && rear.size() > 0) {
				front.pop();
				rear.pop();
			}
		}
		if (check && front.size() == 0 && rear.size() == 0)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}