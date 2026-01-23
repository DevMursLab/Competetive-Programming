#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define ll long long
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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    set<ll> avail;
    vector<ll> brr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
        avail.insert(i);
        brr.push_back(arr[i].first);
    }
    sort(arr.begin(), arr.end());
    ll cost = 0;
    for (auto &[val, curIndex] : arr)
    {
        if (avail.size() == 1)
            break;

        auto leftIter = avail.lower_bound(curIndex);
        if (leftIter == avail.begin())
            leftIter = avail.end();
        leftIter--;

        auto rightIter = avail.upper_bound(curIndex);
        if (rightIter == avail.end())
            rightIter = avail.begin();

        ll L = *leftIter, R = *rightIter;
        cost += min(brr[L], brr[R]);
        avail.erase(curIndex);
    }
    cout << cost << '\n';
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