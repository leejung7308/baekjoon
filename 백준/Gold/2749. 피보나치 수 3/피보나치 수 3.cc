#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> memo(1500001);
int fibo(int n) {
	if (memo[n] != 0) return memo[n];
	if (n == 1) return 1;
	if (n == 0) return 0;
	return memo[n] = (fibo(n - 1) + fibo(n - 2)) % 1000000;
}
int main() {
	FAST_IO;
	long long n;
	cin >> n;
	cout << fibo(n % 1500000);
}