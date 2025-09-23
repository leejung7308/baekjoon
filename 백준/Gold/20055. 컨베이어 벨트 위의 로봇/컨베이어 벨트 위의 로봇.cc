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
int n, k, front, back, cnt, answer;
vector<int> durability;
vector<bool> robot;
void First() {
    if (front == 0) front = 2 * n - 1;
    else front--;
    if (back == 0) back = 2 * n - 1;
    else back--;
    if (robot[back]) robot[back] = false;
}
void Second() {
    int idx = back;
    while (idx != front) {
        if (robot[idx]) {
            int nidx = idx == 2 * n - 1 ? 0 : idx + 1;
            if (robot[nidx] == false && durability[nidx] != 0) {
                robot[idx] = false;
                robot[nidx] = true;
                durability[nidx]--;
                if (durability[nidx] == 0) cnt++;
            }
        }
        idx = idx == 0 ? 2 * n - 1 : idx - 1;
    }
    if (robot[back]) robot[back] = false;
}
void Third() {
    if (durability[front] == 0) return;
    robot[front] = true;
    durability[front]--;
    if (durability[front] == 0) cnt++;
}
void Fourth() {
    if (cnt >= k) cout << answer;
}
int main() {
    FAST_IO;
    cin >> n >> k;
    front = 0, back = n - 1, cnt = 0, answer = 0;
    durability.resize(n * 2);
    robot.resize(n * 2);
    for (int i = 0; i < 2 * n; i++) cin >> durability[i];
    while (cnt < k) {
        answer++;
        First();
        Second();
        Third();
        Fourth();
    }
}