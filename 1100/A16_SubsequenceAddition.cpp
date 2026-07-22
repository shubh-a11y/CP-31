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

        sort(a.begin(),a.end());

        if(a[0] != 1)
        {
            cout<<"NO"<<endl;
            continue;
        }

        vector<long long> prefix_sum(n);
        prefix_sum[0] = a[0];   
        for(int i=1;i<n;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + a[i];
        }
        
        bool flag = true;
        for(int i=1;i<n;i++)
        {
        
            if(prefix_sum[i-1] < a[i]) 
            {
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout<<"YES"<<endl;
        }
    }
}