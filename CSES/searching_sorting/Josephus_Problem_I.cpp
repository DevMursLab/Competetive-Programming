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
    int n;
    cin >> n;
    // vector< int> a(n);
    set<int> st;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
    }
    set<int> temp = st, c = st;
    int k1 = 1, k2 = 1;
    while (temp.size() > 1)
    {
        set<int> curr;

        while (!temp.empty())
        {
            if (k1 == 1)
            {
                curr.insert(*temp.begin());
                temp.erase(*temp.begin());
            }
            k1 = 0;
            if (temp.empty())
                continue;
            ans.push_back(*temp.begin());
            temp.erase(*temp.begin());
            k1 = 1;
        }
        temp = curr;
    }
    if (!temp.empty())
        ans.push_back(*temp.begin());
    for (auto it : ans)
        cout << it << " ";
}
// sort(ALL(a),greater<int>());
// int maxi=*max_element(a.begin(),a.end());
//  int maxi = distance(a.begin(), max_element(a.begin(), a.end()));   // return max index

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
