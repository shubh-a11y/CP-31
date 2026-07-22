
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long a,b,n;
        cin>>a>>b>>n;

        vector<long long> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        // sort(v.rbegin(),v.rend());

        long long res = 0;
        for(int i=0;i<n;i++)
        {
            res += min(v[i],a-1);
        }

        res += b;

        cout<<res<<endl;

    }


}