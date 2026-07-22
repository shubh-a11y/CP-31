
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
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        map<long long,long long> mp;
        for(int i=0;i<n;i++)
        {
            int ele = a[i];

            for(int j=2;j<=sqrt(a[i]) && ele>1;j++)
            {
                while(ele%j == 0)
                {
                    mp[j]++;
                    ele = ele/j;
                }
            }
            if(ele != 1)
            {
                mp[ele]++;
            }
        }

        bool flag = true;
        for(auto it:mp)
        {
            if((it.second)%n != 0)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}