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

#define PrintLn(X) cout
 << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int Q[8] = {0};

void printQ(){
	char buf[9] = "........";
	/*
	Rep(i, 8) PrintLn(i << Q[i]);
	*/
	Rep(i, 8){
		buf[Q[i]] = 'Q';
		PrintLn(buf);
		buf[Q[i]] = '.';
	}
}
bool isValidQ(){
	For(i, 1, 8){
		if(Q[i] != -1){
			Rep(j, i){
				if(Q[j] == -1) continue;
				if(Q[i] == Q[j]) return false;
				if(Q[i] - Q[j] == i - j) return false;
				if(Q[i] - Q[j] == j - i) return false;
			}
		}
	}
	return true;
}

bool solve(int n){
	For(i, n, 8){
		if(Q[i] != -1) continue;
		Rep(j, 8){
			Q[i] = j;
			if(isValidQ()){
				if(i == 7){
					bool flag = true;
					Rep(k, 8) if(Q[k] == -1) flag = false;
					if(flag){
						printQ();
						return true;
					}
				}else{
					if(solve(i + 1)) return true;
				}
			}
			Q[i] = -1;
		}
	}

	bool flag = true;
	Rep(k, 8) if(Q[k] == -1) f
lag = false;
	if(flag){
		printQ();
		return true;
	}
	return false;
}

int main(void)
{
	char buf[9];
	Rep(i, 8){
		cin >> buf;
		Q[i] = -1;
		Rep(j, 8){
			if(buf[j] == 'Q'){
				if(Q[i] != -1){
					PrintLn("No Answer");
					return 0;
				}else{
					Q[i] = j;
				}
			}
		}
	}

	if(!solve(0)){
		PrintLn("No Answer");
	}
	return 0;
}
