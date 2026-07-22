
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
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int res;
        bool first = true;
        for(int i=0;i<n;i++)
        {
            if(a[i] != i)
            {
            if(first)
            {
                res = a[i];
                first = false;
            }
            else
            {
                res = res&a[i];
            }
        }
        }

        for(int i=0;i<n;i++)
        {
            if(a[i] != i)
            {
                res = res&a[i];
            }
        }

        cout<<res<<endl;
    }
}