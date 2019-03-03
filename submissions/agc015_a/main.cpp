#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	ll N, A, B;
	cin >> N >> A >> B;
	if(N == 1){
		if(A == B){
			PrintLn(1);
		}else{
			PrintLn(0);
		}
	}else if(N == 2){
		if(A <= B){
			PrintLn(1);
		}else{
			PrintLn(0);
		}
	}else{
		if(A <= B){
			PrintLn(B * (N - 1) + A - (A * (N - 1) + B) + 1);
		}else{
			PrintLn(0);
		}
	}
	return 0;
}
