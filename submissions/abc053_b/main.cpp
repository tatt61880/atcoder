#include <cstdio>
#include <cstring>
 
int main(void)
{
 char s[200001];
 scanf("%s", s);
 int start, end;
 for(int i = 0; i < strlen(s); i++){
  if(s[i] == 'Z') end = i;
 }
 for(int i = 0; i < strlen(s); i++){
  if(s[i] == 'A') {start = i; break;}
 }
 printf("%d\n", end - star
t + 1);
 return 0;
}