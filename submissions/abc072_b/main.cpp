#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i = (int)(begin), i##_end = (int)(end); i < i##_end; ++i)
#define repN(a) repX a
#defi
ne repX(a0,a1,a2,x,...) x

int main(void){
	string s;
	cin >> s;
	int len = s.size();
	rep(i, len){
		printf("%c", s[i]);
		i++;
	}
	printf("\n");
	return 0;
}
