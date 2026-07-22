
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    vector<int> arr(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(mp.find(arr[i]) == mp.end())
        {
            mp[arr[i]] = i;
        }
    }

    vector<int> res;

    while(q--)
    {
        int x;
        cin>>x;

        int idx = mp[x];
        res.push_back(idx+1);
        for(auto it:mp)
        {
            if(it.second < idx)
            {
                mp[it.first]++;
            }
        }
        mp[x] = 0;
    }

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }

}