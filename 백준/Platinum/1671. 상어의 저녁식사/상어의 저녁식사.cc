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
struct shark { 
    int size, speed, iq; 
    bool operator<= (const shark& a) {
        if (this->size <= a.size && this->speed <= a.speed && this->iq <= a.iq) return true;
        else return false;
    }
};
int n;
vector<shark> sharks;
vector<vector<int>> canEat;
vector<int> whoAte;
vector<bool> visited;
bool tryEat(int shark) {
    for (int eat : canEat[shark]) {
        if (visited[eat]) continue;
        visited[eat] = true;
        if (whoAte[eat] == shark) continue;
        if (whoAte[eat] == -1 || tryEat(whoAte[eat])) {
            whoAte[eat] = shark;
            return true;
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> n;
    canEat.resize(n);
    visited.resize(n);
    whoAte = vector<int>(n, -1);
    for (int i = 0; i < n; i++) {
        shark cur;
        cin >> cur.size >> cur.speed >> cur.iq;
        for (int j = 0; j < sharks.size(); j++) {
            if (sharks[j] <= cur) canEat[i].push_back(j);
            else if (cur <= sharks[j]) canEat[j].push_back(i);
        }
        sharks.push_back(cur);
    }
    for (int i = 0; i < canEat.size(); i++) {
        visited = vector<bool>(canEat.size());
        if (tryEat(i)) n--;
        visited = vector<bool>(canEat.size());
        if (tryEat(i)) n--;
    }
    cout << n;
}