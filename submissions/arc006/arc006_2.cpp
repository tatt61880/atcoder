#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
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

int main(void)
{
	int N, L;
	string A[20];
	char buf[20];
	cin >> N >> L; cin.ignore();
	Rep(i, L){
		getline(cin, A[i]);
	}
	string B;
	getline(cin, B);
	int pos = B.find('o') / 2;

	Rep(i, L){
		if(pos != 0     && A[L - 1 - i][pos * 2 - 1] == '-') pos--;
		else if(pos != N - 1 && A[L - 1 - i][pos * 2 + 1] == '-') pos++;
	}

	PrintLn(pos + 1);
	return 0;
}
