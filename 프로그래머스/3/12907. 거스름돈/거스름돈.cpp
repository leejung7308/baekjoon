#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<long long> dp(n+1);
    dp[0]=1;
    for(int i=0;i<money.size();i++){
        for(int j=money[i];j<dp.size();j++){
            dp[j] += dp[j-money[i]];
            dp[j] %= 1000000007;
        }
    }
    answer = dp[n];
    return answer;
}