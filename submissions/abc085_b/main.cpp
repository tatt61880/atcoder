#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define printLn(X) cout << X << endl
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(){
	set<int> st;
	int N;
	cin >> N;
	rep(i, N){
		int x;
		cin >> x;
		st.insert(x);
	}
	printLn(st.size());
	return 0;
}
