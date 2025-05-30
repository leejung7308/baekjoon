#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
int solution(int N, int number) {
    if(N == number) return 1;
	int tmp = N;
	vector<unordered_set<int>> dp(9);
	for (int i = 1; i <= 8; i++) {
		dp[i].insert(tmp);
		tmp *= 10;
		tmp += N;
	}
	for (int i = 2; i <= 8; i++) {
		for (int j = 1; j < i; j++) {
			for (int a : dp[j]) for (int b : dp[i - j]) {
				dp[i].insert(a + b);
				dp[i].insert(a - b);
			    dp[i].insert(a * b);
                if(b != 0) dp[i].insert(a / b);
			}
		}
		if (dp[i].find(number) != dp[i].end()) {
			return i;
		}
	}
	return -1;
}