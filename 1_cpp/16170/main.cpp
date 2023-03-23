#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
int main() {
	time_t time_now = time(NULL);
	struct tm* t = localtime(&time_now);
	cout << t->tm_year + 1900 << '\n' << t->tm_mon + 1 << '\n' << t->tm_mday << '\n';
	return 0;
}