#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int x, y;
char c[10][11];
string ans = "";
int dx = 0;
int dy = 0;

void f(){
	ans += c[y][x];
	if(x == 0 && dx == -1) dx = 1;
	if(y == 0 && dy == -1) dy = 1;
	if(x == 8 && dx == 1) dx = -1;
	if(y == 8 && dy == 1) dy = -1;
	x+=dx; y+=dy;
	//printf("c[%d][%d] = %c\n", y, x, c[y][x]);
}

int main(void)
{
	string W;
	cin >> x >> y >> W;

	if(W.find('R') != -1) dx = 1;
	if(W.find('L') != -1) dx = -1;
	if(W.find('U') != -1) dy = -1;
	if(W.find('D') != -1) dy = 1;
	Rep(i, 10){
		cin >> c[i];
	}

	x--; y--;
	f();
	f();
	f();
	f();
	PrintLn(ans);
	return 0;
}

