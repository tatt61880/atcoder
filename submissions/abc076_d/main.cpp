#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

float f(int t, int vs, int ve, int vmax)
{
	float ret = 0.0;
	int 
v = vs;
	For(i, 1, t + 1){
		int vv;
		vv = min(vs + i, ve + t - i);
		vv = min(vv, vmax);
		ret += float(vv + v) / 2.0;
		if(vv == v && v < vmax) ret += 0.25;
		v = vv;
	}
	return ret;
}

int main(void)
{
	int N;
	int t[101];
	int T[101];
	int v[101];
	int vs[101];
	int ve[101];

	cin >> N;
	Rep(i, N) cin >> t[i];
	Rep(i, N) cin >> v[i];
	t[N] = 0;
	v[N] = 0;

	T[0] = 0;
	Rep(i, N) T[i + 1] = T[i] + t[i];

#if 0
	Rep(i, N + 1){
		cout << T[i] << endl;
	}
	cout << "----" << endl;
#endif
	vs[0] = 0;
	Rep(i, N){
		ve[i] = vs[i] + t[i];
		ve[i] = min(ve[i], v[i]);
		For(j, i + 1, N + 1){
			int vv = v[j] + T[j] - T[i + 1];
			ve[i] = min(ve[i], vv);
		}
		//cout << ve[i] << endl;
		vs[i + 1] = ve[i];
	}

	float ans = 0;
	Rep(i, N){
		ans += f(t[i], vs[i], ve[i], v[i]);
	}

	printf("%.15lf\n", ans);
	return 0;
}
