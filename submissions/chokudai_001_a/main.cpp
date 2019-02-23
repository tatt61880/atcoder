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

#define Print(x, y) cout << (y + 1) << " " << (x + 1) << e
ndl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int A[30][30];
	Rep(y, 30){
		Rep(x, 30){
			cin >> A[x][y];
		}
	}
	while(1){
		int max_x = 0;
		int max_y = 0;
		int max = 0;

		Rep(y, 30){
			Rep(x, 30){
				int a = A[x][y];
				if(a > max){
					max = a;
					max_x = x;
					max_y = y;
				}
			}
		}
		if(max == 0) break;

		int lx = max_x;
		int ly = max_y;
		int la;
		Print(lx, ly);
		A[lx][ly]--;
		la = A[lx][ly];
		while(la){
			if(lx > 0 && A[lx-1][ly] == la){
				lx--;
			}else if(lx < 29 && A[lx+1][ly] == la){
				lx++;
			}else if(ly > 0 && A[lx][ly-1] == la){
				ly--;
			}else if(ly < 29 && A[lx][ly+1] == la){
				ly++;
			}else{
				break;
			}
			Print(lx, ly);
			A[lx][ly]--;
			la = A[lx][ly];
		}
	}
	return 0;
}
