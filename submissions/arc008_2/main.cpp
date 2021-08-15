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
	int n, m;
	char name[1000];
	char kit[1000];
	cin >> n >> m;
	cin >> name >> kit;
	map<char, int> mp1;
	map<char, int> mp2;
	Rep(i, n) mp1[name[i]]++;
	Rep(i, m) mp2[kit[i]]++;
	for(map<char, int>::iterator it = mp1.begin(); it != mp1.end(); it++){
		char key = it->first;
		if(mp2[key] == 0){
			PrintLn(-1);
			return 0;
		}
		mp1[key] = (mp1[key] + mp2[key] - 1)/ mp2[key];
	}
	int max = 0;
	for(map<char, int>::iterator it = mp1.begin(); it != mp1.end(); it++){
		if(it->second > max) max = it->second;
	}
	PrintLn(max);
	return 0;
}
