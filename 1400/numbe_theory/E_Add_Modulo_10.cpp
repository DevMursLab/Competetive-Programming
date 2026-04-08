#include <bits/stdc++.h>
using namespace std;

#define int long long
#define gcd __gcd
#define ALL(x) (x).begin(), (x).end()
#define py cout << "Yes\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "No\n";
#define cheakmate return;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + (a[i] % 10);
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, a[i] % 10);
    }

    // important fix
    if (mini == 0)
    {

        pn cheakmate
    }

    for (int i = 0; i < n; i++)
    {
        int x = a[i] % 10;
        if (x % mini != 0)
        {
            pn cheakmate
        }
    }

    py
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}