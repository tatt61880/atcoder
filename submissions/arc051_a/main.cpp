#include <iostream>
using namespace std;
#define PrintLn(X) cout << (X) << endl

int X1, Y1, R;
int x2, y2, x3, y3;

bool inCircle(int x, int y)
{
	return (X1 - x) * (X1 - x) + (Y1 - y) * (Y1 - y) <= R * R;
}
bool inBox(int x, int y)
{
	return x2 <= x && x <= x3 && y2 <= y && y <= y3;
}
void Print(bool covered){
	PrintLn(covered ? "NO" : "YES");
}

int main(void)
{
	cin >> X1 >> Y1 >> R;
	cin >> x2 >> y2 >> x3 >> y3;
	Print(inBox(X1 - R, Y1) && inBox(X1 + R, Y1) && inBox(X1, Y1 - R) && inBox(X1, Y1 + R));
	Print(inCircle(x2, y2) && inCircle(x2, y3) && inCircle(x3, y2) && inCircle(x3, y3));
	return 0;
}
