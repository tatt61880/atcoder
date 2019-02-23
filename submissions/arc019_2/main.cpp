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
	string so;
	string sr;
	cin >> so;
	sr = so;
	reverse(sr.begin(), sr.end());

	int len = so.size();
	if(so == sr){
		len -= len % 2;
		PrintLn(len * 25);
	}else{
		int ans = len * 25;
		int count = 0;
		Rep(i, len / 2){
			if(so[i] != sr[i]) count++;
		}
		if(count == 1) ans -= 2;
		PrintLn(ans);
	}
	return 0;
}
