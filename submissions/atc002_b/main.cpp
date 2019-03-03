#include<iostream>
using namespace std;
typedef long long LL;
 
LL pow_mod(LL N, LL P, LL M){
	LL res = 1;
	while(P > 0){
		if(P & 1) res = (res * N) % M;
		P >>= 1;
		N = (N * N) % M;
	}
	return res;
}
int main()
{
	LL N,M,P;
	cin>>N>>M>>P;
	cout<<pow_mod(N,P,M)<<endl;
}
