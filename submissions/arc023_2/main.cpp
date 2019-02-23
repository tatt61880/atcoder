#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

#define PrintLn(X) cout
 << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int R, C, D;
	cin >> R >> C >> D;
	int ans = 0;
	Rep(r, R){
		Rep(c, C){
			int x;
			cin >> x;
			if(r + c <= D){
				if(((r + c) & 1) == (D & 1)){
					//PrintLn(r << " " << c);
					ans = max(ans, x);
				}
			}
		}
	}

	PrintLn(ans);
	return 0;
}
