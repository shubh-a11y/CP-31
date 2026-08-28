
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,t;
    cin>>n>>t;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long s = 0;
    

    long long sum = 0;
    long long res = 0;
    for(int e=0;e<n;e++)
    {
        sum += a[e];

        while(sum > t)
        {
            sum -= a[s];
            s++;
        }

        res = max(res,e-s+1);

    }

    cout<<res<<endl;


}