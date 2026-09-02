
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

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=1;i<n;i+=2)
        {
            a[i] = -a[i];
        }

        map<long long,long long> mp;
        mp[0] = 1;
        long long sum = 0;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(mp[sum] > 0)
            {
                cout<<"YES"<<endl;
                flag = true;
                break;
            }
            else
            {
                mp[sum]++;
            }
        }

        if(!flag)
        {
            cout<<"NO"<<endl;
        }


    }
}