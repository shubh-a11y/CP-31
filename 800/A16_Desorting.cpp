
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

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        if(!is_sorted(v.begin(),v.end()))
        {
            cout<<0<<endl;
            continue;
        }

        int res = v[1]-v[0];

        for(int i=1;i<n;i++)
        {
            res = min(res,v[i]-v[i-1]);
        }

        cout<<(res/2)+1<<endl;
    }
}