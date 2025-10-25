#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[1] < b[1]) return true;
    if(a[1] == b[1]) return a[0] < b[0];
    return false;
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    for(int i = 0; i < targets.size(); i++){
        answer++;
        int cs = targets[i][0], ce = targets[i][1];
        while(i < targets.size() - 1) {
            if(targets[i + 1][0] < ce) i++;
            else break;
        }
    }
    return answer;
}