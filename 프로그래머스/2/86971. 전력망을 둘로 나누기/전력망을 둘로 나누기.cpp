#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n+1;
    vector<vector<int>> v(n + 1);
    for(const vector<int>& w : wires){
        v[w[0]].push_back(w[1]);
        v[w[1]].push_back(w[0]);
    }
    for(const vector<int>& w : wires){
        vector<bool> visited(n + 1);
        visited[w[0]]=visited[w[1]]=true;
        queue<pair<int,int>> q;
        int cnt1=1,cnt2=1;
        q.push({w[0],w[0]});
        q.push({w[1],w[1]});
        while(!q.empty()){
            int cur = q.front().first;
            int root = q.front().second;
            q.pop();
            for(int i : v[cur]){
                if(visited[i]) continue;
                if(root==w[0]) cnt1++;
                else cnt2++;
                visited[i]=true;
                q.push({i,root});
            }
        }
        answer = min(answer, abs(cnt1-cnt2));
    }
    return answer;
}