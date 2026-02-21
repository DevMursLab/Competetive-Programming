#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#define gcd __gcd

#define ALL(x) (x).begin(), (x).end()
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "NO\n";
#define cheakmate return;
const int N = 1e5 + 5;
#define Mod 1000000009 + 7

void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b = a;
    sort(ALL(b), greater<int>());

    int m_pos = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            m_pos = i;
            break;
        }
    }
    int maxi = INT_MIN, mini = INT_MAX;
    int maxi_p = -1, mini_p = 0;
    for (int i = m_pos; i < n; i++)
    {
        if (a[i] > maxi)
        {
            maxi = a[i];
            maxi_p = i;
        }
        if (a[i] < mini)
        {
            mini = a[i];
            mini_p = i;
        }
    }
    int dif = abs(a[maxi_p] - h);
    int cur = 0, ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur + maxi >= h)
        {
            swap(a[maxi_p], a[i]);
            ok = 1;
            break;
        }
        cur += a[i];
    }
    if (!ok)
        swap(a[mini_p], a[maxi_p]);
    // cout << maxi_p << endl;
    // cout << m_pos << endl;
    // cout << maxi << endl;
    int sum = accumulate(ALL(a), 0LL);

    long long full = (h - 1) / sum;
    long long ans = full * (n + k);

    long long rem = h - full * sum;

    for (int i = 0; i < n; i++)
    {
        rem -= a[i];
        ans++;
        if (rem <= 0)
            break;
    }

    cout << ans << "\n";

    // for (auto it : a)
    //     cout << it << " ";
}

// sort(ALL(a),greater<int>());
// int maxi=*max_element(a.begin(),a.end());
//  int maxi = distance(a.begin(), max_element(a.begin(), a.end()));   // return max index

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*===============================================
  :::::::::::::Author :Md.Mursalin:::::::::::::
  ===============================================*/
