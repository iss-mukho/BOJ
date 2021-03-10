#include <iostream>
using namespace std;
int main()
{
    int dot[3][2];
    int tempX, tempY;
    for (int i = 0; i < 3; i++)
        cin >> dot[i][0] >> dot[i][1];

    if (dot[0][0] == dot[1][0])
        tempX = dot[2][0];
    else if (dot[0][0] == dot[2][0])
        tempX = dot[1][0];
    else
        tempX = dot[0][0];
    if (dot[0][1] == dot[1][1])
        tempY = dot[2][1];
    else if (dot[0][1] == dot[2][1])
        tempY = dot[1][1];
    else
        tempY = dot[0][1];

    cout << tempX << ' ' << tempY << '\n';
    return 0;
}