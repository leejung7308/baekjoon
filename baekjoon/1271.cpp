//#include<bits/stdc++.h>
//using namespace std;
//int isBigger(string a, string b) {
//	if (a.length() > b.length()) return 1;
//	else if (a.length() < b.length()) return 0;
//	for (int i = 0; i < a.length(); i++) {
//		if (a[i] == b[i]) continue;
//		else if (a[i] < b[i]) return 0;
//		else if (a[i] > b[i]) return 1;
//	}
//	return 2;
//}
//string strMinus(string a, string b) {
//	string ret;
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//	ret = a;
//	for (int i = 0; i < b.length(); i++) {
//		if (ret[i] - b[i] < 0) {
//			ret[i] -= b[i] - '0';
//			ret[i] += 10;
//			ret[i + 1] -= 1;
//		}
//		else {
//			ret[i] -= b[i] - '0';
//		}
//	}
//	for (int i = ret.length() - 1; i > 0; i--) {
//		if (ret[i] != '0') break;
//		else {
//			ret.pop_back();
//		}
//	}
//	reverse(ret.begin(), ret.end());
//	return ret;
//}
//string strPlus(string a, string b) {
//	string ret;
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//	ret = a;
//	for (int i = 0; i < b.length(); i++) {
//		if (i == ret.length()) ret.push_back('0');
//		if (ret[i] + b[i] - '0' * 2 > 9) {
//			if (i + 1 == ret.length()) ret.push_back('0');
//			ret[i + 1] += 1;
//			ret[i] += b[i] - '0' - 10;
//		}
//		else {
//			ret[i] += b[i] - '0';
//		}
//	}
//	for (int i = 0; i < ret.length(); i++) {
//		if (ret[i] - '0' > 9) {
//			if (i + 1 == ret.length()) ret.push_back('0');
//			ret[i + 1] += 1;
//		}
//	}
//	reverse(ret.begin(), ret.end());
//	return ret;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	string n, m, tmp;
//	string ans = "0";
//	cin >> n >> m;
//	while (true) {
//		string cnt = "1";
//		tmp = m;
//		for (int i = 0; i < n.length() - m.length(); i++) {
//			tmp.push_back('0');
//			cnt.push_back('0');
//		}
//		switch (isBigger(tmp, n)) {
//		case 0:
//			n = strMinus(n, tmp);
//			ans = strPlus(ans, cnt);
//			break;
//		case 1:
//			tmp.pop_back();
//			cnt.pop_back();
//			n = strMinus(n, tmp);
//			ans = strPlus(ans, cnt);
//			break;
//		case 2:
//			n = strMinus(n, tmp);
//			ans = strPlus(ans, cnt);
//			break;
//		}
//		if (isBigger(m, n) == 1) break;
//	}
//	cout << ans << endl << n << endl;
//}