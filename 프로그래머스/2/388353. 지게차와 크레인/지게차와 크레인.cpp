#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int truck(vector<string>& s, vector<vector<bool>>& r, char rq){
    pair<int,int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    int w = s[0].size(), h = s.size();
    int ret = 0;
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(h, vector<bool>(w));
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()){
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        for(const pair<int,int>& d : dir){
            int ny = cy + d.first, nx = cx + d.second;
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            if(!r[ny][nx]){
                if(s[ny][nx] == rq){
                    ret++;
                    s[ny][nx] = ' ';
                    r[ny][nx] = true;
                }
                continue;
            }
            q.push({ny,nx});
        }
    }
    return ret;
}
int crane(vector<string>& s, vector<vector<bool>>& r, char rq){
    int w = s[0].size(), h = s.size();
    int ret = 0;
    for(int i = 1; i < h - 1; i++){
        for(int j = 1; j < w - 1; j++){
            if(r[i][j]) continue;
            if(s[i][j] != rq) continue;
            s[i][j] = ' ';
            r[i][j] = true;
            ret++;
        }
    }
    return ret;
}
int solution(vector<string> storage, vector<string> requests) {
    int w = storage[0].size(), h = storage.size();
    int answer = w * h;
    vector<vector<bool>> removed(h + 2, vector<bool>(w + 2, true));
    vector<string> ns(h + 2, string(w + 2, ' '));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            ns[i + 1][j + 1] = storage[i][j];
            removed[i + 1][j + 1] = false;
        }
    }
    for(const string& s : requests){
        if(s.size() == 2) answer -= crane(ns, removed, s[0]);
        else answer -= truck(ns, removed, s[0]);
    }
    return answer;
}