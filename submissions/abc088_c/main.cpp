//{{{
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
const int MOD = 1e9+7;
//}}}
int a[100];
int main(void){
	int a1, b1, c1;
	cin >> a1 >> b1 >> c1;
	int a2, b2, c2;
	cin >> a2 >> b2 >> c2;
	int a3, b3, c3;
	cin >> a3 >> b3 >> c3;
	if(
		a1 - a2 == b1 - b2 &&
		a1 - a2 == c1 - c2 &&
		a1 - a3 == b1 - b3 &&
		a1 - a3 == c1 - c3
		){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}
