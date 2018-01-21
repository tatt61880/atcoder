#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
typedef long long ll;
int N, K;
ll x[50];
ll y[50];
ll minX;
ll maxX;
ll minY;
ll maxY;
int main(void)
{
	cin >> N >> K;
	Rep(i, N){
		cin >> x[i] >> y[i];
	}
	ll minS = 1LL << 62;
	Rep(a, N){
		Rep(b, N){
			if(x[a] > x[b]) continue;
			minX = x[a];
			maxX = x[b];
			Rep(c, N){
				Rep(d, N){
					if(y[c] > y[d]) continue;
					minY = y[c];
					maxY = y[d];
					ll S = (maxX - minX) * (maxY - minY);
					if(S < minS){
						int count = 0;
						Rep(i, N){
							if(minX <= x[i] && x[i] <= maxX && minY <= y[i] && y[i] <= maxY){
								count++;
							}
						}
						if(count >= K){
							minS = S;
						}
					}
				}
			}
		}
	}
	PrintLn(minS);
	return 0;
}
