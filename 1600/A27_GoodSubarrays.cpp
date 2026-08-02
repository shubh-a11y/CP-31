
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector<long long> a(n+1);
        for(int i=1;i<=n;i++)
        {
            a[i] = s[i-1]-'0';
        }

        unordered_map<long long,long long> mp;
        mp[-1] = 1;
        long long currSum = -1;
        long long res = 0;
        for(int i=1;i<=n;i++)
        {
            currSum += a[i]-1;

            res += mp[currSum];
            mp[currSum]++;

        }

        cout<<res<<endl;


    }
}