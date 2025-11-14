#include <iostream>
using namespace std;

int main()
{
    int x = 0, repeat = 0, input = 0;
    cin >> repeat;
    for (int i = 0; i < repeat; i++)
    {
        cin >> input;
        x ^= input;
    }

    if (x == 0) cout << "cubelover";
    else cout << "koosaga";
}