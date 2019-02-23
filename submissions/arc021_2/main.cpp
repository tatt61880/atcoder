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
	int L;
	cin >> L;
	LL B[100000];
	LL A[100000];
	Rep(i, L){
		cin >> B[i];
	}
	A[0] = 0;
	Rep(i, L - 1){
		A[i + 1] = A[i] ^ B[i];
	}
	if(A[L - 1] != B[L - 1]){
		PrintLn(-1);
	}else{
		Rep(i, L){
			PrintLn(A[i]);
		}
	}
	return 0;
}
