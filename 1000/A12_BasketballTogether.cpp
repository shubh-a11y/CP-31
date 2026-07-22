
#include<bits/stdc++.h>
using namespace std;

int main()
{

    long long n;
    cin>>n;

    long long d;
    cin>>d;

    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a.begin(),a.end(),greater<long long>());

    long long ans = 0;
    
    int idx = 0;

    while(n > 0)
    {
        long long div = (d/a[idx]) + 1;

        if(div <= n)
        {
            ans++;
            n -= div;
        }
        else
        {
            break;
        }
        idx++;
    }

    cout<<ans<<endl;
        
}
