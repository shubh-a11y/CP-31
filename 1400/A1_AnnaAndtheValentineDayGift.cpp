
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        int m;

        cin >> n >> m;
        vector<long long> a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int digits = 0;
        vector<int> zeros_count;

        for (int i = 0; i < n; i++)
        {
            int curr = a[i];
            int zeros = 0;
          
            while (curr % 10 == 0)
            {
                zeros++;
                curr /= 10;
            }

            zeros_count.push_back(zeros);

            while (curr > 0)
            {
                digits++;
                curr /= 10;
            }
        }

        sort(zeros_count.begin(), zeros_count.end(), greater<int>());

        if (digits >= m + 1)
        {
            cout << "Sasha" << endl;
            continue;
        }

        for (int i = 1; i < zeros_count.size(); i += 2)
        {
            digits += zeros_count[i];
        }

        if (digits >= m + 1)
        {
            cout << "Sasha" << endl;
            continue;
        }
        else
        {
            cout << "Anna" << endl;
            continue;
        }
    }
}