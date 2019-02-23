#include <stdio.h>

#if 0
    0.1km 未満： VVの値は 00 とする。
    0.1km 以上 5km 以下：距離 (km) を 10 倍した値とする。1 桁の場合は上位に 0 を付す。
        例えば、2,000m =2.0km ならば、VVは 20 である。同じく、200mの場合VVは 02 である。
    6km 以上 30km 以下：距離 (km) に 50 を足した値とする。
        例えば、15,000m =15km ならば、VVは 65 である。
    35km 以上 70km 以下：距離 (km) から 30 を引いて 5 で割った後、80 を足した値とする。
        例えば、40,000m =40
km ならば、VVは 82 である。
    70km より大きい：VVの値は 89 とする。
#endif
int main(void)
{
	int m;
	int VV;
	scanf("%d", &m);
	if(m < 100){
		VV = 0;
	}else if(m <= 5000){
		VV = m / 100;
	}else if(m <= 30000){
		VV = 50 + m / 1000;
	}else if(m <= 70000){
		VV = (m / 1000 - 30) / 5 + 80;
	}else{
		VV = 89;
	}
	printf("%02d\n", VV);
	return 0;
}
