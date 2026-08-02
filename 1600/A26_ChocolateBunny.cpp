
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<long long> a(n+1,0);
    int prev = 1;
    for(int i=2;i<=n;i++)
    {
        cout<<"? "<<prev<<" "<<i<<endl;
        int k1;
        cin>>k1;
        
        cout<<"? "<<i<<" "<<prev<<endl;
        int k2;
        cin>>k2;

        if(k1 > k2)
        {
            a[prev] = k1;
            prev = i;
        }
        else
        {
            a[i] = k2;
        }
    }

    a[prev] = n;

    cout<<"! ";
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}