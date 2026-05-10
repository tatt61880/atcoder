#include<iostream>
using namespace std;
int main(){
 int w,h,n;
 cin>>w>>h>>n;
 int xx=w, xn=0;
 int yx=h, yn=0;
 for(int i=0;i<n;i++){
  int x,y,a;
  cin>>x>>y>>a;
  switch(a){
  case 1: if(x>xn) xn=x; break;
  case 2: if(x<xx) xx=x; break;
  case 3: if(y>yn) yn=y; break;
  case 4: if(y<yx) yx=y; break;
  }
 }
 if(xx<xn)xx=xn;
 if(yx<yn)yx=yn;
 cout<<((xx-xn)*(yx-yn))<<endl;
 return 0;
}