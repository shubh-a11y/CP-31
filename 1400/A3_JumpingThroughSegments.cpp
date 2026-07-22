
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<pair<int,int>>& segments, int mid, int curr_l, int curr_r)
{
    int n = segments.size();
    for(int i=0;i<n;i++)
    {
        int l = segments[i].first;
        int r = segments[i].second;

        if(l > curr_r+mid || r < curr_l-mid)
        {
            return false;
        }

        curr_l = max(l,curr_l-mid);
        curr_r = min(r,curr_r+mid);
    }

    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> segments;

        for(int i=0;i<n;i++)
        {
            int l,r;
            cin>>l>>r;
            segments.push_back({l,r});
        }

        
        int l = 0;
        int r = 1e9+5;

        int curr_l = 0;
        int curr_r = 0;
        
        int res = 0;
        while(l <= r)
        {
            int mid = l+(r-l)/2;

            if(isPossible(segments,mid,curr_l,curr_r))
            {
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        cout<<res<<endl;
    }
}