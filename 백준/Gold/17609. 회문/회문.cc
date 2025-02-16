#include <iostream>
#include <string>
using namespace std;

string s;

int isPalindrome(int left, int right, bool testPseudo) {
  while (left < right) {
    if (s[left] != s[right]) {
      if (testPseudo) {
        if (isPalindrome(left+1, right, false) == 0 || isPalindrome(left, right-1, false) == 0) return 1;
      }
      return 2;
    }
    left++; right--;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while(n--) {
    cin >> s;
    cout << isPalindrome(0, s.length() - 1, true) << '\n';
  }
}