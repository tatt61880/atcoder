#include <iostream>
#include <set>
using namespace std;

typedef long long LL;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	LL n;
	int q;
	cin >> n >> q;
	int a[24];
	Rep(i, q) cin >> a[i];

	set<LL> st;
	st.insert(1);
	Rep(i, q){
		set<LL> st2;
		for(auto& x:st){
			LL num = x * a[i];
			if(num <= n) st2.insert(num);
		}
		for(auto& x:st2) st.insert(x);
	}

	int ans = 0;
	for(auto& x:st){
		LL num = x;
		Rep(i, q) if(num % a[i] 
== 0) num /= a[i];
		if(num == 1) ans++;
	}
	PrintLn(ans);
	return 0;
}
