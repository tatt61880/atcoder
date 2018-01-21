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
	set<string> st;
	char c = '.';
	Rep(i, N){
		string w;
		cin >> w;
		bool f = false;
		if(c != '.' && c != w[0]) f = true; // 繝ｫ繝ｼ繝ｫ1驕募渚
		if(st.count(w)) f = true; // 繝ｫ繝ｼ繝ｫ2驕募渚
		if(f){
			if(i % 2){
				PrintLn("WIN");
			}else{
				PrintLn("LOSE");
			}
			return 0;
		}
		st.insert(w);
		c = w[w.size() - 1];
	}
	PrintLn("DRAW");
	return 0;
}
