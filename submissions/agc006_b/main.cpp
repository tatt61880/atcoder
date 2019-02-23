#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a
; i < (int)(b); ++i)

int main(void)
{
	int N, x;
	cin >> N >> x;
	int a[200000];
	
	Rep(i, 2 * N - 1){
		a[i] = i + 1;
	}
	if(x != 1 && x != 2 * N - 1){
		PrintLn("Yes");
		if(x < N){
			swap(a[x - 0], a[N - 0]);
			swap(a[x - 1], a[N - 1]);
			swap(a[x - 2], a[N - 2]);
		}else{
			swap(a[x - 2], a[N - 2]);
			swap(a[x - 1], a[N - 1]);
			swap(a[x - 0], a[N - 0]);
		}
		Rep(i, 2 * N - 1) PrintLn(a[i]);
	}else{
		PrintLn("No");
	}
	return 0;
}
