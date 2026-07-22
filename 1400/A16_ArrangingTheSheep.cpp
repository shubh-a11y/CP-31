
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

        string s;
        cin>>s;

        vector<int> pos;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '*')
            {
                pos.push_back(i);
            }
        }

        int sz = pos.size();

        if(sz == 0)
        {
            cout<<0<<endl;
            continue;
        }

        long long med = sz/2;

        int idxMed = pos[med];
        long long ans = 0;

        for(int i=med+1;i<sz;i++)
        {
            ans += pos[i]-idxMed-(i-med);
        }

        for(int i=med-1;i>=0;i--)
        {
            ans += idxMed-pos[i]-(med-i);
        }

        cout<<ans<<endl;
    }
}