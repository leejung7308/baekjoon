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

int main() {
    FAST_IO;
    int x;
    cin >> x;
    int n;
    cin >> n;
    int sum = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }
    if (sum == x) cout << "Yes\n";
	else cout << "No\n";
}