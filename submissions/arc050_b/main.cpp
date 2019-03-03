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
typedef long long LL;
typedef unsigned long long ULL;
const double PI = 3.14159265358979323846264338327950;
const LL MOD = 1000000007;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
LL R, B, r, b;
// n譚溘・襍､縺ｮ螟壹＞闃ｱ譚溘ｒ菴懊▲縺溘→縺阪・譛ｬ謨ｰ縲・
LL f(LL n){
	LL R2 = R - n * r;
	LL B2 = B - n;
	if(B2 / b > R2){
		return n + R2;
	}else{
		return n + B2 / b;
	}
}
int main(void)
{
	cin >> R >> B >> r >> b;
	LL p1 = 0;
	LL p5 = (R / r > B) ? B : (R / r);
	LL p3 = (p5 + p1) / 2;
	while(1){
		LL p4 = (p5 + p3) / 2;
		LL p2 = (p3 + p1) / 2;
		LL v5 = f(p5);
		LL v4 = f(p4);
		LL v3 = f(p3);
		LL v2 = f(p2);
		LL v1 = f(p1);
		if(p1 >= p2-1 && p2 >= p3-1 && p3 >= p4-1 && p4 >= p5-1){
			LL ans = 0;
			ans = max(ans, v1);
			ans = max(ans, v2);
			ans = max(ans, v3);
			ans = max(ans, v4);
			ans = max(ans, v5);
			PrintLn(ans);
			return 0;
		}
		if(v5 > v4){
			p1 = p3;
			p3 = p4;
		}else if(v1 > v2){
			p5 = p3;
			p3 = p2;
		}else if(v3 > v2 && v3 > v4){
			p5 = p4;
			p1 = p2;
		}else if(v2 < v3){
			p1 = p3;
			p3 = p4;
		}else{
			p5 = p3;
			p3 = p2;
		}
	}
	return 0;
}
