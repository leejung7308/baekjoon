#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>  // pair
#include <tuple>
#include <stack>
// #include <map>
#include <unordered_map>
#define ll long long
#define INF 1e9
using namespace std;

int ans = 0;
int n,m,k;
int sz[21][21];
int dir[21][21];
pair<int,int> smell[21][21];  // <size, remaining second>
pair<int,int> pos[401];  // shark location
int preference[401][5][5];  // 400 sharks at max, four directions each
int dr[] = {0,-1,1,0,0};
int dc[] = {0,0,0,-1,1};


void chooseCell(int i, int r, int c, pair<int,int> smell_[21][21], int sz_[21][21], int dir_[21][21]) {
	int direction = dir[r][c];
	int nr,nc;
	for(int d=1;d<=4;++d) {
		int preferredDir = preference[i][direction][d];
		nr = r+dr[preferredDir];
		nc = c+dc[preferredDir];

		if(!(1<=nr&&nr<=n && 1<=nc&&nc<=n)) continue;

		pair<int,int>& p = smell[nr][nc];
		if(!p.first && !p.second) {
			if(sz_[nr][nc]) {
				if(sz[r][c] < sz_[nr][nc]) {
					sz_[nr][nc] = sz[r][c];
					dir_[nr][nc] = preferredDir;

					pos[i].first = nr;
					pos[i].second = nc;

					smell_[nr][nc].first = sz_[nr][nc];
					smell_[nr][nc].second = k;
				} else {
					pos[i].first = 0;
					pos[i].second = 0;
				}
			} else {
				sz_[nr][nc] = sz[r][c];
				dir_[nr][nc] = preferredDir;

				pos[i].first = nr;
				pos[i].second = nc;
				smell_[nr][nc].first = sz_[nr][nc];
				smell_[nr][nc].second = k;
			}
			sz_[r][c] = 0;
			dir_[r][c] = 0;

			break;
		}
	}
	return;
}

void chooseCellMySmell(int i, int r, int c, pair<int,int> smell_[21][21], int sz_[21][21], int dir_[21][21]) {
	int direction = dir[r][c];
	for(int d=1;d<=4;++d) {
		int preferredDir = preference[i][direction][d];
		int nr = r+dr[preferredDir];
		int nc = c+dc[preferredDir];

		if(!(1<=nr&&nr<=n && 1<=nc&&nc<=n)) continue;

		pair<int,int>& p = smell[nr][nc];
		if(p.first == sz[r][c]) {  // my smell
			if(sz_[nr][nc]) {
				if(sz[r][c] < sz_[nr][nc]) {
					sz_[nr][nc] = sz[r][c];
					dir_[nr][nc] = preferredDir;

					pos[i].first = nr;
					pos[i].second = nc;
					smell_[nr][nc].first = sz_[nr][nc];
					smell_[nr][nc].second = k;
				} else {
					pos[i].first = 0;
					pos[i].second = 0;
				}
			} else {
				sz_[nr][nc] = sz[r][c];
				dir_[nr][nc] = preferredDir;

				pos[i].first = nr;
				pos[i].second = nc;
				smell_[nr][nc].first = sz_[nr][nc];
				smell_[nr][nc].second = k;
			}
			sz_[r][c] = 0;
			dir_[r][c] = 0;

			break;
		}
	}
	return;
}

void sol() {

	// 1. smell
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(sz[i][j]) {
				pair<int,int>& p = smell[i][j];
				p.first = sz[i][j];
				p.second = k;
			}
		}
	}

	// 2. move sharks & smell disperse
	int sz_[21][21], dir_[21][21];
	pair<int,int> smell_[21][21];
	copy(&smell[0][0], &smell[0][0]+441, &smell_[0][0]);
	copy(&sz[0][0], &sz[0][0]+441, &sz_[0][0]);
	copy(&dir[0][0], &dir[0][0]+441, &dir_[0][0]);
	for(int i=1;i<=m;++i) {
		int r = pos[i].first;
		int c = pos[i].second;

		int available = 0;
		int nextR, nextC;
		for(int d=1;d<=4;++d) {
			int nr = r+dr[d];
			int nc = c+dc[d];

			if(!(1<=nr&&nr<=n && 1<=nc&&nc<=n)) continue;

			pair<int,int>& p = smell[nr][nc];
			if(!p.first && !p.second) {  // no smell
				available++;
				nextR = nr;
				nextC = nc;
			}
		}

		if(available >= 1) {
			chooseCell(i,r,c,smell_,sz_,dir_);
		} else if(!available) {
			// my smell
			chooseCellMySmell(i,r,c,smell_,sz_,dir_);
		}

	}
	copy(&smell_[0][0], &smell_[0][0]+441, &smell[0][0]);
	copy(&sz_[0][0], &sz_[0][0]+441, &sz[0][0]);
	copy(&dir_[0][0], &dir_[0][0]+441, &dir[0][0]);

	for(int i=1;i<=m;++i) {
		int r = pos[i].first;
		int c = pos[i].second;

		for(int j=1;j<=n;++j) {
			for(int k=1;k<=n;++k) {
				if(j==r && k==c) continue;
				if(!smell[j][k].second) continue;
				if(smell[j][k].first == i) {
					if(--smell[j][k].second == 0) {
						smell[j][k].first = 0;
					}
				}
			}
		}
	}

	return;
}

int main(void) {
	// ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			scanf("%d", &sz[i][j]);
			if(sz[i][j]) {
				int size = sz[i][j];
				pos[size].first = i;
				pos[size].second = j;
			}
		}
	}
	for(int i=1;i<=m;++i) {
		int r,c;
		r = pos[i].first;
		c = pos[i].second;

		scanf("%d", &dir[r][c]);
	}


	for(int i=1;i<=m;++i) {
		for(int j=1;j<=4;++j) {
			for(int k=1;k<=4;++k) {
				scanf("%d", &preference[i][j][k]);
			}
		}
	}

	while(ans <= 1000) {
		sol();
		ans++;

		int finish = 1;
		for(int j=2;j<=m;++j) {
			if(pos[j].first || pos[j].second) {
				finish = 0;
			}
		}

		if(finish) {
			break;
		}
	}

	ans = ans <= 1000 ? ans : -1;
	printf("%d\n", ans);
	
	return 0;
}