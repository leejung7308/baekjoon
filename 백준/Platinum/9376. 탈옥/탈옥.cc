#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#define P pair<int, int>
#define PP pair<int, P>
#define F first
#define S second
#define INF 987654321

using namespace std;

int test_case;
int N, M;
char map[105][105];
int Distance[3][105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<P> start;

void reset_distance(){
    for(int k = 0; k < 3; k++){
        for(int i = 0; i <= N+1; i++){
            for(int j = 0; j <= M+1; j++){
                Distance[k][i][j] = INF;
            }
        }
    }
}

void Dijstra(P X, int cnt){
    priority_queue<PP> q;
    q.push({-0, X});
    Distance[cnt][X.F][X.S] = 0;
    while(!q.empty()){
        int x = q.top().S.F;
        int y = q.top().S.S;
        int cost = -q.top().F;
        q.pop();
        if(Distance[cnt][x][y] < cost) continue;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx <= N+1 && yy >= 0 && yy <= M+1){
                if(map[xx][yy] == '*') continue;
                if(map[xx][yy] == '#'){
                    if(Distance[cnt][xx][yy] > cost + 1){
                        Distance[cnt][xx][yy] = cost + 1;
                        q.push({-(cost + 1), {xx, yy}});
                    }
                }
                else if(map[xx][yy] == '.' || map[xx][yy] == '$'){
                    if(Distance[cnt][xx][yy] > cost){
                        Distance[cnt][xx][yy] = cost;
                        q.push({-cost, {xx, yy}});
                    }
                }
            }
        }
    }
}

void solve(){
    long long int ans = INF;
    reset_distance();
    for(int i = 0; i < 3; i++){
        Dijstra(start[i], i);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(map[i][j] == '*') continue;
            long long int sum = Distance[0][i][j] + Distance[1][i][j] + Distance[2][i][j];
            if(map[i][j] == '#') sum -= 2;
            if(sum >= 0) ans = min(ans, sum);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin >> test_case;
    for(int k = 1; k <= test_case; k++){
        start.clear();
        cin >> N >> M;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                cin >> map[i][j];
                if(map[i][j] == '$'){
                    start.push_back({i,j});
                }
            }
        }
        for(int i = 0; i <= N+1; i++){
            map[i][0] = '.';
            map[i][M+1] = '.';
        } 
        for(int i = 0; i <= M+1; i++){
            map[0][i] = '.';
            map[N+1][i] = '.';
        } 
        start.push_back({0, 0});
        solve();
    }
    return 0;
}