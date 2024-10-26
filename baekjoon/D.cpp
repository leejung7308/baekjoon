//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string&);
//string rtrim(const string&);
//vector<string> split(const string&);
//
//
//
///*
// * Complete the 'nodeDistance' function below.
// *
// * The function is expected to return an INTEGER_ARRAY.
// * The function accepts UNWEIGHTED_INTEGER_GRAPH s as parameter.
// */
//
// /*
//  * For the unweighted graph, <name>:
//  *
//  * 1. The number of nodes is <name>_nodes.
//  * 2. The number of edges is <name>_edges.
//  * 3. An edge exists between <name>_from[i] and <name>_to[i].
//  *
//  */
//#define INF 987654321
//void distance(int);
//bool isCycle(int, int);
//vector<vector<int>> edges;
//vector<bool> visited;
//vector<int> parents;
//vector<int> cycle;
//vector<int> mainNodes;
//vector<int> answer;
//vector<int> cnt;
//vector<int> nodeDistance(int s_nodes, vector<int> s_from, vector<int> s_to) {
//	edges = vector<vector<int>>(s_nodes+1);
//	cnt = vector<int>(s_nodes + 1, 0);
//	parents = vector<int>(s_nodes + 1,-1);
//	visited = vector<bool>(s_nodes + 1, false);
//	answer = vector<int>(s_nodes + 1, INF);
//	vector<int> result(s_nodes);
//	for (int i = 0; i < s_from.size(); i++) {
//		edges[s_from[i]].push_back(s_to[i]);
//		edges[s_to[i]].push_back(s_from[i]);
//		cnt[s_from[i]]++;
//		cnt[s_to[i]]++;
//	}
//	for (int i = 1; i <= s_nodes; i++) {
//		if (!visited[i] && isCycle(i, -1)) break;
//	}
//    for (int i = 0; i < mainNodes.size(); i++) {
//		cout << mainNodes[i] << ' ';
//        distance(mainNodes[i]);
//    }
//	cout << '\n';
//	for (int i = 1; i <= s_nodes; i++) {
//		if (find(cycle.begin(), cycle.end(), i) != cycle.end()) result[i - 1] = 0;
//		else result[i - 1] = answer[i];
//	}
//    return result;
//}
//void distance(int start) {
//	priority_queue<pair<int, int>> pq;
//	answer[start] = 0;
//	pq.push({ 0,start });
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int node = pq.top().second;
//		pq.pop();
//		for (int next : edges[node]) {
//			int ncost = cost + 1;
//            if (answer[next] < ncost) {
//				answer[next] = ncost;
//				pq.push({ -ncost,next });
//            }
//		}
//	}
//}
//bool isCycle(int node, int parent) {
//	visited[node] = true;
//	parents[node] = parent;
//    for (int next : edges[node]) {
//		if (next == parent) continue;
//        if (visited[next]) {
//			int current = node;
//			cycle.push_back(current);
//            if (cnt[current] > 2) mainNodes.push_back(current), cout<<"d";
//            while (current != next) {
//				current = parents[current];
//                if (cnt[current] > 2) mainNodes.push_back(current), cout << "d";
//				cycle.push_back(current);
//            }
//            return true;
//        }
//		if (!visited[next] && isCycle(next, node)) return true;
//    }
//	return false;
//}
//
//int main()
//{
//	int s_nodes;
//	cin >> s_nodes;
//	vector<int> s_from(s_nodes);
//	vector<int> s_to(s_nodes);
//	int m;
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> s_from[i];
//	}
//	for (int i = 0; i < m; i++) {
//		cin >> s_to[i];
//	}
//	vector<int> result = nodeDistance(s_nodes, s_from, s_to);
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << '\n';
//	}
//    return 0;
//}
//
//string ltrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        s.begin(),
//        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );
//
//    return s;
//}
//
//string rtrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//        s.end()
//    );
//
//    return s;
//}
//
//vector<string> split(const string& str) {
//    vector<string> tokens;
//
//    string::size_type start = 0;
//    string::size_type end = 0;
//
//    while ((end = str.find(" ", start)) != string::npos) {
//        tokens.push_back(str.substr(start, end - start));
//
//        start = end + 1;
//    }
//
//    tokens.push_back(str.substr(start));
//
//    return tokens;
//}
