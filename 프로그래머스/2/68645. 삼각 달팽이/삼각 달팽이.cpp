#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v(n,vector<int>(n));
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,-1}};
    int cy=-1, cx=0, flag=0, num=1;
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cy+=dir[flag].first;
            cx+=dir[flag].second;
            v[cy][cx] = num++;
        }
        ++flag %= 3;
    }
    for(int i=0;i<n;i++){
        for(int j=0; j<i+1;j++) answer.push_back(v[i][j]);
    }
    return answer;
}