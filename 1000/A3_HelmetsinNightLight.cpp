
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        long long p;
        cin>>p;

        vector<long long> a(n);
        vector<long long> b(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        map<long long, long long> mp;
        for(int i=0;i<n;i++)
        {
            mp[b[i]] += a[i];
        }

        long long ans = p;
        int peopleLeft = n-1;

        for(auto it: mp)
        {
            if(it.first > p)
            {
                break;
            }
            if(it.second < peopleLeft)
            {
                ans += it.first*it.second;
                peopleLeft -= it.second;
            }
            else{
                ans += it.first*peopleLeft;
                peopleLeft = 0;
                break;
            }
        }

        if(peopleLeft > 0)
        {
            ans += peopleLeft*p;
        }

        cout<<ans<<endl;



    }
}