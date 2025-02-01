#include <iostream>
using namespace std;
int month[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int leapyear(int);
int days(int, int);
int main() {
    int y1, m1, d1, y2, m2, d2, result;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    //캠프가 1000년 이상일 경우 "gg" 출력
    if ((y2 - y1) == 1000) {
        if (m2 > m1){
            cout << "gg";
            return 0;
        }
        if (m2 == m1) {
            if (d2 >= d1) {
                cout << "gg";
                return 0;
            }
        }
    }
    else if ((y2 - y1) > 1000) {
        cout << "gg";
        return 0;
    }

    //디데이 구하기
    result = (days(y2, m2) + d2) - (days(y1, m1) + d1);
    cout << "D-" << result;
}

//윤년인지 아닌지
int leapyear(int year) {
    int judge = 0;
    if (year % 4 == 0) {
        judge = 1;
        if (year % 100 == 0) judge = 0;
        if (year % 400 == 0) judge = 1;
    }
    return judge;
}

//1년 1월 1일 부터 y년 m-1월 말일까지의 days 구하기
int days(int y, int m) {
    int count = 0;
    for (int i = 1; i <= y; i++) {
        //y년 m-1월 말일까지 구하는 이유: d는 따로 더함
        for (int j = 0; j < (i == y ? m - 1 : 12); j++) {
            count += month[j];
        }
        //윤년은 366일
        if (leapyear(i)) count++;
    }
    //예를 들어 2020년 2월 20일인 경우, 2월 29일이 넘지 않으므로 -1
    if (leapyear(y) == 1 && m < 3) --count;
    return count;
}