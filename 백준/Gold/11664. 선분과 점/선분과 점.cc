#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

struct pos {
    double x;
    double y;
    double z;
};

double distance(const pos& a, const pos& b) {
    double x = pow(b.x - a.x, 2);
    double y = pow(b.y - a.y, 2);
    double z = pow(b.z - a.z, 2);
    return sqrt(x + y + z);
}

double dotProduct(const pos& a, const pos& b, const pos& c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y) + (b.z - a.z) * (c.z - a.z);
}

int main() {
    FAST_IO;
    cout << fixed;
    cout.precision(10);
    
    // 입력을 한 줄에 9개의 정수로 받음
    pos a, b, c;
    cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> c.x >> c.y >> c.z;
    
    double ab_length = distance(a, b); // 선분 AB의 길이
    
    // 선분 AB의 길이가 0인 경우 (A와 B가 같은 점)
    if (ab_length < 1e-9) {
        cout << distance(a, c);
        return 0;
    }
    
    // 벡터 AB와 벡터 AC의 내적
    double dot_ac_ab = dotProduct(a, b, c);
    
    // 투영점이 선분 AB 밖에 있는 경우 (A 쪽)
    if (dot_ac_ab <= 0) {
        cout << distance(a, c);
        return 0;
    }
    
    // 투영점이 선분 AB 밖에 있는 경우 (B 쪽)
    double dot_ab_ab = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z);
    if (dot_ac_ab >= dot_ab_ab) {
        cout << distance(b, c);
        return 0;
    }
    
    // 투영점이 선분 AB 위에 있는 경우 - 수직 거리 계산
    double t = dot_ac_ab / dot_ab_ab;
    pos projection = {a.x + t * (b.x - a.x), a.y + t * (b.y - a.y), a.z + t * (b.z - a.z)};
    
    cout << distance(c, projection);
    
    return 0;
}