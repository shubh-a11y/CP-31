
#include <bits/stdc++.h>
using namespace std;

int BS(int l,int r,long long tea,vector<long long> &prefixb)
{
    int res = -1;

    int start = l;
    int end = r; 
    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if((prefixb[mid]-prefixb[l-1]) <= tea)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid-1;

        }
    }

    return res-1;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        
        
        
            long long n;
            cin>>n;

            vector<long long> a(n);
            for(long long i=0;i<n;i++)
            {
                cin>>a[i];
            }
            vector<long long> b(n);
            for(long long i=0;i<n;i++)
            {
                cin>>b[i];
            }

            vector<long long> diffArray(n+1,0);
            vector<long long> rem(n+1,0);

            vector<long long> prefixb(n+1,0);
            for(int i=1;i<=n;i++)
            {
                prefixb[i] = prefixb[i-1] + b[i-1];
            }

            for(int i=0;i<n;i++)
            {
                // 0 indexed
                int l = i;
                int r = n-1;

                int mid = BS(l+1,r+1,a[i],prefixb); // 0 indexed mid

                if(mid < 0)
                {
                    mid = l-1;
                }

                diffArray[l] += 1;
                diffArray[mid+1] -= 1;
                rem[mid+1] += a[i] - (prefixb[mid+1]-prefixb[l]); // 1 based prefixb
                
                

            }

            long long counter = 0;
            vector<long long> ans(n,0);
            for(int i=0;i<n;i++)
            {
                counter += diffArray[i];
                ans[i] += counter * b[i] + rem[i];
            }

            for(int i=0;i<n;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        
    }
}