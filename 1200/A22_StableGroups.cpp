
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,x;
    cin>>n>>k>>x;

    vector<long long> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long groups = 0;
    vector<long long> diffs;

    for(int i=1;i<n;i++)
    {
        if(a[i]-a[i-1] > x)
        {
            groups++;
            diffs.push_back(a[i]-a[i-1]);
        }
    }
    groups++;

    sort(diffs.begin(),diffs.end());

    int m = diffs.size();
    for(int i=0;i<m;i++)
    {
        if(diffs[i]%x == 0)
        {
            if(diffs[i]/x - 1 <= k)
            {
                k -= (diffs[i]/x - 1);
                groups--;
            }
            else{
                break;
            }
        }
        else{
            if(diffs[i]/x <= k)
            {
                k -= (diffs[i]/x);
                groups--;
            }
            else{
                break;
            }
        }
    }
    cout<<groups<<endl;

}
