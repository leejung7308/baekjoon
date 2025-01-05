//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, min, max, prev;
//	int tmp;
//	cin >> n;
//	cin >> tmp;
//	min = max = tmp;
//	n--;
//	prev = -1;
//	while (n--) {
//		cin >> tmp;
//		if (tmp < min) {
//			if (prev < (max - min)) prev = max - min;
//			min = max = tmp;
//		}
//		else if (tmp > max) max = tmp;
//	}
//	cout << std::max(prev, max - min);
//}