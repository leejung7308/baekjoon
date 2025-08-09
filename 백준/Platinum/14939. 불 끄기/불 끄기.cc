#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
#define DIR8 const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int, int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
vector<int> v;
int bitcount(int x) {
    int ret = 0;
    while (x > 0) {
        if (x & 1)ret++;
        x >>= 1;
    }
    return ret;
}
int main() {
    FAST_IO;
    for (int i = 0; i < 10; i++) {
        string tmp;
        int bit = 0;
        cin >> tmp;
        for (int j = 0; j < 10; j++) {
            bit <<= 1;
            if (tmp[j] == 'O') bit += 1;
        }
        v.push_back(bit);
    }
    int ans = INF;
    for (int i = 0; i < 1024; i++) {
        int cnt = 0;
        int prev = i;
        int cur = v[0];
        int next;
        for (int j = 0; j < 9; j++) {
            next = v[j + 1];
            cnt += bitcount(prev);
            next ^= prev;
            cur ^= prev;
            cur ^= ((prev << 1) & 1023);
            cur ^= prev >> 1;
            prev = cur;
            cur = next;
        }
        cnt += bitcount(prev);
        cur ^= prev;
        cur ^= (prev << 1) & 1023;
        cur ^= prev >> 1;
        if (cur == 0) ans = min(ans, cnt);
    }
    cout << ans;
}