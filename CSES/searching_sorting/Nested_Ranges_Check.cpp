#include <bits/stdc++.h>
using namespace std;

struct Range
{
    int x, y, idx;
};

int main()
{
    int n;
    cin >> n;

    vector<Range> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
    }

    sort(a.begin(), a.end(), [](auto &p, auto &q)
         {
        if (p.x == q.x) return p.y > q.y;
        return p.x < q.x; });

    vector<int> contains(n, 0), contained(n, 0);

    // who is contained
    int maxRight = -1;
    for (auto &r : a)
    {
        if (r.y <= maxRight)
            contained[r.idx] = 1;
        maxRight = max(maxRight, r.y);
    }

    // who contains
    int minRight = 1e18;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i].y >= minRight)
            contains[a[i].idx] = 1;
        minRight = min(minRight, a[i].y);
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << "\n";
}
