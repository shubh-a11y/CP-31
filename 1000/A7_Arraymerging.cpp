
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

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<long long> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        unordered_map<long long, long long> mp1, mp2;

        int count = 1;
        for(int i=1;i<n;i++)
        {
            if(a[i] == a[i-1])
            {
                count++;
            }
            else{
                if(count > mp1[a[i-1]])
                {
                    mp1[a[i-1]] = count;
                }
                count = 1;
            }
        }
        if(count > mp1[a[n-1]])
        {
            mp1[a[n-1]] = count;
        }
        count = 1;
        for(int i=1;i<n;i++)
        {
            if(b[i] == b[i-1])
            {
                count++;
            }
            else{
                if(count > mp2[b[i-1]])
                {
                    mp2[b[i-1]] = count;
                }
                count = 1;
            }
        }
        if(count > mp2[b[n-1]])
        {
            mp2[b[n-1]] = count;
            count = 1;
        }

        long long res = 0;

        for(auto it: mp1)
        {
            if(mp1[it.first] + mp2[it.first] > res)
            {
                res = mp1[it.first] + mp2[it.first];
            }
        }

        for(auto it: mp2)
        {
            if(mp1[it.first] + mp2[it.first] > res)
            {
                res = mp1[it.first] + mp2[it.first];
            }
        }

        cout<<res<<endl;
    }
}