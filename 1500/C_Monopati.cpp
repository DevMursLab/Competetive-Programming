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
    int n;
    cin >> n;
    vector<int> top(n), bottom(n);
    for (int &x : top)
        cin >> x;
    for (int &x : bottom)
        cin >> x;

    vector<int> pref_top(n), pref_bottom(n);
    vector<int> suff_top(n), suff_bottom(n);

    pref_top[0] = top[0];
    pref_bottom[0] = bottom[0];
    for (int i = 1; i < n; i++)
    {
        pref_top[i] = max(pref_top[i - 1], top[i]);
        pref_bottom[i] = min(pref_bottom[i - 1], bottom[i]);
    }

    suff_top[n - 1] = top[n - 1];
    suff_bottom[n - 1] = bottom[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff_top[i] = min(suff_top[i + 1], top[i]);
        suff_bottom[i] = max(suff_bottom[i + 1], bottom[i]);
    }

    int ans = 0;
    for (int split = 0; split < n; split++)
    {
        int required_min = max((split == 0 ? top[0] : pref_top[split]),
                               (split == n - 1 ? bottom[n - 1] : suff_bottom[split + 1]));
        int required_max = min((split == 0 ? bottom[0] : pref_bottom[split]),
                               (split == n - 1 ? top[n - 1] : suff_top[split + 1]));
        if (required_min <= required_max)
        {
            ans += required_max - required_min + 1;
        }
    }

    cout << ans << endl;
    // sort(ALL(a),greater<int>());
    // int maxi=*max_element(a.begin(),a.end());
    //  int maxi = distance(a.begin(), max_element(a.begin(), a.end()));   // return max index
}
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
