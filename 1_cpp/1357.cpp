// 백준 1357: 뒤집힌 덧셈(브론즈 I), https://www.acmicpc.net/problem/1357
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;

    string x = to_string(X);
    string y = to_string(Y);
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
 
    int temp = stoi(x) + stoi(y);
    string answer = to_string(temp);
    reverse(answer.begin(), answer.end());
    
    cout << stoi(answer) << '\n';

    return 0;
}