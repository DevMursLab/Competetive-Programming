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
struct Cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};
struct Cmp2
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        // return a.first < b.second;
    }
};

void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq, pq2;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp2> pq2;
    for (int i = 0; i < m; i++)
    {
        pq.push({b[i], c[i]});
    }
    int i = 0;
    int ans = 0;
    while (true)
    {
        if (pq.empty())
            break;
        // if (ms.empty())
        //     break;

        if (*ms.rbegin() < pq.top().first)
        {

            pq.pop();
            break;
        }
        if (*ms.rbegin() >= pq.top().first)
        {
            ans++;

            // pq.pop();
            // break;
        }
        // int x = pq.top().first;
        // int y = pq.top().second;
        if (pq.top().second > 0)
        {
            ms.insert(max((*ms.rbegin() - pq.top().first), pq.top().second));
        }
        pq.pop();
    }

    cout << ans << endl;
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
