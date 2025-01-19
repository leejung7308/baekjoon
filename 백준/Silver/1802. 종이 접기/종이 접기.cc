#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
string input;
bool dnc(int mid, int size){
    if(size==0) return true;
    if(dnc(mid-(size/2+1), size/2) == false) return false;
    if(dnc(mid+(size/2+1), size/2) == false) return false;
    bool flag = true;
    for(int i=1;i<=size;i++){
        if(input[mid+i]==input[mid-i]){
            flag = false;
            break;
        }
    }
    return flag;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> input;
        if(input.size()==1) {
            cout << "YES\n";
            continue;
        }
        int mid = input.size()/2;
        int size = input.size()/2;
        if(dnc(mid, size)) cout << "YES\n";
        else cout << "NO\n";
    }
}