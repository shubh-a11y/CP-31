
#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<long long> contigousA;
    vector<long long> contigousB;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            int count = 1;
            while (((i + 1 < n) && (a[i + 1] == 1)))
            {
                count++;
                i++;
            }
            contigousA.push_back(count);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (b[i] == 1)
        {
            int count = 1;
            while (((i + 1 < m) && (b[i + 1] == 1)))
            {
                count++;
                i++;
            }
            contigousB.push_back(count);
        }
    }

    vector<long long> waysA(n + 1, 0); // Number of ways to have a subsegment of length i in A
    vector<long long> waysB(m + 1, 0); // Number of ways to have a subsegment of length i in B

    for (auto x : contigousA)
    {
        for (int i = 1; i <= x; i++)
        {
            waysA[i] += (x - i + 1);
        }
    }

    for (auto x : contigousB)
    {
        for (int i = 1; i <= x; i++)
        {
            waysB[i] += (x - i + 1);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (k % i != 0)
        {
            continue;
        }

        if (k / i > m)
        {
            continue;
        }
        ans += waysA[i] * waysB[k / i];
    }
    cout << ans << endl;
}
