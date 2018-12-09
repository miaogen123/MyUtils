#include"math.h"
#include<vector>


long long getIntInverse(long long a, long long b) {
	using LL = long long;
	LL N = a;
	LL midV = 0;
	std::vector<long long > inverseList;
	while (true) {
		midV = a % b;
		if (midV == 0)
			break;
		a = (LL)(a / b);
		inverseList.push_back(a);
		a = b;
		b = midV;
	}
	LL bi_2 = 1, bi_1=inverseList.back(), bi=0;
	for (int i = inverseList.size() - 2; i >= 0; i--) {
		bi = bi_1 * inverseList[i] + bi_2;
		bi_2 = bi_1;
		bi_1 = bi;
	}
	if (inverseList.size() % 2 == 0) {
		return bi;
	}
	else {
		return N - bi;
	}
}

