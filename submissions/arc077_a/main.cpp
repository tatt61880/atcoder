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
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int a[200000];
int b[200000];
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		cin >> a[i];
	}
	if(N % 2 == 0){
		Rep(i, N){
			if(i % 2 == 0){
				b[N / 2 + i / 2] = a[i];
			}else{
				b[N / 2 - ((i + 1) / 2)] = a[i];
			}
		}
	}else{
		Rep(i, N){
			if(i % 2 == 0){
				b[N / 2 - i / 2] = a[i];
			}else{
				b[N / 2 + (i + 1) / 2] = a[i];
			}
		}
	}
	Rep(i, N){
		cout << b[i];
		if(i != N-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	return 0;
}
