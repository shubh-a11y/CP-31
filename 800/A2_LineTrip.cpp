
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int x;
        cin>>x;

        vector<int> v(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int res = 0;

        for(int i=1;i<n;i++)
        {
            res = max(res,v[i]-v[i-1]);
        }

        res = max(res,2*(x-v[n-1]));

        res = max(res,(v[0]));

        cout<<res<<endl;
    }
}