//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//
///*
// * Complete the 'programmerStrings' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts STRING s as parameter.
// */
//
//int programmerStrings(string s) {
//    int answer = 0;
//	string ss = "programmer";
//	string es = "programmer";
//
//    int sidx = 0, eidx = s.size() - 1;
//	while (true) {
//		int idx = ss.find(s[sidx]);
//		if(idx != -1) ss.erase(idx,1);
//		idx = es.find(s[eidx]);
//		if(idx != -1) es.erase(idx,1);
//		if (ss.size() != 0) sidx++;
//		if (es.size() != 0) eidx--;
//		if (ss.size()==0 && es.size()==0) break;
//	}
//	answer = eidx - sidx - 1;
//	if (answer < 0) answer = 0;
//	return answer;
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string s;
//    getline(cin, s);
//
//    int result = programmerStrings(s);
//
//    fout << result << "\n";
//
//    fout.close();
//
//    return 0;
//}
