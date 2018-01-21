#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int main(void)
{
	int n;
	cin>>n;
	int a[1000];
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	int ans=0;
	int sum=0;
	rep(i,n){
		if(sum<a[i]){
			ans++;
			sum+=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
