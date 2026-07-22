
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long sum = 0;
    for(int i=0;i<k;i++)
    {
        sum += a[i];
    }

    int l = 0;
    long long curr = sum;
    for(int r=k;r<n;r++)
    {
        curr += a[r] - a[l];
        l++;
        sum += curr;
    }

    cout<<fixed<<setprecision(6)<<(double)sum/(n-k+1)<<endl;


}