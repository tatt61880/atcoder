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

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int board[100000];
vector<int> v[100000];
int main(void)
{
	int N;
	cin >> N;


	Rep(i, N - 1){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<int> vf;
	vector<int> vs;
	board[0] = 1;
	vf.push_back(0);
	board[N - 1] = -1;
	vs.push_back(N - 1);

	while(1){
		int break_count = 0;
		if(vf.size() != 0){
			vector<int> vt;
			for(auto &x: vf){
				for(auto &y: v[x]){
					if(board[y] == 0){
						board[y] = 1;
						vt.push_back(y);
					}
				}
			}
			vf = vt;
		}else{
			break_count++;
		}
		if(vs.size() != 0){
			vector<int> vt;
			for(auto &x: vs){
				for(auto &y: v[x]){
					if(board[y] == 0){
						board[y] = -1;
						vt.push_back(y);
					}
				}
			}
			vs = vt;
		}else{
			break_count++;
		}
		if(break_count == 2) break;
	}

	int count = 0;
	Rep(i, N){
		count += board[i];
	}
	if(count > 0){
		PrintLn("Fennec");
	}else{
		PrintLn("Snuke");
	}
	return 0;
}
