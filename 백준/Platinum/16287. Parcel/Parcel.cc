#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pii pair<int, int>
int v[5001];
int memo[800000][2];
int main() {
    FAST_IO;
    int w, n;
    cin >> w >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) {
        if (v[i] + v[j] < w && memo[w - (v[i] + v[j])][0] != 0) {
            int a = memo[w - v[i] - v[j]][0], b = memo[w - v[i] - v[j]][1];
            if (a != i && a != j && b != i && b != j) {
                cout << "YES";
                return 0;
            }
        }
        if (v[i] + v[j] < w) {
            memo[v[i] + v[j]][0] = i;
            memo[v[i] + v[j]][1] = j;
        }
    }
    cout << "NO";
}