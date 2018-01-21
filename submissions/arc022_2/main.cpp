#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	int N;
	cin >> N;
	int A[100000];
	Rep(i, N){
		cin >> A[i];
	}
	set<int> st;
	int ans = 0;
	int left = 0;
	Rep(right, N){
		if(st.find(A[right]) == st.end()){
			st.insert(A[right]);
			ans = max(ans, right - left + 1);
		}else{
			while(A[left] != A[right]){
				st.erase(A[left]);
				left++;
			}
			left++;
		}
	}
	PrintLn(ans);
	return 0;
}
