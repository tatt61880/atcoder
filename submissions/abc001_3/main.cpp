#include <stdio.h>

int main(void)
{
	int Deg, Dis;
	scanf("%d%d", &Deg, &Dis);

	char Dir[16][4] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
					   "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "N
NW"};
	int W;

	int Di = 0;
	for(Di = 0; Di < 16; Di++){
		if(1125 + 2250 * (Di - 1) <= Deg * 10 && Deg * 10 < 3375 + 2250 * (Di - 1)){
			break;
		}
	}

	int W_[] = {25, 155, 335, 545, 795, 1075, 1385, 1715, 2075, 2445, 2845, 3265};
	for(W = 0; W < 12; W++){
		if(Dis * 10 < W_[W] * 6){
			break;
		}
	}

	printf("%s %d\n", W ? Dir[Di % 16] : "C", W);
	return 0;
}
