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

typedef long long ll;
typedef unsigned long long ull;



#define PrintLn(X) cout << X
 << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int a2[100000] = {0};
int a5[100000] = {0};

int main(void)
{
	string T;
	cin >> T;
	int N = T.length();
	Rep(i, N){
		int pre2 = 0;
		int pre5 = 0;
		if(i >= 2){
			pre2 = a2[i - 2];
			pre5 = a5[i - 2];
		}
		if(T[i] == '?'){
			a2[i] = pre2 + 1;
			a5[i] = pre5 + 1;
		}else if(T[i] == '2'){
			a2[i] = pre2 + 1;
			a5[i] = 0;
		}else if(T[i] == '5'){
			a2[i] = 0;
			a5[i] = pre5 + 1;
		}
	}

	int ans = 0;
	Rep(i, N - 1){
		//PrintLn(i << " " << a2[i] << " " << a5[i + 1]);
		int m = min(a2[i], a5[i + 1]);
		if(m > ans) ans = m;
	}
	PrintLn(ans * 2);
	return 0;
}
