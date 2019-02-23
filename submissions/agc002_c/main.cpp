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
#include 
<cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const double PI = 3.14159265358979323846264338327950;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N, L;
	cin >> N >> L;
	int A[100000];
	Rep(i, N){
		cin >> A[i];
	}
	bool f = false;
	int id = 0;
	Rep(i, N - 1){
		if(A[i] + A[i + 1] >= L){
			f = true;
			id = i;
			break;
		}
	}
	if(f){
		PrintLn("Possible");
		Rep(i, id){
			printf("%d\n", i + 1);
		}
		for(int i = N - 2; i >= id; i--){
			printf("%d\n", i + 1);
		}
	}else{
		PrintLn("Impossible");
	}
	return 0;
}
