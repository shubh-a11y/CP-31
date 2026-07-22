
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

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> left_sum(n);
        left_sum[0] = a[0];
        for(int i=1;i<n;i++)
        {
            left_sum[i] = left_sum[i-1] + a[i];
        }

        long long ans = 0;
     

        for(int k=1;k<=n;k++)
        {
            if(n%k != 0)
            {
                continue;
            }
               vector<long long> diffs;
            int curr = k-1;
            diffs.push_back(abs(left_sum[curr]));
            curr += k;

            while(curr < n)
            {
                diffs.push_back(abs(left_sum[curr]-left_sum[curr-k])); 
                curr += k;   
            }
            long long mini = diffs[0];
            long long maxi = diffs[0];

            for(int i=1;i<diffs.size();i++)
            {
                mini = min(mini,diffs[i]);
                maxi = max(maxi,diffs[i]);
            }

            ans = max(ans,maxi-mini);

        }


        cout<<ans<<endl;
    }
}