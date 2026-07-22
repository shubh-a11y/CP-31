
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
        long long OddSum = 0;
        long long EvenSum = 0;
        map<long long,long long> mp;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                EvenSum += a[i];
            }
            else{
                OddSum += a[i];
            }
            mp[EvenSum-OddSum]++;
        }

        if(mp[0] > 0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else{
            bool flag = false;
            for(auto it: mp)
            {
                if(it.second > 1)
                {
                    flag = true;
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
}