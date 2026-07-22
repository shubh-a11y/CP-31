
#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& changes, vector<pair<long long,long long>>& s, long long mid, long long n)
{
    vector<long long> a(n,0);
    for(int i=0;i<=mid;i++)
    {
        a[changes[i]-1] = 1;
    }

    for(int i=1;i<n;i++)
    {
        a[i] += a[i-1];
    }

    for(int i=0;i<s.size();i++)
    {
        long long l = s[i].first-1;
        long long r = s[i].second-1;

        long long sz = r-l+1;
        long long ones = a[r];
        if(l > 0)
        {
            ones -= a[l-1];
        }

        if(ones > sz/2)
        {
            return true;
        }
    }

    return false;

        
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,m;
        cin>>n>>m;

        vector<pair<long long,long long>> s(m);
        for(int i=0;i<m;i++)
        {
            cin>>s[i].first>>s[i].second;
        }

        long long q;
        cin>>q;

        vector<long long> changes(q);
        for(int i=0;i<q;i++)
        {
            cin>>changes[i];
        }

        long long low = 0;
        long long high = q-1;
        long long res = -2;

        while(low <= high)
        {
            long long mid = low + (high-low)/2;

            if(check(changes,s,mid,n))
            {
                res = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        cout<<res+1<<endl;




    }
}