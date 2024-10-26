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
// * Complete the 'sumVips' function below.
// *
// * The function is expected to return a LONG_INTEGER.
// * The function accepts following parameters:
// *  1. INTEGER_ARRAY score
// *  2. INTEGER guilder_count
// *  3. INTEGER k
// */
//
//void reverseErase(vector<int>& v, int n) {
//    for (int i = v.size()-1; i >= 0; i--) {
//		if (v[i] == n) {
//			v.erase(v.begin() + i);
//			break;
//		}
//	}
//}
//long sumVips(vector<int> score, int guilder_count, int k) {
//	long answer = 0;
//	cout << guilder_count << ' ' << k << '\n';
//    for (int i = 0; i < guilder_count; i++) {
//        vector<int> f, b;
//        int sum;
//        if (k > score.size()) {
//            f = b = score;
//			sort(f.begin(), f.end());
//			sum = f[f.size()-1];
//        }
//        else {
//			for (int j = 0; j < k; j++) {
//				cout << score[j] << ' ' << score[score.size() - 1 - j] << '\n'; // [1,2,3,4,5,6,7,8,9,10
//				f.push_back(score[j]);
//				b.push_back(score[score.size() - 1 - j]);
//			}
//			cout << f.size() << ' ' << b.size() << '\n';
//            sort(f.begin(), f.end());
//            sort(b.begin(), b.end());
//            if (f[f.size() - 1] >= b[b.size() - 1]) {
//				sum = f[f.size() - 1];
//				score.erase(find(score.begin(), score.end(), sum));
//            }
//            else if (f[f.size() - 1] < b[b.size() - 1]) {
//				sum = b[b.size() - 1];
//				reverseErase(score, sum);
//			}
//        }
//		answer += sum;
//        cout << sum << '\n';
//    }
//	return answer;
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string score_count_temp;
//    getline(cin, score_count_temp);
//
//    int score_count = stoi(ltrim(rtrim(score_count_temp)));
//
//    vector<int> score(score_count);
//
//    for (int i = 0; i < score_count; i++) {
//        string score_item_temp;
//        getline(cin, score_item_temp);
//
//        int score_item = stoi(ltrim(rtrim(score_item_temp)));
//
//        score[i] = score_item;
//    }
//
//    string guilder_count_temp;
//    getline(cin, guilder_count_temp);
//
//    int guilder_count = stoi(ltrim(rtrim(guilder_count_temp)));
//
//    string k_temp;
//    getline(cin, k_temp);
//
//    int k = stoi(ltrim(rtrim(k_temp)));
//
//    long result = sumVips(score, guilder_count, k);
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
