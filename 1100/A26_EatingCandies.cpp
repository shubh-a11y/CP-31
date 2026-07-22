
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> prefix(n), suffix(n);
        prefix[0] = a[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + a[i];
        }

        suffix[n-1] = a[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1] + a[i];
        }

        int left = 0;
        int right = n-1;

        int ans = 0;
        while(left < right)
        {
            if(prefix[left] == suffix[right])
            {
                ans = left+1 + n-right;
                left++;
                right--;
            }
            else if(prefix[left] < suffix[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        cout<<ans<<endl;
    }
}