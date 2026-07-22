
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,c;
        cin>>n>>c;

        vector<long long> a(n);
        long long sum = 0;
        long long sum_sq = 0;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
            sum_sq += (a[i]*a[i]);
        }



        long long high = 1e9;
        long long low = 1;

        while (low <= high)
        {
            long long margin = low + (high - low) / 2;

            // Cast to 128-bit integer for the massive calculation
            __int128_t current_area = (__int128_t)sum_sq +
                                      4 * (__int128_t)n * margin * margin +
                                      4 * (__int128_t)margin * sum;

            if (current_area == c)
            {
                cout << margin << "\n";
                break;
            }
            else if (current_area > c)
            {
                high = margin - 1;
            }
            else
            {
                low = margin + 1;
            }
        }
    }

}