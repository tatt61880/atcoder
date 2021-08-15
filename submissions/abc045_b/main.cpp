#include<string>
#include<iostream>
using namespace std;

void p(char c){ cout<<c<<endl; }

int main(void)
{
 string a,b,c;
 cin>>a>>b>>c;
 int i=1,j=0,k=0;
 char cc=a[0];
 while(1){
  switch(cc){
  case 'a':
   if(i==a.length()) {p('A'); return 0;}
   cc=a[i++];
   break;
  case 'b':
   if(j==b.length()) {p('B'); return 0;}
   cc=b[j++];
   break;
  case 'c':
   if(k==c.length()) {p('C'); return 0;}
   cc=c[k++];
   break;
  }
 }
 return 0;
}