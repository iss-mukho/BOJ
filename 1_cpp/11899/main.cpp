#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	string S;
	stack<char> s;
	int i, len;
	cin >> S;
	len = S.length();
	for (i = 0; i < len; ++i) {
		if (s.empty())
			s.push(S[i]);
		else if (s.top() == '(') {
			if (S[i] == ')')
				s.pop();
			else
				s.push(S[i]);
		}
		else
			s.push(S[i]);
	}
	cout << s.size() << '\n';
	return 0;
}