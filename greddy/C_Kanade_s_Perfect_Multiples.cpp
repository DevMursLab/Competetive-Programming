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

struct Bitset
{
    int n;
    vector<unsigned long long> b; // 64-bit blocks
    Bitset(int n = 0) { init(n); }
    void init(int n_)
    {
        n = n_;
        b.assign((n + 64) / 64, 0ULL);
    }
    inline void set1(int i)
    { // i >= 0
        b[i >> 6] |= (1ULL << (i & 63));
    }
    inline void set0(int i)
    {
        b[i >> 6] &= ~(1ULL << (i & 63));
    }
    inline bool get(int i) const
    {
        return (b[i >> 6] >> (i & 63)) & 1ULL;
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Bitset present(k + 1), skip(k + 1);

    for (int x : a)
    {
        if (1 <= x && x <= k)
            present.set1((int)x);
    }

    for (int i = 1; i <= k; i++)
    {
        if (!present.get((int)i))
            continue;
        if (skip.get((int)i))
            continue;

        for (int j = i; j <= k; j += i)
        {
            if (!present.get((int)j))
            {
                pm cheakmate
            }
            else
            {
                skip.set1((int)j);
            }
        }

        ans.push_back(i);
        skip.set0((int)i);
    }

    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
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
