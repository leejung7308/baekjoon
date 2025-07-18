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
struct trie { map<char, trie> children; };
unordered_map<string, int> v;
trie* root;
int n;
double avg = 0;
void addinput(string s, trie* cur, int cnt)
{
    int d = cur->children.size() == 1 ? 0 : 1;
    for (auto& p : cur->children)
    {
        if (p.first == ' ') {
            avg += cnt;
            continue;
        }
        addinput(s + p.first, &p.second, cnt + d);
    }
}
int main()
{
    FAST_IO;
    while (true)
    {
        cin >> n;
        if (cin.eof()) return 0;
        avg = 0;
        root = new trie();
        v = unordered_map<string, int>();
        for (int i = 0; i < n; i++)
        {
            trie* cur = root;
            string tmp;
            cin >> tmp;
            tmp += ' ';
            for (int i = 0; i < tmp.size(); i++)
            {
                if (cur->children.find(tmp[i]) == cur->children.end())
                    cur->children[tmp[i]] = trie();
                cur = &cur->children[tmp[i]];
            }
        }
        string s;
        trie* cur = root;
        for (auto& p : cur->children)
        {
            addinput(s + p.first, &p.second, 1);
        }
        cout << fixed << setprecision(2) << avg / (double)n << '\n';
        delete (root);
    }
}