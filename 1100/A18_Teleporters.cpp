
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,c;
        cin>>n>>c;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            a[i] = a[i] + i+1;
        }

        sort(a.begin(),a.end());

        long long ans = 0;

        int j = 0;
        while(c >= 0 && j < n)
        {
            c -= a[j];  
            ans++;
            j++;
        }

        if(c >= 0)
        {
            cout<<ans<<endl;
        }
        else{
            cout<<ans-1<<endl;
        } 
    }
}