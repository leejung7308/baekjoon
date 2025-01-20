#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
string m = "moo";
void moo(int x, int size, int k) {
	if (size == 3) {
		cout << m[x - 1];
		return;
	}
	int half = (size - (k + 3)) / 2;
	if (x == half + 1) {
		cout << 'm';
		return;
	}
	if (x > half + 1 && x < half + (k + 4)) {
		cout << 'o';
		return;
	}
	if (x <= half) return moo(x, half, k-1);
	if (x > half + (k + 3)) return moo(x - (half + (k+3)), half, k - 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int s = 3, i = 1;
	while (s < n) {
		s *= 2;
		s += i++ + 3;
	}
	moo(n, s, i - 1);
}