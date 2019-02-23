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

int main(void){
	int N;
	cin >> N;
	vector<bool> v;
	bool same_colors_flag = true;
	Rep(i, N){
		bool c;
		cin >> c;
		v.push_back(c);
		if(v[i] != v[0]) same_colors_flag = false;
	}

	if(same_colors_flag){
		PrintLn(-1);
		return 0;
	}

	//Rep(i, N) cout << v[i]; PrintLn("");
	int count_max = 0;
	int i = 0;
	int count_first = -1;
	int count_last = 0;
	while(i < N - 1){
		//PrintLn("i = " << i);
		int count = 1;
		while(i != N - 1 && v[i] == v[i + 1]){
			i++;
			count++;
		}
		if(count == 1) i++;
		if(count_first == -1) count_first = count;
		count_last = count;
		count_max = max(count_max, count);
		//PrintLn(count_max);
	}
	if(v[0] ==
 v.back()){
		count_max = max(count_max, count_first + count_last);
	}
	//PrintLn(count_max);
	PrintLn((count_max + 1) / 2);
	return 0;
}
