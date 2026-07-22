
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
        vector<long long> b(n);
        unordered_map<long long,long long> mp;

        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
            b[i] = i+1;
        }

        bool flag = false;

        if(mp[a[n-1]] == 1)
        {
            flag = true;
        }

        for(int i=0;i<n-1;i++)
        {
            if(mp[a[i]] == 1)
            {
                flag = true;
                break;
            }
            else{
                if(a[i] == a[i+1])
                {
                    swap(b[i],b[i+1]);
                }
            }
        }

        if(flag)
        {
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<n;i++)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;


    }
}

}