#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
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

typedef long long LL;
typedef unsigned long long ULL;

const double PI = 3.14159265358979323846264338327950;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	char s[100];
	scanf("%s", s);

	char ans[100] = "";
	Rep(i, strlen(s)){
		switch(s[i]){
			case '0': ans[strlen(ans)] = '0'; break;
			case '1': ans[strlen(ans)] = '1'; break;
			case 'B': if(strlen(ans)) ans[strlen(ans) - 1] = '\0'; break;
		}
	}
	PrintLn(ans);
	return 0;
}
