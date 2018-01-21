#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	cout<<max(n-a,0)<<" "<<max(2*n-b,0)<<" "<<max(3*n-c,0)<<endl;
	return 0;
}
