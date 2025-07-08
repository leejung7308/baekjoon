#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, ret;

int main() {

  cin >> n;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end());

  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if(pq.size() > v[i].first) pq.pop();
  }

  while(pq.size()) {
    ret += pq.top();
    pq.pop();
  }
  cout << ret << "\n";
  
  return 0;
}