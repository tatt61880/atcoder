#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	int n;
	cin >> n;
	int primes[1254] = {2, 3, 5, 7, 11, 13, 17};
	int pnum = 7;
	for(int num = 19; num <= 10007; num += 2){
		if(num % 6 == 3) continue;
		bool f = true;
		for(int p = 0; primes[p] * primes[p] < num; ++p) {
			if(num % primes[p] == 0){
				f = false;
				break;
			}
		}
		if(f) primes[pnum++] = num;
	}
	LL P[1254];
	Rep(i, pnum) P[i] = (LL)primes[i] * primes[i] * primes[i];
	map<LL, int> mp;
	while(n--){
		LL v;
		cin >> v;
		for(int p = 0; P[p] < v + 1; ++p) while(v % P[p] == 0) v /= P[p];
		mp[v]++;
	}
	int max = 0;
	for(map<LL, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) if(itr->second > max) max = itr->second;
	PrintLn(max);
	return 0;
}
