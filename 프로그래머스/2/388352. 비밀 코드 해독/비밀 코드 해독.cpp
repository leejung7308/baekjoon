#include <string>
#include <vector>

using namespace std;
bool check(int pwd, const vector<vector<int>>& q, const vector<int>& ans){
    for(int i = 0; i < q.size(); i++){
        int cmp = 0, cnt = 0;
        for(int bit : q[i]) cmp += (1 << bit);
        cnt = __builtin_popcount(pwd & cmp);
        if(cnt != ans[i]) return false;
    }
    return true;
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    int pwd = 0;
    for(int i=1; i<=n-4; i++)
    {
        for(int j=i+1; j<=n-3; j++)
        {
            for(int k=j+1; k<=n-2; k++)
            {
                for(int l=k+1; l<=n-1; l++)
                {
                    for(int m=l+1; m<=n; m++)
                    {
                        pwd = (1 << i) | (1 << j) | (1 << k) | (1 << l) | (1 << m);
                        if(check(pwd, q, ans)) answer++;
                    }
                }
            }
        }
    }
    return answer;
}