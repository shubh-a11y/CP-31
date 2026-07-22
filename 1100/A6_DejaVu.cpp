
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,x;
        cin>>n>>x;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<long long> q(x);
        for(int i=0;i<x;i++)
        {
            cin>>q[i];
        }

        long long mini_x1 = 31;
        for(int i=0;i<x;i++)
        {
            if(q[i] >= mini_x1)
            {
                continue;
            }

            mini_x1 = q[i];
            long long ele = 1;
            int divs = q[i];
            while(divs--)
            {
                ele *= 2;
            }

            for(int j=0;j<n;j++)
            {
                if(a[j]%ele == 0)
                {
                    a[j] += ele/2;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}