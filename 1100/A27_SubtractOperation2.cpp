
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Fast I/O is crucial for large test cases to prevent TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        long long n, k;
        cin>>n>>k;

        vector<long long> a(n);
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        // Sorting takes O(N log N) time and completely avoids hash collisions
        sort(a.begin(), a.end());

        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            // std::binary_search checks if a[i] + k exists in O(log N) time
            if(binary_search(a.begin(), a.end(), a[i] + k))
            {
                flag = true;
                break;
            }
        }

        if(flag)
        {
            cout<<"YES\n"; // Using \n instead of endl is faster
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}