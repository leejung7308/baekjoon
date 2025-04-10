#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer(n*(n+1)/2);
    int index=0, skip=0, flag=0, num=1;
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            switch(flag){
                case 0:
                    index+=skip++;
                    answer[index]=num++;
                    break;
                case 1:
                    answer[++index]=num++;
                    break;
                case 2:
                    index-=skip--;
                    answer[index]=num++;
                    break;
            }
        }
        ++flag %= 3;
    }
    return answer;
}