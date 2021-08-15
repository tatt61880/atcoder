#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

#if 0
12345 竍・
10000 + 1000 + 100 * 2 + 10 * 4 + 1 * 8 +
    2000 * 2 + 200 * 2 + 20 * 4 + 2 * 8 +
               300 * 4 + 30 * 4 + 3 * 8 +
                         40 * 8 + 4 * 8 +
                                  5 * 16
#endif

int main(void)
{
	char S[11];
	cin >> S;
	LL s[11];

	int N = strlen(S);
	Rep(i, N){
		s[i] = S[N - 1 - i] - '0';
	}

	LL ans = 0;
	Rep(i, N){
		LL sub = 0;
		Rep(j, N - 1){
			sub += s[i];
			sub *= (j != N - 2) ? 2 : 1;
			s[i] *= (i > j) ? 10 : 1;
		}
		//PrintLn(sub + s[i]);
		ans += sub + s[i];
	}
	PrintLn(ans);
	return 0;
}
