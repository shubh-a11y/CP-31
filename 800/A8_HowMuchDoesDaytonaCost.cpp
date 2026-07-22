

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        int k;

        cin>>n;
        cin>>k;

        vector<int> v(n,0);
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            mp[v[i]]++;
        }


        if(mp[k] == 0)
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }


    }
}