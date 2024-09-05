//#include<iostream>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	unordered_map<long long, int> soldier;
//	long long ground = 0;
//	long long num = 0;
//	cin >> ground;
//	for (int i = 0; i < ground; i++) {
//		bool find = false;
//		long long ans;
//		cin >> num;
//		for (int j = 0; j < num; j++) {
//			long long tmp;			
//			cin >> tmp;
//			soldier[tmp]++;
//			if (soldier[tmp] > num / 2) {
//				find = true;
//				ans = tmp;
//			}
//		}
//		if (!find) cout << "SYJKGW" << endl;
//		else cout << ans << endl;
//		soldier.clear();
//	}
//}
