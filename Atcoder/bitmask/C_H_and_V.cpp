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

    int H, W, K;
    cin >> H >> W >> K;

    vector<string> grid(H);
    for (int i = 0; i < H; i++)
    {
        cin >> grid[i];
    }

    int ans = 0;

    // maskR = row selection
    for (int maskR = 0; maskR < (1 << H); maskR++)
    {
        // maskC = column selection
        for (int maskC = 0; maskC < (1 << W); maskC++)
        {

            int black = 0;

            for (int i = 0; i < H; i++)
            {
                if ((maskR >> i) & 1)
                    continue;
                for (int j = 0; j < W; j++)
                {

                    // যদি row বা column paint করা হয় → skip

                    if ((maskC >> j) & 1)
                        continue;

                    // painted না হলে যদি কালো হয় → count
                    if (grid[i][j] == '#')
                    {
                        black++;
                    }
                }
            }

            if (black == K)
            {
                ans++;
            }
        }
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

    solve();

    return 0;
}
