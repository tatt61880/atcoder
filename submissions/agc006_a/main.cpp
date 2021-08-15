#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N;
	char s[101];
	char t[101];
	cin >> N >> s >> t;
	Rep(i, N + 1){
		char st[201] = "";
		strncpy(st, s, i);
		strcat(st, t);
		if(strncmp(st, s, N) == 0){
			PrintLn(i + N);
			return 0;
		}
	}
}
