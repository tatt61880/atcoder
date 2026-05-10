#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N, D, K;
	cin >> N >> D >> K;
	LL L[10000];
	LL R[10000];
	Rep(i, D){
		cin >> L[i] >> R[i];
	}
	Rep(i, K){
		int S, T;
		cin >> S >> T;
		if(S < T){
			Rep(i, D){
				if(L[i] <= S && S <= R[i]){
					S = R[i];
					if(S >= T){
						PrintLn(i + 1);
						break;
					}
				}
			}
		}else{
			Rep(i, D){
				if(L[i] <= S && S <= R[i]){
					S = L[i];
					if(S <= T){
						PrintLn(i + 1);
						break;
					}
				}
			}
		}
	}
	return 0;
}
