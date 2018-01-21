#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define PrintLn(x) cout << (x) << endl;
int main(void)
{
	int N;
	cin >> N;
	map<string, pair<string, bool>> mp;
	string S[20];
	Rep(n, N) cin >> S[n];
	int U[20];
	bool V[20];
	Rep(n, N){
		string u, s, v;
		cin >> u >> s >> s >> v >> s;
		mp[S[n]] = pair<string, bool>(u, (v == "good"));
	}
	int index;
	index = 0;
	map<string, int> StoI;
	for(auto& x:mp) StoI[x.first] = index++;
	index = 0;
	for(auto& x:mp){
		U[index] = StoI[x.second.first];
		V[index] = x.second.second;
		index++;
	}
	int max = 0;
	int max_i = 0;
	bool P[20];
	for(int i = ((1 << N) - 1); i >= 0; i--){
		bool flag = true;
		int count = 0;
		Rep(n, N) P[n] = (((i >> (N - 1 - n)) & 1) == 1);
		Rep(n, N){
			if(P[n]){
				count++;
				if((V[n] ^ P[U[n]])){
					flag = false;
					break;
				}
			}else{
				if(!(V[n] ^ P[U[n]])){
					flag = false;
					break;
				}
			}
		}
		if(flag && count > max){
			max = count;
			max_i = i;
		}
	}
	if(max == 0){
		PrintLn("No answers");
		return 0;
	}
	Rep(n, N) P[n] = (((max_i >> (N - 1 - n)) & 1) == 1);
	for(auto& x:StoI){
		if(P[x.second]){
			PrintLn(x.first);
		}
	}
	return 0;
}
