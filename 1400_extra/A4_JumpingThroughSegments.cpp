
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<pair<long long,long long>>& v, long long mid)
{
    long long curr_l = 0;
    long long curr_r = 0;

    for(int i=0;i<v.size();i++)
    {
        long long l = v[i].first;
        long long r = v[i].second;

        if((l > curr_r+mid) || (r < curr_l-mid))
        {
            return false;
        }
        else
        {
            curr_l = max(l,curr_l-mid);
            curr_r = min(r,curr_r+mid);
        }


    }

    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<pair<long long,long long>> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
        }

        long long l = 0;
        long long r = 1e9;
        long long res = -1;

        while(l <= r)
        {
            long long mid = l + (r-l)/2;

            if(isPossible(v,mid))
            {
                res = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        cout<<res<<endl;
    }
}