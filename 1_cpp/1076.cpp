// 백준 1076: 저항(브론즈 II), https://www.acmicpc.net/problem/1076
#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int main(){
    map<string, int> strToInt;
    strToInt["black"] = 0; // strToInt.insert(psi("black", 0));
    strToInt["brown"] = 1;
    strToInt["red"] = 2;
    strToInt["orange"] = 3;
    strToInt["yellow"] = 4;
    strToInt["green"] = 5;
    strToInt["blue"] = 6;
    strToInt["violet"] = 7;
    strToInt["grey"] = 8;
    strToInt["white"] = 9;

    string inLine;
    string temp;

    cin >> inLine;
    temp += to_string(strToInt[inLine]);
    cin >> inLine;
    temp += to_string(strToInt[inLine]);
    cin >> inLine;
    
    cout << fixed;
    cout.precision(0);    
    cout << (long)stoi(temp) * pow(10, strToInt[inLine]) << '\n';

    return 0;
}