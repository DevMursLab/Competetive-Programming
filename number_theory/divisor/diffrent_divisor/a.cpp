#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int a;
    cin >> s >> a;
    int temp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (!(i & 1))
            temp += (s[i] - '0');
        else
            temp -= (s[i] - '0');
    }
    if (temp % 11 == 0)
        cout << "divisible" << endl;
    else
        cout << "  not divisible" << endl;
}
