#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i <= (int)(b); ++i)

ll a[100000];
ll Temp[100000];
ll ans = 0;

void MergeSort(int left, int right)
{
	if(right - left < 2){
		if(a[left] > a
[right]){
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			ans++; // 莠､蟾ｮ轤ｹ縺・縺､縺ｻ縺ｩ縺代∪縺・
		}
		return;
	}

	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);

	//{ 蟾ｦ蜊雁・縺ｯ縺昴・縺ｾ縺ｾTemp縺ｫ繧ｳ繝斐・縺励∪縺吶・}
	For(i, left, mid){
		Temp[i] = a[i];
	}
	//{ 蜿ｳ蜊雁・縺ｯ騾・・〒Temp縺ｫ繧ｳ繝斐・縺励∪縺吶・}
	int j = right;
	For(i, mid + 1, right){
		Temp[i] = a[j];
		j--;
	}

	int l = left;
	int r = right;
	For(i, left, right){
		if(Temp[l] > Temp[r]){
			ans += mid - l + 1; //{ @Temp[r]縺悟ｷｦ蜊雁・縺ｮ蜿ｳ縺九ｉ(mid - l + 1)蛟九・謨ｰ繧定ｷｨ縺・〒縲・mid - l + 1)蛟九・莠､蟾ｮ轤ｹ縺後⊇縺ｩ縺代∪縺吶・}
			a[i] = Temp[r];
			r--;
		}else{
			a[i] = Temp[l];
			l++;
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	Rep(i, N){
		cin >> a[i];
	}

	MergeSort(0, N - 1);
	PrintLn(ans);
	return 0;
}
