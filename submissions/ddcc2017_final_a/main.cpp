#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a;
 i < (int)(b); ++i)

typedef long long ll;

float K;

bool in(float x, float y, float r)
{
	return x * x + y * y <= r * r;
}

int num(float size)
{
	int res = 0;
	float r = size / 2.0;
	Rep(i, size / K){
		Rep(j, size / K){
			float min_x = i * K - r;
			float min_y = j * K - r;
			float max_x = (i + 1) * K - r;
			float max_y = (j + 1) * K - r;
			if(in(min_x, min_y, r) && 
				in(max_x, min_y, r) && 
				in(min_x, max_y, r) && 
				in(max_x, max_y, r)){
				res++;
			}
		}
	}
	return res;
}

int main(void)
{
	cin >> K;
	cout << num(200.0) << " " << num(300.0) << endl;
	return 0;
}
