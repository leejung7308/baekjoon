//#include<bits/stdc++.h>
//using namespace std;
//vector<bool> all(21, true);
//vector<bool> vst(21);
//void op(string o, int x) {
//	if (o == "add") vst[x] = true;
//	else if (o == "remove") vst[x] = false;
//	else if (o == "check") {
//		cout << vst[x] << '\n';
//	}
//	else if (o == "toggle") {
//		vst[x] = !vst[x];
//	}
//	else if (o == "all") {
//		vst = all;
//	}
//	else if (o == "empty") vst = vector<bool>(20);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int m;
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		string t1;
//		int t2 = -1;
//		cin >> t1;
//		if (!(t1 == "all" || t1 == "empty")) cin >> t2;
//		op(t1, t2);
//	}
//}