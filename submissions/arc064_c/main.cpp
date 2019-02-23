#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

double d[1002][1002];
double x[1002];
double y[1002];
double r[1002];
double cost[100
2];
int done[1002] = {0};

int main(void)
{
	cin >> x[0] >> y[0];
	double xt, yt;
	cin >> xt >> yt;
	int N;
	cin >> N;
	x[N + 1] = xt;
	y[N + 1] = yt;

	Rep(i, N){
		cin >> x[i + 1] >> y[i + 1] >> r[i + 1];
	}
	Rep(a, N + 2){
		cost[a] = -1;
		Rep(b, N + 2){
			double dd = sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2)) - r[a] - r[b];
			if(dd < 0) dd = 0;
			d[a][b] = d[b][a] = dd;
		}
	}

	cost[0] = 0;
	while(1){
		int p = -1;
		Rep(i, N + 2){
			if(done[i] || cost[i] < 0){
				continue;
			}

			if(p == -1){
				p = i;
			}else if(cost[i] < cost[p]){
				p = i;
			}
		}

		if(p == -1){
			break;
		}

		done[p] = 1;

		Rep(i, N + 2){
			if(i == p) continue;
			double cost_ = cost[p] + d[p][i];
			if(cost[i] < 0 || cost[i] > cost_){
				cost[i] = cost_;
			}
		}
	}

	printf("%.10f\n", cost[N + 1]);
	return 0;
}
