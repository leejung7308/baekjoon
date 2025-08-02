#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
long long basic_Tree[100001 * 4];
long long Tree[100001 * 4];
long long lazy[100001 * 4];

long long segment_tree(int node, int st, int fin) {
	if (st == fin) return basic_Tree[node] = 1;
	int mid = (st + fin) / 2;
	long long left = segment_tree(node * 2, st, mid);
	long long right = segment_tree(node * 2 + 1, mid + 1, fin);
	return basic_Tree[node] = (left + right);
}

void change_lazy(int node, int left, int right) {
	if (lazy[node] % 2 == 1) {
		Tree[node] = basic_Tree[node] - Tree[node];
		if (left != right) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void change_tree(int node, int st, int fin, int left, int right) {
	change_lazy(node, st, fin);
	if (left > fin || right < st) return;
	if (left <= st && fin <= right) {
		Tree[node] = basic_Tree[node] - Tree[node];
		if (st != fin) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		return;
	}
	int mid = (st + fin) / 2;
	change_tree(node * 2, st, mid, left, right);
	change_tree(node * 2 + 1, mid + 1, fin, left, right);
	Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}

long long get_sum(int node, int st, int fin, int left, int right) {
	change_lazy(node, st, fin);
	if (left > fin || right < st) return 0;
	if (left <= st && right >= fin) return Tree[node];
	int mid = (st + fin) / 2;
	long long left_sum = get_sum(node * 2, st, mid, left, right);
	long long right_sum = get_sum(node * 2 + 1, mid + 1, fin, left, right);
	return (left_sum + right_sum);
}


void solve() {
	segment_tree(1, 0, N - 1);
	for (int i = 1; i <= M; i++) {
		int a, x, y;
		scanf("%d %d %d", &a, &x, &y);
		if (a == 0) { // x ~ y 까지 상태 반전
			change_tree(1, 0, N - 1, x - 1, y - 1);
		}
		else { // x ~ y 까지 커져있는 스위치 개수
			cout << get_sum(1, 0, N - 1, x - 1, y - 1) << "\n";
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	solve();
	return 0;
}
