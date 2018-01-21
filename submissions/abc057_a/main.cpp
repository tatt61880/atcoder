#include <iostream>
using namespace std;
int main(void)
{
int a,b;
cin>>a>>b;
int ans=a+b;
if(ans>23)ans-=24;
cout<<ans<<endl;
return 0;
}