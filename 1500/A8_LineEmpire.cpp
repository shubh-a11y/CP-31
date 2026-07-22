
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        long long a,b;
        cin>>a>>b;

        vector<long long> v(n);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        int idx = 0;
        if(a%b == 0)
        {
            idx = n-(a/b);
        }
        else
        {
            idx = n-(a/b)-1;
        }

        // as idx is 1 based, we need to convert it to 0 based index

        idx = idx-1;

        

        vector<long long> suffixSum(n,0);
        suffixSum[n-1] = v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixSum[i] = suffixSum[i+1]+v[i];
        }

        if(idx < 0)
        {
            cout<<b*suffixSum[0]<<endl;
            continue;
        }

        if(idx == n-1)
        {
            cout<<(a+b)*(v[idx])<<endl;
        }
        else
        {
            cout<<(a+b)*v[idx] + b*(suffixSum[idx+1]-(v[idx]*(n-1-idx)))<<endl;
        }

    }
}