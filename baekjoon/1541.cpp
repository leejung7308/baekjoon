//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	string op;
//	cin >> op;
//	int i = 0, ans = 0; 
//	string num;
//	while (isdigit(op[i])) {
//		num.push_back(op[i++]);
//	}
//	ans += stoi(num);
//	int neg = 0;
//	bool isneg = false;
//	while (i < op.size()) {
//		num.clear();
//		if (op[i] == '+') {
//			if (isneg) num.push_back('-');
//		}
//		else if (op[i] == '-') {
//			isneg = true;
//			num.push_back('-');
//		}
//		i++;
//		while (isdigit(op[i])) {
//			num.push_back(op[i++]);
//		}
//		ans += stoi(num);
//	}
//	cout << ans;
//}