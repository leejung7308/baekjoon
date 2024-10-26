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
// * Complete the 'minDeletions' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts INTEGER_ARRAY arr as parameter.
// */
//int getLIS(vector<int> arr) {
//    vector<int> lis;
//    for (int i : arr) {
//		auto it = lower_bound(lis.begin(), lis.end(), i);
//		if (it == lis.end()) lis.push_back(i);
//		else *it = i;
//    }
//	return lis.size();
//}
//
//int minDeletions(vector<int> arr) {
//	int len = getLIS(arr);
//	if(arr.size() - len - 1 < 0) return 0;
//	return arr.size() - len - 1;
//}
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string arr_count_temp;
//    getline(cin, arr_count_temp);
//
//    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));
//
//    vector<int> arr(arr_count);
//
//    for (int i = 0; i < arr_count; i++) {
//        string arr_item_temp;
//        getline(cin, arr_item_temp);
//
//        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));
//
//        arr[i] = arr_item;
//    }
//
//    int result = minDeletions(arr);
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
