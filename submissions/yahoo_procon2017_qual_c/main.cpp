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
#include <c
math>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int A[100000];
int a[100000] = {0};
string S[100000];
char target[100000];
int main(void)
{
	int N, K;
	cin >> N >> K;

	Rep(i, K) cin >> A[i];
	Rep(i, K) a[A[i] - 1] = 1;
	Rep(i, N) cin >> S[i];
	strcpy(target, S[A[0] - 1].c_str());
	int minLength = strlen(target);
	Rep(i, K){
		if(S[A[i] - 1].size() < minLength){
			minLength = S[A[i] - 1].size();
		}
	}
	Rep(n, minLength + 1){
		Rep(i, N){
			if(a[i]){
				if(strncmp(target, S[i].c_str(), n)){
					PrintLn("-1");
					return 0;
				}
			}else{
				if(strncmp(target, S[i].c_str(), n) == 0){
					goto NEXT;
				}
			}
		}
		target[n] = '\0';
		PrintLn(target);
		return 0;
NEXT:
;
	}
	PrintLn("-1");
	return 0;
}
