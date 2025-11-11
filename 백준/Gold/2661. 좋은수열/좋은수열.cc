#include <bits/stdc++.h>
#include <unordered_map>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
#define DIR8 const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int, int>
#define MAX 1000000
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
int n;
void Solution(int cnt, const string& s) {
    int len = s.size();
    int half = len / 2;
    for (int i = 1; i <= half; i++) {
        string first = s.substr(len - i, i);
        string second = s.substr(len - (i * 2), i);
        if (first == second) return;
    }
    if (cnt == n) {
        cout << s;
        exit(0);
    }
    Solution(cnt + 1, s + '1');
    Solution(cnt + 1, s + '2');
    Solution(cnt + 1, s + '3');
}
void Input() {
    cin >> n;
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution(0, "");
    }
}