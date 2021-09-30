#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> s;
	string input, output;
	int inputLength = 0, i;
	cin >> input;
	inputLength = input.length();

	for (i = 0; i < inputLength; ++i) {
		if (input[i] == 'X') {
			if (s.size() == 4) {
				output += "AAAA";
				while (!s.empty())
					s.pop();
			}
			s.push(input[i]);
		}
		else {
			if (s.size() == 4) {
				output += "AAAA";
				while (!s.empty())
					s.pop();
			}
			if (s.size() == 2) {
				output += "BB";
				while (!s.empty())
					s.pop();
			}
			else if(s.size() != 0){
				output = "-1";
				break;
			}
			output += '.';
		}
	}
	if (!s.empty()) {
		if (s.size() == 4)
			output += "AAAA";
		else if (s.size() == 2)
			output += "BB";
		else
			output = "-1";
	}

	cout << output << '\n';
	return 0;
}