#include <iostream>
#include <map>
#include <set>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N, M;
	cin >> N >> M;
	int R[300001] = {0};
	int T[100000];
	set<pair<int, int>> st;
	Rep(i, M){
		int s, t;
		cin >> s >> t;
		R[--s]++;
		R[t--]--;
		pair<int, int> p(s, i);
		st.insert(p);
		T[i] = t;
	}
	Rep(i, N) R[i+1] += R[i];
	int F[100000] = {0};
	set<pair<int, int>>::iterator it = st.begin();
	Rep(i_r, N){
		if(R[i_r] == 1){
			for(; it != st.end();){
				if(T[it->second] >= i_r){
					F[it->second] = 1;
					break;
				}
				it++;
			}
		}
	}
	int count = 0;
	Rep(i, M) count += (1 - F[i]);
	PrintLn(count);
	Rep(i, M) if(F[i] == 0) PrintLn(i + 1);
	return 0;
}
