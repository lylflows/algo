#include <iostream>

using namespace std;

int d[100005], a[100005], n, k, ans;

int main()
{
    cin >> n >> k;
    ans = n;
    if (k == 0)
        ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        int l = 0, r = i;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (d[i] - d[m] >= k)
            {
                ans = min(ans, i - m);
                l = m + 1;
            }
            else
                r = m;
        }
    }
    cout << ans;
    return (0);
}