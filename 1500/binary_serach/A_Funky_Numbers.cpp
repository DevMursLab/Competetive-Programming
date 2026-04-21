#include <bits/stdc++.h>
using namespace std;
#define int long long
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define cheakmate return;

long long triangular(long long k)
{
    return k * (k + 1) / 2;
}
bool cheak(int n)
{
    int low = 1, high = 1e9;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (triangular(mid) > n)
            continue;
        if ()
    }
}
void solve()
{
    int n;
    cin >> n;
    int low = 1, high = 1e9;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (triangular(mid) > n)
            continue;
        if (cheak(n))
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}

/*===============================================
  :::::::::::::Author :Md.Mursalin:::::::::::::
  ===============================================*/
