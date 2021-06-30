#include <iostream>
#include <string>
using namespace std;
// C++: it_is_me_mukho
// JAVA: itIsMeMukho
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string varName, output;
	int i, len;
	cin >> varName;
	len = varName.length();

	if ((varName[0] >= 65 && varName[0] <= 90) || varName[0] == '_' || varName[len - 1] == '_' || varName.find("__") != -1)
		output = "Error!";
	else if (varName.find('_') == -1) { // JAVA to C++
		for (i = 0; i < len; ++i) {
			if (varName[i] >= 65 && varName[i] <= 90) {
				output += "_";
				output += varName[i] + 32;
			}
			else if (varName[i] >= 97 && varName[i] <= 122)
				output += varName[i];
			else {
				output = "Error!";
				break;
			}
		}
	}
	else {
		for (i = 0; i < len; ++i) { //  C++ to JAVA
			if (varName[i] >= 65 && varName[i] <= 90) {
				output = "Error!";
				break;
			}

			if (varName[i] == '_') {
				++i;
				if (varName[i] >= 65 && varName[i] <= 90) {
					output = "Error!";
					break;
				}
				output += varName[i] - 32;
			}
			else
				output += varName[i];
		}
	}

	cout << output << '\n';

	return 0;
}