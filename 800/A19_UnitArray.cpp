
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

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[v[i]]++;
        }

          int res = 0;

        while((mp[1] - mp[-1]) < 0)
        {
            mp[1]++;
            mp[-1]--;
            res++;
        }

        if(mp[-1]%2 != 0)
        {
            mp[-1]--;
            mp[1]++;
            res++;
        }

        cout<<res<<endl;
    }
}