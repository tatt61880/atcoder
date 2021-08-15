#include <cstdio>
int main()
{
  char s[4];
  scanf("%s", s);
  s[1] = 'R' - s[1] + 'B'; 
  printf("%s\n", s);
}