#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> v) {
    int answer = 0;
    vector<vector<int>> dp(v.size(),vector<int>(v.size(),2000000000));
    for(int i=0;i<v.size();i++) dp[i][i]=0;
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v.size() - 1;j++){
            if(j+i>=v.size()) break;
            for(int k=j;k<j+i;k++){
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+v[j][0]*v[k][1]*v[j+i][1]);
            }
        }
    }
    answer = dp[0][v.size()-1];
    return answer;
}