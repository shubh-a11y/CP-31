
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<long long> dummy = a;

        int len = 0;
        int ans = 0;

        for (int i = n - 1; i > 0; i--)
        {
            if (2 * dummy[i] > dummy[i - 1])
            {
                len++;
                if (len >= k)
                {
                    ans++;
                }
            }
            else
            {
                len = 0;
            }
        }
        cout << ans << endl;
    }
}