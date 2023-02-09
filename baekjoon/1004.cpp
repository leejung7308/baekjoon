#include <stdio.h>
int sqrt(int a, int b) {
	return a * a + b * b;
}
int main() {
	int T, a, b, c, d, n, x[50], y[50], r[50], cnt=0;
	scanf("%d", &T);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	for(int j=0;j<T;j++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x[i], &y[i], &r[i]);
			if ((sqrt(x[i] - a, y[i] - b) < r[i] * r[i]) && (sqrt(x[i] - c, y[i] - d) > r[i] * r[i])) {
				cnt++;
			}
			else if ((sqrt(x[i] - a, y[i] - b) > r[i] * r[i]) && (sqrt(x[i] - c, y[i] - d) < r[i] * r[i])) {
				cnt++;
			}
		}
	}
}