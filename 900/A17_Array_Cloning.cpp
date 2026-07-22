
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
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }

        int freq = 1;
        for(auto it:mp)
        {
            freq = max(freq,it.second);
        }

        int curr = n-freq;
        int add = 0;
        int currf = freq;
        while(curr > 0)
        {
            curr -= currf;
            currf *= 2;
            add++;
        }

        cout<<n-freq+add<<endl;
    }
}

