
#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long n,m,k;
    cin>>n>>m>>k;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long ans = n;

    vector<int> diff;

    for(int i=1;i<n;i++)
    {
        diff.push_back(a[i]-a[i-1]-1);
        ans += a[i]-a[i-1]-1;
    }

    sort(diff.begin(),diff.end(),greater<int> ());

    for(int i=0;i<k-1;i++)
    {
        ans -= diff[i];
    }

    cout << ans << endl;

}