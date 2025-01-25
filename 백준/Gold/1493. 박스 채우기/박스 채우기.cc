#include<bits/stdc++.h>
#include<unordered_map>
#define INF 987654321
using namespace std;
int cube[20], cnt = 0;
bool flag = true;
void box(int length, int width, int height) {
	if (length == 0 || width == 0 || height == 0) return;
	int power = (int)log2(min({ length,width,height }));
	for (int i = power; i >= 0; i--) {
		if (cube[i] > 0) {
			cnt++;
			cube[i]--;
			int len = pow(2, i);
			box(length, width - len, height);
			box(len, len, height - len);
			box(length - len, len, height);
			return;
		}
	}
	flag = false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, length, width, height;
	cin >> length >> width >> height >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cube[a] = b;
	}
	box(length, width, height);
	if (flag) cout << cnt;
	else cout << -1;
}