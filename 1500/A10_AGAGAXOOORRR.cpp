
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<long long> prefix_XOR(n, 0);
        prefix_XOR[0] = a[0];

        for (int i = 1; i < n; i++)
        {
            prefix_XOR[i] = prefix_XOR[i - 1] ^ a[i];
        }

        long long flag = false;

        if (prefix_XOR[n - 1] == 0)
        {
            flag = true;
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            int blocks = 0;
            long long target = prefix_XOR[n - 1];
            int prev = -1;
            for (int i = 0; i < n; i++)
            {
                long long curr = prefix_XOR[i];
                if (prev != -1)
                {
                    curr = curr ^ prefix_XOR[prev];
                }
                if (curr == target)
                {
                    blocks++;
                    prev = i;
                }
            }
            if (blocks >= 3)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}
