#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	string C, result;
	cin >> C;
	if (C == "A+")
		result = "4.3";
	else if (C == "A0")
		result = "4.0";
	else if (C == "A-")
		result = "3.7";
	else if (C == "B+")
		result = "3.3";
	else if (C == "B0")
		result = "3.0";
	else if (C == "B-")
		result = "2.7";
	else if (C == "C+")
		result = "2.3";
	else if (C == "C0")
		result = "2.0";
	else if (C == "C-")
		result = "1.7";
	else if (C == "D+")
		result = "1.3";
	else if (C == "D0")
		result = "1.0";
	else if (C == "D-")
		result = "0.7";
	else if (C == "F")
		result = "0.0";
	cout << result << '\n';
	return 0;
}