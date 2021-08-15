#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	char S0[51];
	char S[51];
	char T[51];
	cin >> S0 >> T;
	vector<string> v;

	Rep(i, strlen(S0) - strlen(T) + 1){
		strcpy(S, S0);
		bool flag = false;
		bool f = true;
		Rep(j, strlen(T)){
			if(S[i + j] != '?' && S[i + j] != T[j]) f = false;
		}
		if(f) flag = true;
		if(flag){
			Rep(j, strlen(T)){
				S[i + j] = T[j];
			}
			Rep(k, strlen(S)){
				if(S[k] == '?') S[k] = 'a';
			}
			v.push_back(S);
		}
	}

	if(v.size() == 0){
		cout << "UNRESTORABLE" << endl;
	}else{
		sort(v.begin(), v.end());
		cout << v[0] << endl;
	}
	return 0;
}
