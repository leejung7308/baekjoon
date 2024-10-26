//#include <bits/stdc++.h>
//#include <unordered_map>
//
//using namespace std;
//
//string ltrim(const string&);
//string rtrim(const string&);
//
//
//
///*
// * Complete the 'Moves' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts INTEGER_ARRAY arr as parameter.
// */
//
//int Moves(vector<int> arr) {
//    int maxEven = 0;
//	int maxOdd = 0;
//    int evenLen = 0;
//    int oddLen = 0;
//    bool isEven = false;
//	int oddCnt = 0;
//	int evenCnt = 0;
//	int lastEven = 0;
//	int lastOdd = 0;
//    for (int i = 0; i < arr.size(); i++) {
//        if (arr[i] % 2 == 0) {
//            evenCnt++;
//            lastEven = i;
//        }
//        else {
//            oddCnt++;
//            lastOdd = i;
//        }
//    }
//    if (arr[0] % 2 == 0) {
//		evenLen++;
//        isEven = true;
//    }
//    else {
//		oddLen++;
//		isEven = false;
//    }
//    for (int i = 1; i < arr.size(); i++) {
//        if (arr[i] % 2 == 0 && arr[i - 1] % 2 == 0) {
//			evenLen++;
//        }
//        else if (arr[i] % 2 == 1 && arr[i - 1] % 2 == 1) {
//            oddLen++;
//		}
//        else {
//			if (isEven) {
//				maxEven = max(maxEven, evenLen);
//				evenLen = 1;
//				isEven = false;
//			}
//			else {
//				maxOdd = max(maxOdd, oddLen);
//				oddLen = 1;
//				isEven = true;
//			}
//        }
//    }
//}
//
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
//    int result = Moves(arr);
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
