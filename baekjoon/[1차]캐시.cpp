//#include <string>
//#include <vector>
//#include <map>
//#include <iostream>
//using namespace std;
//map<string, int> cache;
//void addAge() {
//    for (auto it = cache.begin(); it != cache.end(); it++) {
//        it->second++;
//    }
//}
//string lower(string input) {
//    string output;
//    for (char c : input) {
//        output.push_back(tolower(c));
//    }
//    return output;
//}
//void LRU(string input) {
//    string tmp;
//    int m = -1;
//    for (auto it = cache.begin(); it != cache.end(); it++) {
//        if (it->second > m) {
//            m = it->second;
//            tmp = it->first;
//        }
//    }
//    cache.erase(tmp);
//    cache[input] = 0;
//}
//int solution(int cacheSize, vector<string> cities) {
//    int answer = 0;
//    for (int i = 0; i < cities.size(); i++) {
//        addAge();
//        if (cache.find(lower(cities[i])) == cache.end()) {
//            answer += 5;
//            if (cacheSize == 0) continue;
//            if (cache.size() == cacheSize) LRU(lower(cities[i]));
//            else cache[lower(cities[i])] = 0;
//        }
//        else {
//            answer += 1;
//            cache[lower(cities[i])] = 0;
//        }
//
//    }
//    return answer;
//}