#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> lights;
    multiset<int> gaps;

    // initial lights
    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        // right light
        auto it = lights.upper_bound(p);
        int right = *it;
        it--;
        int left = *it;

        // old gap remove
        gaps.erase(gaps.find(right - left));

        // new gaps add
        gaps.insert(p - left);
        gaps.insert(right - p);

        // insert new light
        lights.insert(p);

        // print max gap
        cout << *gaps.rbegin() << " ";
    }

    return 0;
}
