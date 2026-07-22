
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

        if(mp.size() == 1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(mp.size() > 2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else{
            vector<int> ele;
            for(auto it:mp)
            {
                ele.push_back(it.first);
            }

            if(n%2 == 0)
            {
                if(mp[ele[0]] == n/2 && mp[ele[1]] == n/2)
                {
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else
            {
                if(abs(mp[ele[0]] - mp[ele[1]]) == 1)
                {
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
        
    }
}