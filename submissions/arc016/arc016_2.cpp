#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N;
	cin >> N;
	int a[9] = {0};
	int count = 0;
	Loop(N){
		string s;
		cin >> s;
		Rep(i, 9){
			if(!a[i] && s[i] == 'o') a[i] = 1, count++;
			if(s[i] == 'x') count++;
			if(s[i] != 'o') a[i] = 0;
		}
	}
	PrintLn(count);
	return 0;
}
