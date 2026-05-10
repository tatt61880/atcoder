#include <iostream>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

char m[201][201];
int main(void)
{
	int last = 0;
	int H, W;
	int A, B;
	cin >> H >> W >> A >> B;

	Rep(i, H){
		cin >> m[i];
	}
	int o = 0;
	int a = 0;
	int b = 0;
	int ab = 0;
	int ab_ = 0;
	Rep(i, H){
		Rep(j, W){
			if(m[i][j] == 'S'){
				bool aa = (m[i][j] == m[H - 1 - i][j]);
				bool bb = (m[i][j] == m[i][W - 1 - j]);
				bool cc = (m[i][j] == m[H - 1 - i][W - 1 - j]);
				if(aa && bb && cc){
					ab++;
				}else if(aa && bb){
					ab_++;
				}else if(aa){
					a++;
				}else if(bb){
					b++;
				}else{
					o++;
				}
			}
		}
	}

	int x = A + B;
	x += (A + B) * (ab / 4) + (A > B ? A : B ) * (ab / 4);
	if(a == 0 && b == 0 && ab_ == 0 && o == 0){
		x -= (A + B);
		PrintLn(x);
		return 0;
	}

	if(A * ((a + ab_) / 2) > B * ((b + ab_) / 2)){
		x += A * ((a + ab_) / 2);
		if(b || o){
		}else{
			x -= A;
		}
	}else{
		x += B * ((b + ab_) / 2);
		if(a || o){
		}else{
			x -= B;
		}
	}
	PrintLn(x);
	return 0;
}
