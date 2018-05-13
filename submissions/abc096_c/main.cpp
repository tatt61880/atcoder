//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}
int H, W;
char s[51][51];
int count(int w, int h){
	if(h < 0) return 0;
	if(w < 0) return 0;
	if(h > H - 1) return 0;
	if(w > W - 1) return 0;
	return (s[h][w] == '#');
}
bool isValid(int w, int h){
	int res = 0;
	res += count(w - 1, h);
	res += count(w + 1, h);
	res += count(w, h - 1);
	res += count(w, h + 1);
	return res;
}
int main(){
	cin >> H >> W;
	rep(i, H) {
		cin >> s[i];
	}
	bool ans = true;
	rep(h, H) {
		rep(w, W) {
			if(s[h][w] == '#' && !isValid(w, h)) ans = false;
		}
	}
	puts(ans ? "Yes" : "No");
	return 0;
}
