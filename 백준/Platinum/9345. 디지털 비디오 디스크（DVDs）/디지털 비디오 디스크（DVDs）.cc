#define pii pair<int,int>
#define INF 987654321
#include <iostream>
using namespace std;

int minseg[400002];
int maxseg[400002];
int arr[100002];
int N,M;

void update(int node){
	maxseg[node] = max(maxseg[node * 2], maxseg[node * 2 + 1]);
	minseg[node] = min(minseg[node * 2], minseg[node * 2 + 1]);
	return;
}

void makeSeg(int str, int end, int node) {
	if (str == end) {
		minseg[node] = arr[str];
		maxseg[node] = arr[str];
		return;
	}
	else {
		int mid = (str + end) / 2;
		makeSeg(str, mid, node * 2);
		makeSeg(mid + 1, end, node * 2 + 1);
		update(node);
		return;
	}
}

void UpdateSeg(int str, int end, int node, int idx) {
	if (str == end) {
		minseg[node] = arr[str];
		maxseg[node] = arr[str];
	}
	else {
		int mid = (str + end) / 2;
		
		if (idx <= mid) {
			UpdateSeg(str, mid, node * 2, idx);
		}
		else {
			UpdateSeg(mid + 1, end, node * 2 + 1, idx);
		}
		update(node);
	}
	return;
}

pii getRange(int str, int end, int l, int r, int node) { //{큰 값, 작은 값}
	if (str > r || end < l) return { -INF,INF };
	if (str >= l && end <= r) return { maxseg[node],minseg[node] };
	int mid = (str + end) / 2;
	pii tmp1 = getRange(str, mid, l, r, node * 2);
	pii tmp2 = getRange(mid + 1, end, l, r, node * 2 + 1);
	return { max(tmp1.first,tmp2.first),min(tmp1.second,tmp2.second) };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			arr[i] = i;
		}
		makeSeg(0, N - 1, 1);


		for (int i = 0; i < M; i++) {
			int Q, a, b;
			cin >> Q >> a >> b;
			//a--; b--;
			if (Q == 0) {//선반 바꿔끼우기.
				swap(arr[a], arr[b]);
				UpdateSeg(0, N - 1, 1, a);
				UpdateSeg(0, N - 1, 1, b);
			}
			else { //책을 빌리기
				pii ans = getRange(0, N - 1, a, b, 1);
				
				if (ans.first == b && ans.second == a) {
					cout << "YES\n";
				}
				else cout << "NO\n";
			}
		}
		
	}
}