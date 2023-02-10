#include<stdio.h>
int main() {
	int T, N, M;
	int res;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		res = 1;
		scanf("%d %d", &N, &M);
		if (M - N < N) N = M - N;
		for (int j = 1; j <=N; j++) {
			res *= M--;
			res /= j;
		}
		printf("%d\n", res);
	}
	return 0;
}
