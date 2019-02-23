#include <iostream>
#include <set>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N;
	cin >> N;
	int ans = 0;
	set<int> st;
	Rep(i, N){
		int a;
		cin >> a;
		if(st.count(a)){
			st.erase(a);
		}else{
			
st.insert(a);
		}
	}
	PrintLn(st.size());
	return 0;
}
