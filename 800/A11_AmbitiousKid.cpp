
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> v(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    int res = INT_MAX;

    for(int i=0;i<n;i++)
    {
        res = min(res,abs(v[i]));
    }

    cout<<res<<endl;

    
}