#include <bits/stdc++.h>
using namespace std;

bool adj[501][501];
int degree[501];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {

        memset(adj, 0, sizeof(adj));
        memset(degree, 0, sizeof(degree));
        int n;
        cin >> n;

        vector<int> pre;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            pre.push_back(tmp);
        }

		for (int i = 0; i < pre.size(); i++) {
            for (int j = i + 1; j < pre.size(); j++) {
                adj[pre[i]][pre[j]] = 1;
                degree[pre[j]]++;
            }
        }

        int m;
        cin >> m;


        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if (adj[a][b] == 1) {
                adj[a][b] = 0;
                degree[b]--;
                adj[b][a] = 1;
                degree[a]++;
            }
            else {
                degree[a]--;
                adj[b][a] = 0;
                adj[a][b] = 1;
                degree[b]++;
            }
        }

        
        queue<int> Q;

        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                Q.push(i);
            }
        }

        vector<int> ans;

        bool cantKnow = false;

        while (!Q.empty()) {

            if (Q.size() >= 2) {
                cantKnow = true;
                break;
            }

            int x = Q.front(); Q.pop();
            ans.push_back(x);

            for (int i = 1; i <= n; i++) {
                if (adj[x][i] == 1) {
                    int nx = i;

                    if (--degree[nx] == 0) {
                        Q.push(nx);
                    }

                }
            }
        }

        if (cantKnow) {
            cout << "?\n";
            continue;
        }


        if (ans.size()!=n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        else {
			for (auto x : ans) {
				cout << x << ' ';
			}
			cout << '\n';
        }


    }
  
    return 0;
}