

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> res;
        for(int i=0;i<n;i++)
        {
            int l = 1;
            int r = i+1;
            while(l<=r)
            {
               int mid = l+(r-l)/2;
               if(a[i-mid+1] >= mid)
               {
                   l = mid+1;
               } 
               else{
                r = mid-1;
               }
            }

            res.push_back(r);
        }
        for(auto x : res)
        {
            cout<<x<<" ";
        }
        cout<<endl;

    }
}