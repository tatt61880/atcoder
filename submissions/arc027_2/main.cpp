#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long 
LL;
typedef unsigned long long ULL;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int N;
string str1, str2;

void f(char a, char d){
	Rep(i, N){
		if(str1[i] == a) str1[i] = d;
		if(str2[i] == a) str2[i] = d;
	}
}

void g(char a1, char a2){
	Rep(i, N){
		if(str1[i] == a1) str1[i] = a2;
		if(str2[i] == a1) str2[i] = a2;
	}
}

int main(void){
	cin >> N;
	cin >> str1 >> str2;
	Rep(i, 26){
		char c = 'A' + i;
		Rep(j, N){
			if(str1[j] == c && str2[j] != c) g(str1[j], str2[j]);
			if(str2[j] == c && str1[j] != c) g(str2[j], str1[j]);
		}
	}
	Rep(i, 10){
		char c = '0' + i;
		Rep(j, N){
			if(str1[j] == c && str2[j] != c) f(str1[j], c);
			if(str2[j] == c && str1[j] != c) f(str2[j], c);
		}
	}
	LL ans = 1;
	Rep(i, 26){
		char c = &#3
9;A' + i;
		Rep(j, N){
			if(str1[j] == c){
				if(j == 0) ans *= 9;
				else ans *= 10;
				break;
			}
		}
	}
	//PrintLn(str1);
	PrintLn(ans);
	return 0;
}
