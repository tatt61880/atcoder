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
#include <casser
t>
using namespace std;


typedef long long LL;
typedef unsigned long long ULL;

const double PI = 3.14159265358979323846264338327950;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	string str;
	cin >> str;
	int pos;
	cin >> pos;
	Rep(i, str.length()){
		if(i == pos){
			cin >> pos;
			cout << "\"";
		}
		cout << str[i];
	}
	if(pos == str.length()) cout << "\"";
	PrintLn("");
	return 0;
}
