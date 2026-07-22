
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> a(m, vector<long long>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[j][i];
            }
        }

        for (int i = 0; i < m; i++)
        {
            sort(a[i].begin(), a[i].end());
        }

        long long ans = 0;

        for (int i = 0; i < m; i++)
        {
            long long multiplier = n - 1;
            long long start = 0;
            long long end = n - 1;
            while (start < end)
            {
                ans += (a[i][end] - a[i][start]) * multiplier;
                start++;
                end--;
                multiplier -= 2;
            }
        }

        cout << ans << endl;
    }
}
