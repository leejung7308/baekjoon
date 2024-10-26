//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string&);
//string rtrim(const string&);
//
//
//
///*
// * Complete the 'findMinWeight' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts following parameters:
// *  1. INTEGER_ARRAY weights
// *  2. INTEGER d
// */
//
//int findMinWeight(vector<int> weights, int d) {
//    priority_queue<int> pq;
//	for (int i = 0; i < weights.size(); i++) {
//		pq.push(weights[i]);
//	}
//    int answer = 0;
//	for (int i = 0; i < d; i++) {
//		int w = pq.top();
//		pq.pop();
//		if (w % 2 == 0) {
//			pq.push(w / 2);
//		}
//		else {
//			pq.push(w / 2 + 1);
//		}
//	}
//	while (!pq.empty()) {
//		answer += pq.top();
//		pq.pop();
//	}
//	return answer;
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string weights_count_temp;
//    getline(cin, weights_count_temp);
//
//    int weights_count = stoi(ltrim(rtrim(weights_count_temp)));
//
//    vector<int> weights(weights_count);
//
//    for (int i = 0; i < weights_count; i++) {
//        string weights_item_temp;
//        getline(cin, weights_item_temp);
//
//        int weights_item = stoi(ltrim(rtrim(weights_item_temp)));
//
//        weights[i] = weights_item;
//    }
//
//    string d_temp;
//    getline(cin, d_temp);
//
//    int d = stoi(ltrim(rtrim(d_temp)));
//
//    int result = findMinWeight(weights, d);
//
//    fout << result << "\n";
//
//    fout.close();
//
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
