//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//vector<vector<int>> in(1000001), out(1000001);
//vector<bool> visited(1000001);
//int start, donut=0, stick=0, eight=0;
//void travelEight(int n) {
//	for (int i = 0; i < out[n].size(); i++) {
//		if (!visited[out[n][i]]) {
//			visited[out[n][i]] = true;
//			travelEight(out[n][i]);
//		}
//	}
//}
//int travel(int cur) {
//	if (visited[cur]) return cur;
//	visited[cur] = true;
//	if (out[cur].size() == 0) return cur;
//	return travel(out[cur][0]);
//}
//vector<int> solution(vector<vector<int>> edges) {
//    vector<int> answer;
//	int max_n=-1;
//    for (int i = 0; i < edges.size(); i++) {
//		in[edges[i][1]].push_back(edges[i][0]);
//		out[edges[i][0]].push_back(edges[i][1]);
//		max_n = max(max_n, edges[i][0]);
//		max_n = max(max_n, edges[i][1]);
//    }
//	for (int i = 1; i <= max_n; i++) {
//		if (in[i].size() == 0 && out[i].size() > 1) start = i;
//		if (in[i].size() >= 2 && out[i].size() == 2) {
//			eight++;
//			visited[i] = true;
//			travelEight(i);
//		}
//	}
//	for (int i = 0; i < out[start].size(); i++) {
//		if (visited[out[start][i]]) continue;
//		int tmp = travel(out[start][i]);
//		if (tmp != out[start][i]) stick++;
//		else {
//			if (out[tmp].size() > 0) donut++;
//			else stick++;
//		}
//	}
//	answer.push_back(start);
//	answer.push_back(donut);
//	answer.push_back(stick);
//	answer.push_back(eight);
//    return answer;
//}